#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
  int n,x;
  char s[10];

  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    x = i;
    sprintf(s, "%d", x);

    if(x % 3 == 0 || x % 10 ==3){
      printf(" %d", i);
      continue;
    }
    else{
      int k=strlen(s);

      while(k>0){
        k=k-1;
        int j = pow(10,k);

        if( (x / j) % 10 == 3){
          printf(" %d", i);
          break;
        }
      }
    }
  }
  printf("\n");

  return 0;
}

