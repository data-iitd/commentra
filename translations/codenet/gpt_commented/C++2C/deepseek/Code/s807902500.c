#include <stdio.h> // Include the stdio library for input and output operations
#include <string.h> // Include the string library for string manipulation functions

int main() {
  char s[100], t[100]; // Declare two character arrays, s and t, with a maximum size of 100 characters each
  scanf("%s %s", s, t); // Read input strings s and t from the user

  // Concatenate string s with itself, effectively doubling it
  // This is done by copying the original string to a new position in the array
  // and then appending the original string to the end of it
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    s[len + i] = s[i];
  }
  s[len * 2] = '\0'; // Null-terminate the new string

  // Check if string t can be found within the doubled string s
  // If found, print "Yes", otherwise print "No"
  if (strstr(s, t) != NULL) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}
