#include <stdio.h>
#include <stdlib.h>

int main() {
  char s[100];
  scanf("%s", s);
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]){
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}
