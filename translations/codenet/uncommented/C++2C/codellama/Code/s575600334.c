#include <stdio.h>

void binPrint(unsigned x, int bits){
  for (int i=bits-1; i>=0; i--){
    printf("%d", x&(1<<i)?1:0);
  }
  printf("\n");
}
int main(void){
  unsigned a,b;
  scanf("%u %u", &a, &b);

  binPrint(a&b, 32);
  binPrint(a|b, 32);
  binPrint(a^b, 32);
  
  return 0;
}

