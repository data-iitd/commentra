#include <stdio.h>
#include <string.h>

int main() {
  // Declare a variable to store the input string
  char s[100];
  
  // Read a string input from the user and store it in `s`
  scanf("%s", s);
  
  // Check if the first three characters of `s` are the same or if the second three characters of `s` are the same
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]){
    // If either condition is true, print "Yes"
    printf("Yes\n");
  } else {
    // Otherwise, print "No"
    printf("No\n");
  }
  
  // End of code
  return 0;
}