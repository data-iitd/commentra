#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char W[1000];
  scanf("%s", W);
  
  // Sort the string
  qsort(W, strlen(W), sizeof(char), (int (*)(const void *, const void *))strcmp);

  // Check for character pairs
  for (int i = 0; i < strlen(W); i+=2)
  {
    if(W[i] != W[i+1])
    {
      // If a character is not followed by its pair, output "No" and exit.
      printf("No\n");
      return 0;
    }
  }
  
  // Output result
  printf("Yes\n");
  
  return 0;
}
