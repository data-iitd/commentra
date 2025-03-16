
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
  // Step 1: Include necessary headers
  // The code starts by including necessary headers for input/output operations,
  // string manipulation, and using standard namespace.
  char W[1000];
  scanf("%s",W);
  
  // Step 2: Read input
  // The program reads a string `W` from the standard input.
  
  // Step 3: Sort the string
  // The string `W` is sorted in ascending order.
  qsort(W,strlen(W),sizeof(char),strcmp);

  // Step 4: Check for character pairs
  // The program iterates through the sorted string, checking if each character
  // is followed by its identical pair.
  for (int i = 0; i < strlen(W); i+=2)
  {
    if(W[i]!= W[i+1])
    {
      // If a character is not followed by its pair, output "No" and exit.
      printf("No\n");
      return 0;
    }
    
  }
  
  // Step 5: Output result
  // If all characters are in pairs, the program outputs "Yes"; otherwise,
  // it outputs "No".
  printf("Yes\n");
  
  return 0;
}

