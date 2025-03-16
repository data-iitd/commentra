#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char W[100000];
  scanf("%s",W);
  
  qsort(W,strlen(W),1,strcmp);

  for (int i = 0; i < strlen(W); i+=2)
  {
    if(W[i]!= W[i+1])
    {
      printf("No\n");
      return 0;
    }
    
  }
  printf("Yes\n");
  


  return 0;
}

