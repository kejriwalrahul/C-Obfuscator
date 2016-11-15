#include <stdio.h>

int main() {
  b: printf("%d %o %p\n", 50, 50, 50);	goto a;
  a: return 0;
}
