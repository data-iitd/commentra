#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char W[1000];
  scanf("%s", W);
  
  int len = strlen(W);
  qsort(W, len, sizeof(char), (int (*)(const void *, const void *))strcmp);

  for (int i = 0; i < len; i+=2)
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
