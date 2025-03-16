#include <stdio.h>
#include <string.h>

int main() {
  char s[1000], t[1000];
  scanf("%s %s", s, t);

  strcat(s, s);

  printf("%s\n", strstr(s, t)? "Yes" : "No");
}

