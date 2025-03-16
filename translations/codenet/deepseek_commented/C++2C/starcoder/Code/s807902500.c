#include <stdio.h>
#include <string.h>

int main() {
  char s[100000], t[100000];
  scanf("%s %s", s, t); // Read two strings from standard input

  // Concatenate s with itself to double its length
  strcat(s, s);

  // Check if t is a substring of the doubled s
  // If found, strstr returns a pointer to the first character of the substring;
  // otherwise, it returns NULL
  // Convert the result to a boolean for easy printing
  printf("%s\n", strstr(s, t)? "Yes" : "No");
}

