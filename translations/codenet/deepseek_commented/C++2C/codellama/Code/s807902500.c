#include <stdio.h>
#include <string.h>

int main() {
  char s[100], t[100];
  scanf("%s %s", s, t); // Read two strings from standard input

  // Concatenate s with itself to double its length
  strcat(s, s);

  // Check if t is a substring of the doubled s
  // If found, strstr returns the position; otherwise, it returns NULL
  // Convert the result to a boolean for easy printing
  puts((strstr(s, t) != NULL) ? "Yes" : "No");
}

