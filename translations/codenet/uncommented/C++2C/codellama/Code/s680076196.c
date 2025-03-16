#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

int main(){
  int a,b,c,d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  printf("%lld\n", (ll)(a-c)*(b-d));
}

