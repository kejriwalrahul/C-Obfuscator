#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a=1,b,c=1,d;

	d = (c + 1, b=3);

	printf("d = %d\n",d);
	return 0;
}