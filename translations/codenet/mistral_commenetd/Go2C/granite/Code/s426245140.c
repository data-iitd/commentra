
#include <stdio.h>

int main() {
  char s[4];

  // Use "scanf" to read a string input from the standard input
  scanf("%s", s);

  // Check if the first three characters of the string "s" form an identical sequence
  if ((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3])) {
    // If the condition is true, print "Yes" to the standard output
    printf("Yes\n");
  } else {
    // If the condition is false, print "No" to the standard output
    printf("No\n");
  }

  // End of code
  return 0;
}