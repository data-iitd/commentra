
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char W[100];
  scanf("%s", W);
  
  qsort(W, strlen(W), sizeof(char), compare);

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

int compare(const void * a, const void * b)
{
  return ( *(char*)a - *(char*)b );
}
