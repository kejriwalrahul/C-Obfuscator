#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <wait.h>
#include <limits.h>
#include <errno.h>

#include <readline/readline.h>
#include <readline/history.h>
#include "header.h"

#define max_bg_num 100

// Constant defininng max length of command typed on console
const int size = 512;

// Defining list of inbuilt commands that shell executes (not via child process)
char *builtInCmds[] = {"exit", "pwd", "lsb", "cd"};
int builtInCmdSize = 4;

// Support maximum of 100 bg_processes
int   bg_process[max_bg_num];
char* bg_commands[max_bg_num];
int next_bg = 1;

// Pipe fds
int fd[2];
int fd_in;

// Define characters that delimit words in input 
int iswhspace(char c){
	switch(c){
		case ' ' :
		case '\t':
		case '\r':
		case '\n': return  1;
		case '\0': return -1;

		default: return 0;
	}
}

// Prints error msg
void* error2(char *s){
	printf("Error: %s\n", s);
	return NULL;	
}

// Prints running background process list
void list_bg(){
	int i, status;
	for(i=0;i<max_bg_num; i++)
		if(bg_process[i] != 0)
			if(waitpid(bg_process[i], &status, WNOHANG) == 0)
				printf("Process PID: %d\tCommand: %s\n", bg_process[i], bg_commands[i]);
			else{
				bg_process[i]  = 0;
				free(bg_commands[i]);
				bg_commands[i] = NULL;
			}
}

// Function to check if given command is inbuilt into shell or not
int isBuildCommand(struct command *c){
	// If empty command, do nothing
	if(c->argv[0] == NULL)
		return 0;

	// Compare c's prog with inbuilt commands
	int i = 0;
	for(;i<builtInCmdSize;i++)
		if(!strcmp(c->argv[0], builtInCmds[i]))
			// Return (index+1) in builtInCmds if c's prog is inbuilt command
			return i+1;

	// if not inbuilt return 0
	return 0;
}

// Function to execute inbuilt commands
void executeBuiltInCommand(struct command *c, int index){
	// Buffer to store current working directory for 'pwd'
	char cwd[1024];

	// Execute inbuilt commands
	switch(index){
		case 0: exit(0);
		case 1: printf("%s\n", getcwd(cwd, sizeof(cwd)));
				break;
		case 2: list_bg();
				break;
		case 3: chdir(c->argv[1]);
				break;
	}
}

// Print tokens in command
// Function for debugging only
void printargs2(char **s){
	int i;
	for(i=0; s[i] ;++i)
		printf("%s\n", s[i]);
}

// Print tokens in command
// Function for debugging only
void printargs(char **s, int size){
	int i;
	for(i=0; i < size ;++i)
		printf("%s\n", s[i]);
}

// recycle memory
void free_mem(struct command *c){
	int i;
	for(i=0; c->argv[i] ;++i)
		free(c->argv[i]);
	free(c);
}

// Command parser - tokenizer
struct command* parseCommand(char *s){
	// 'par'  holds head of command linked list, i.e., it contains the first command in list of commands
	struct command *par  = calloc(1, sizeof(struct command)); 
	struct command *curr = par;		// 'curr' refers to current element in linked list of commands
	curr->next = NULL;				// Initialize next with NULL

	int k = 0;		// Index of next free arg

	// Index of next free char in buff
	int b = 0;
	// buff holds current token being built
	char buff[size+1];
	
	int i;
	for(i=0;s[i]!='\0';i++){
		// ignore whitespace
		if(iswhspace(s[i]))			continue;

		// if current command is terminated
		if(s[i] == ';' || s[i] == '|'){
			curr->separator = s[i];			// store separator
			curr->next	= calloc(1, sizeof(struct command));	// init new node in linked list
			curr 		= curr->next;		// move to new node
			k = 0;							// reset args index counter
			curr->next 	= NULL;				// init next element to NUll
			continue;						// move on to next char in input
		}

		// If special character
		if(s[i]=='&' || s[i] =='<' || s[i] =='>'){
			buff[b]   = s[i];
			buff[b+1] = '\0';
			curr->argv[k] = malloc(strlen(buff));
			strcpy(curr->argv[k], buff);
			k++;
			strcpy(buff, "");
			b = 0;
			continue;
		}

		// Accepting quoted tokens
		if(s[i] == '\"'){
			i++;
			while((s[i] != '\"' || s[i-1] == '\\') && s[i] != '\0'){	
				if(s[i] == '\"' && s[i-1] == '\\') b--;
				buff[b++] = s[i++];
			}

			if(s[i] == '\0')	return error2("Incomplete input");
			buff[b] = '\0';							// terminate current token with '\0'
			curr->argv[k] = malloc(strlen(buff)+1);	// allocate memory for string in args element
			strcpy(curr->argv[k], buff);			// copy token string
			k++; 									// increment index counter
			strcpy(buff, "");						// reset buffer
			b = 0;				
			continue;
		}

		// while non-sig char append char to buffer
		while(s[i]!='|' && s[i]!='&' && s[i] !='<' && s[i] !='>' && s[i]!=';' && s[i]!='\"' && !iswhspace(s[i]) && s[i] != '\0'){
			buff[b++] = s[i++];
		}

		buff[b] = '\0';							// terminate current token with '\0'
		curr->argv[k] = malloc(strlen(buff)+1);	// allocate memory for string in args element
		strcpy(curr->argv[k], buff);			// copy token string
		k++; i--;								// increment index counter
		strcpy(buff, "");						// reset buffer
		b = 0;
	}

