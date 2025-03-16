#include <stdio.h>

int main() {
  // Declare a variable to hold the input string
  char s[100];
  
  // Read input from the user and store it in the variable 's'
  scanf("%s", s);
  
  // Check if the first three characters are the same or the last three characters are the same
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]) {
    // If the condition is true, print "Yes"
    printf("Yes\n");
  } else {
    // If the condition is false, print "No"
    printf("No\n");
  }
  
  return 0;
}
