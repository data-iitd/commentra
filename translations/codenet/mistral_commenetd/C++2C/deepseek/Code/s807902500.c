#include <stdio.h>
#include <string.h>

int main() {
  char s[100], t[100];
  scanf("%s %s", s, t);
  strcat(s, s);
  printf("%s\n", strstr(s, t) ? "Yes" : "No");
  return 0;
}
