#include <stdio.h>
#include <stdlib.h>

int main(){
  long long x, y;
  scanf("%lld %lld", &x, &y);
  if(abs(x-y) <= 1) printf("Brown\n");
  else printf("Alice\n");
}

