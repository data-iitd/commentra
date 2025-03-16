#include <stdio.h>
#include <string.h>

// Include necessary header files for standard input/output and string manipulation

int main(void) {
  char s[1000]; // Declare a character array 's' of size 1000 to store the input string

  scanf("%s", s); // Read a string from the standard input and store it in the array 's'

  int i, flag = 0; // Initialize variables: 'i' as a loop counter and 'flag' as a boolean flag

  for (i = 0; i < strlen(s); i++) { // Iterate through each character in the string 's'
    if (i % 2 == 0) { // Check if the current index 'i' is even
      switch (s[i]) { // Switch statement to check the character at the even index
        case 'R': // If the character is 'R', do nothing and move to the next character
          break;
        case 'U': // If the character is 'U', do nothing and move to the next character
          break;
        case 'D': // If the character is 'D', do nothing and move to the next character
          break;
        default: // If the character is not 'R', 'U', or 'D', set the flag to 1
          flag = 1;
          break;
      }
    } else { // If the current index 'i' is odd
      switch (s[i]) { // Switch statement to check the character at the odd index
        case 'L': // If the character is 'L', do nothing and move to the next character
          break;
        case 'U': // If the character is 'U', do nothing and move to the next character
          break;
        case 'D': // If the character is 'D', do nothing and move to the next character
          break;
        default: // If the character is not 'L', 'U', or 'D', set the flag to 1
          flag = 1;
          break;
      }
    }
  }

  if (flag == 0) { // If no invalid character was found during the iteration
    puts("Yes"); // Output "Yes" to the standard output
  } else { // If an invalid character was found during the iteration
    puts("No"); // Output "No" to the standard output
  }
}
