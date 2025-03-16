#include <stdio.h> // Include the iostream library for input and output operations

int main() {
  char s[100], t[100]; // Declare two string variables, s and t
  scanf("%s %s", s, t); // Read input strings s and t from the user

  strcat(s, s); // Concatenate string s with itself, effectively doubling it

  // Check if string t can be found within the doubled string s
  // If found, print "Yes", otherwise print "No"
  printf("%s\n", strstr(s, t) ? "Yes" : "No");
}

