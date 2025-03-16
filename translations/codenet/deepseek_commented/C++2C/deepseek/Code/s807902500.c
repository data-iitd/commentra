#include <stdio.h>
#include <string.h>

int main() {
  char s[1000], t[1000];
  scanf("%s %s", s, t); // Read two strings from standard input

  // Concatenate s with itself to double its length
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    s[len + i] = s[i];
  }
  s[len * 2] = '\0'; // Null-terminate the new string

  // Check if t is a substring of the doubled s
  // If found, strstr returns a pointer to the first occurrence; otherwise, it returns NULL
  // Convert the result to a boolean for easy printing
  puts(strstr(s, t) != NULL ? "Yes" : "No");
}
