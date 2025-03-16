#include <stdio.h>
#include <string.h>

int main()
{
  // Declare a character array to hold the input string (maximum length 20 + 1 for null terminator)
  char str[21];
  int i, len;
  
  // Read a string from standard input
  scanf("%s", str);
  
  // Calculate the length of the input string
  len = strlen(str);

  // Loop through the string in reverse order
  for(i = len - 1; i >= 0; i--){
    // Output each character of the string in reverse
    putchar(str[i]);
  }
  
  // Print a newline character after the reversed string
  printf("\n");
  
  // Return 0 to indicate successful completion of the program
  return 0;
}
