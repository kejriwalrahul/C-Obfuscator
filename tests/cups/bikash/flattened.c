#include <stdio.h>

int main() {
  b: printf("%d %o %p\n", 50, 50, 50);	goto c;
  c: if(50) printf("%s\n", "Helo"); goto d;
  d: if(25) printf("%s\n", "hi"); else printf("%s\n", "bye"); goto a;
  a: return 0;
}