	// printf("Args:\n");
	// printargs(args, k);

	// returns first element in command linked list
	return par;
}

// Prints prompt on console
char* printPrompt(){
	static char hostname[HOST_NAME_MAX];
	static char username[LOGIN_NAME_MAX];
	static int run = 0;
	char cwd[1024];

	// If function executed first time
	if(!run){
		// Gets computer name
		gethostname(hostname, HOST_NAME_MAX);
		// Gets user name
		getlogin_r(username, LOGIN_NAME_MAX);
		run = 1;
	}
	
	// Deploy prompt:
	static char p[1000];
	strcpy(p,""); 
	strcat(p, username);
	strcat(p,"@");
	strcat(p, hostname);
	strcat(p, ":");
	strcat(p, getcwd(cwd, sizeof(cwd)));
	return strcat(p, "$ ");

	// Test prompt: (to distinguish between real shell and our shell)
	return strcat(getcwd(cwd, sizeof(cwd)),"$");
}

void handleSugar(struct command *cmd){
	int i=0;
	for(i=0; cmd->argv[i] != NULL ;i++){
		if      (!strcmp("<", cmd->argv[i]))	{	cmd->argv[i] = NULL; redirect(IN,  cmd->argv[i+1]);	}
		else if (!strcmp(">", cmd->argv[i]))    {	cmd->argv[i] = NULL; redirect(OUT, cmd->argv[i+1]);	}
		else if (!strcmp("|", cmd->argv[i]))	;
		else if (!strcmp("&", cmd->argv[i]))	{ 	cmd->argv[i] = NULL; redirect(OUT, "out");			}
	}
}

// Actually invoke the child
void executeCommand(struct command *c){
	// If empty command, terminate child
	handleSugar(c);

	if(fd_in != -1){
		if(dup2(fd_in, IN) < 0)    	error("Unable to pipe in input");
	}

	if(fd[1] != -1){
		if(dup2(fd[1], OUT) < 0)    error("Unable to pipe out output");
	}

	if(!strcmp(c->argv[0], ""))
		exit(0);

	// Execute command on child, store return val in case of failure
	int err = execvp(c->argv[0], c->argv);
	// Print error msg corresponding to errno
	if(err == -1){
		printf("%s %s\n", "Failed to execute:", c->argv[0]);
		printf("%s %s\n", "Error:", strerror(errno));
		exit(0);
	}
}

// Check if command is to be executed on background
int isBackgrounfJob(struct command *c){
	// If empty, do nothing
	if(c->argv[0] == NULL)
		return 0;

	// traverse to end of token list
	int i;
	for(i=0;c->argv[i]!=NULL;i++);
	// If last token was '&', then must be background process
	// need to confirm this	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CHECK THIS
	if(!strcmp(c->argv[i-1],"&"))
		return 1;
	
	// Else not background process
	return 0;
}

// Do infinitely
int main(int argc, char **argv){
	
	printf("\nWelcome to Simple Shell!\n\n");
	
	// Disable Tab Completion
	// rl_bind_key ('\t', rl_insert);

	// Initialize fds
	fd[0] = fd[1] = -1;

	while(1){
		int childPid;
		char *cmdLine;
		struct command *cmd;
		int stat;

		char *prompt;
		prompt = printPrompt();			// prints prompt
		
		cmdLine = readline(prompt);		// reads input line
		add_history (cmdLine);			// Stores it in history

		if(cmdLine == NULL)				{ printf("\n"); exit(0);}

		cmd = parseCommand(cmdLine);	// parses given input

		// while commands exists in given ip
		while(cmd){
			int index;
			// If inbuilt command, let shell execute it
			if(index = isBuildCommand(cmd)){
				executeBuiltInCommand(cmd, index-1);
			}
			// If external prog
			else{
				// printargs2(cmd->args);
				// Propagate older pipes
				if(fd_in != IN && fd_in != OUT)
					close(fd_in);

				fd_in = fd[0];
				fd[0] = fd[1] = -1;
				// Establish pipe if command needs it before forking
				if(cmd->separator == '|')
					pipe(fd);

				childPid = fork();			// Fork a child
				if(childPid == 0){			// In child
					executeCommand(cmd);	// Execute program
				}
				else{											// In Parent
					if(isBackgrounfJob(cmd)){					// Check if background process
						bg_process[next_bg-1]  = childPid;		// Record in lsb
						bg_commands[next_bg-1] = malloc(strlen(cmd->argv[0]));
						strcpy(bg_commands[next_bg-1], cmd->argv[0]);
						next_bg++;
					}
					// If not background process, wait for child to terminate
					else{
						if(fd[1]!=-1)
							close(fd[1]);
						waitpid(childPid, &stat, 0);
					}
				}
			}
			struct command *tmp = cmd;
			// Move to next command in command linked list
			cmd = cmd->next;
			free_mem(tmp);
		}
	}
}