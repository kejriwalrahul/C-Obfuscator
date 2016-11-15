#include <stdio.h>

int main(){
	int i = 1;
	int num;
	switch(i){
		case 0:	num = 1; printf("%d\n", num); break;
		case 1: num = 2; printf("%d\n", num); break;
		default: num = 3; printf("%d\n", num); break;
	}
	return 0;
}