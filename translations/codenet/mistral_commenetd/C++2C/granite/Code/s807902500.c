

#include <stdio.h>
// Include the stdio.h library and use the standard namespace.

int main() {
  // Declare two string variables s and t to store user input.
  char s[100], t[100];

  // Read user input and store it in variables s and t respectively.
  scanf("%s%s", s, t);

  // Concatenate the string s with itself and store the result back in s.
  strcat(s, s);

  // Use the printf() function to print the result to the console.
  printf("%s\n", strstr(s, t)?"Yes":"No");
  // Check if the substring t is present in the string s. If it is, print "Yes" to the console. Otherwise, print "No".

  return 0;
}

