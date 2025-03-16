#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  // Declare a string variable to hold the input
  char W[1001];
  
  // Read input string from the user
  scanf("%s", W);
  
  // Get the length of the string
  int len = strlen(W);
  
  // Sort the characters in the string in ascending order
  qsort(W, len, sizeof(char), (int (*)(const void *, const void *))strcmp);

  // Iterate through the sorted string, checking pairs of characters
  for (int i = 0; i < len; i += 2)
  {
    // Check if the current character is not equal to the next character
    if (W[i] != W[i + 1])
    {
      // If they are not equal, print "No" and exit the program
      printf("No\n");
      return 0;
    }
  }
  
  // If all pairs are equal, print "Yes"
  printf("Yes\n");

  // Return 0 to indicate successful completion of the program
  return 0;
}
