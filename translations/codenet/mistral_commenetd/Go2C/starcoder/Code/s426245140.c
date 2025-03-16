// Import the "stdio.h" header file for input/output operations
#include <stdio.h>

// Define a main() function
int main(void) {
  // Declare a variable named "s" of type "char" to store user input
  char s[100];

  // Use "scanf" to read a string input from the standard input
  scanf("%s", s);

  // Check if the first three characters of the string "s" form an identical sequence
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]){
    // If the condition is true, print "Yes" to the standard output
    printf("Yes");
  } else {
    // If the condition is false, print "No" to the standard output
    printf("No");
  }

  // Return from the main function
  return 0;
}

// End of code

