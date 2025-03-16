
#include <stdio.h>
#include <math.h>

int main(){
  long long x, y;
  scanf("%lld %lld", &x, &y);
  if(labs(x-y) <= 1) printf("Brown\n");
  else printf("Alice\n");
}


