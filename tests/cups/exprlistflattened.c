#include <stdio.h>

int main(int argc, char *argv[])
{
	int a=1,b,c=1,d;

	a: d = (c + 1, b=3); goto c;

	c: printf("d = %d\n",d); goto b;
	b: return 0;
}