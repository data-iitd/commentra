#include <stdio.h>  // Include headers for input/output operations
#include <string.h> // Include headers for string manipulation

int main()
{
  char str[21]; // Declare a character array to store the input string
  int i, len;   // Declare loop counters
  
  scanf("%s", str); // Read a string from the user
  
  len = strlen(str); // Calculate the length of the input string

  // Reverse the string and print it
  for(i = len - 1; i >= 0; i--) {
    putchar(str[i]); // Print each character in reverse order
  }
  printf("\n"); // Print a newline character at the end
  
  return 0; // Return 0 to indicate successful execution
}
