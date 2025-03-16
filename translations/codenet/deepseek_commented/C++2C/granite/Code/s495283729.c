
#include <stdio.h>
#include <string.h>
int main(void) {
  char s[1000];
  // Read a string from the user input
  scanf("%s", s);
  int i, flag = 0;
  // Initialize the loop index and a flag to check for invalid characters
  for (i = 0; i < strlen(s); i++) {
    // Loop through each character in the string
    if (i % 2 == 0) {
      // Check if the index is even
      switch (s[i]) {
        // Check if the character is 'R', 'U', or 'D'
        case 'R':
          break;
        case 'U':
          break;
        case 'D':
          break;
        default:
          flag = 1;
          break;
      }
    } else {
      // Check if the index is odd
      switch (s[i]) {
        // Check if the character is 'L', 'U', or 'D'
        case 'L':
          break;
        case 'U':
          break;
        case 'D':
          break;
        default:
          flag = 1;
          break;
      }
    }
  }
  if (flag == 0) {
    // If no invalid characters were found, print "Yes"
    puts("Yes");
  } else {
    // If invalid characters were found, print "No"
    puts("No");
  }
}
