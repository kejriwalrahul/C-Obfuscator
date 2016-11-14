#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int* arr, int size)
{
	int i;
	for (i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	puts("");
}

void swap(char *a, char *b)
{
	char temp = *a;
	(*a) = *b;
	(*b) = temp;
}

int compare(void *a, void *b)
{
	return ((*((char *)a)) - (*((char*)b)));
}

void permt(char *arr, int len, int index)
{
	int i=0;
	if (index >= len) {
		puts(arr);
		return;
	}
	permt(arr, len, index+1);
	for (i=index+1; i<len; i++) {
		if ((arr[index]) != (arr[i])) {
			swap(arr+index, arr+i);
			permt(arr, len, index+1);
			swap(arr+index, arr+i);
		}
	}
}

int main()
{
	char arr[100];
	scanf("%s", arr);
	qsort(arr, strlen(arr), 1, compare);
	printf("%s\n", arr);
	// permt(arr, strlen(arr), 0);
	return 0;
}