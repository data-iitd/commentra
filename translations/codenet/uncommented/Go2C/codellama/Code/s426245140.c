#include <stdio.h>

int main() {
  char s[5];
  scanf("%s", s);
  if (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
