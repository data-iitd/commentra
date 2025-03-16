#include <stdio.h>
#include <string.h>

int main() {
  char s[100]; // Declare a character array to store the input
  
  scanf("%s", s); // Read a string from standard input and store it in s
  
  char ans[] = "No"; // Initialize the answer variable with "No"
  
  // Check if 'C' appears before the last occurrence of 'F' in the string s
  int c_index = -1;
  int f_index = -1;
  int len = strlen(s);
  
  for (int i = 0; i < len; i++) {
    if (s[i] == 'C') {
      c_index = i;
    }
    if (s[i] == 'F') {
      f_index = i;
    }
  }
  
  if (c_index != -1 && f_index != -1 && c_index < f_index) {
    strcpy(ans, "Yes"); // Update ans to "Yes" if the condition is true
  }
  
  // Check if 'C' does not appear in the string s
  if (c_index == -1) {
    strcpy(ans, "No"); // Update ans to "No" if the condition is true
  }
  
  printf("%s\n", ans); // Print the final value of ans
  
  return 0;
}
