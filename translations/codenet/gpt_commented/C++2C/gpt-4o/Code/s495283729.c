#include <stdio.h>
#include <string.h>

int main(void) {
  // Declare a character array to hold the input string
  char s[1000];
  
  // Read a string from standard input
  scanf("%s", s);
  
  // Initialize variables: i for iteration and flag to track validity
  int i, flag = 0;
  
  // Iterate through each character in the string
  for (i = 0; i < strlen(s); i++) {
    // Check if the index is even
    if (i % 2 == 0) {
      // Switch case for characters at even indices
      switch (s[i]) {
        case 'R':
<<<<<<< HEAD
        case 'U':
        case 'D':
          // 'R', 'U', and 'D' are valid, do nothing
=======
          // 'R' is valid, do nothing
          break;
        case 'U':
          // 'U' is valid, do nothing
          break;
        case 'D':
          // 'D' is valid, do nothing
>>>>>>> 98c87cb78a (data updated)
          break;
        default:
          // If character is not valid, set flag to indicate an error
          flag = 1;
          break;
      }
    } else {
      // Switch case for characters at odd indices
      switch (s[i]) {
        case 'L':
<<<<<<< HEAD
        case 'U':
        case 'D':
          // 'L', 'U', and 'D' are valid, do nothing
=======
          // 'L' is valid, do nothing
          break;
        case 'U':
          // 'U' is valid, do nothing
          break;
        case 'D':
          // 'D' is valid, do nothing
>>>>>>> 98c87cb78a (data updated)
          break;
        default:
          // If character is not valid, set flag to indicate an error
          flag = 1;
          break;
      }
    }
  }
  
  // Check the flag to determine if the input string was valid
  if (flag == 0) {
    // If flag is still 0, print "Yes" indicating valid input
    puts("Yes");
  } else {
    // If flag is set, print "No" indicating invalid input
    puts("No");
  }
}

// <END-OF-CODE>
