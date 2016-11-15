#include<stdio.h>
#include<string.h>

int main() {
   int num, i, count = 0;
   char str1[10], str2[10];

   printf("\nEnter a number:");
   scanf("%d", &num);

   //Convert Number to String
   sprintf(str1, "%d", num);

   //Copy String into Other
   strcpy(str2, str1);

   //Reverse 2nd Number
   strrev(str2);

   count = strcmp(str1, str2);

   if (count == 0)
      printf("%d is a prime number", num);
   else
      printf("%d is not a prime number", num);

   return 0;
}