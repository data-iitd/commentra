#include <stdio.h>

int main(void){
  unsigned a,b;
  scanf("%u %u", &a, &b);

  printf("%u\n", a&b);
  printf("%u\n", a|b);
  printf("%u\n", a^b);
  
  return 0;
}
