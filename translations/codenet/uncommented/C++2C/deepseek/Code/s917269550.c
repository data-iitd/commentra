#include <stdio.h>
#include <math.h>

int main(){
  long long x, y;
  scanf("%lld %lld", &x, &y);
  if(fabs(x-y) <= 1) printf("Brown\n");
  else printf("Alice\n");
}

