#include <stdio.h>
#include <string.h>

int main() {
  char s[100]; // Declare a string variable to store the input
  
  scanf("%s", s); // Read a string from standard input and store it in s
  
  char ans[100] = "No"; // Initialize the answer variable with "No"
  
  // Check if 'C' appears before the last occurrence of 'F' in the string s
  if (strstr(s, "C") < strstr(s, "F")) {
    strcpy(ans, "Yes"); // Update ans to "Yes" if the condition is true
  }
  
  // Check if 'C' does not appear in the string s
  if (strstr(s, "C") == NULL) {
    strcpy(ans, "No"); // Update ans to "No" if the condition is true
  }
  
  printf("%s\n", ans); // Print the final value of ans
  
  return 0;
}
