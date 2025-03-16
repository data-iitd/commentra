#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char W[100];
  scanf("%s",W);
  
  int i;
  for(i=0;i<strlen(W);i++)
  {
    if(W[i] != W[i+1])
    {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  


  return 0;
}
