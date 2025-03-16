#include <stdio.h>
#include <string.h>
 
int main() {
  char s[100];
  scanf("%s", s);
  
  char ans[100] = "No";
  if (strstr(s, "C") < strstr(s, "F")) {
    strcpy(ans, "Yes");
  }
  if (strstr(s, "C") < 0) {
    strcpy(ans, "No");
  }
  
  printf("%s\n", ans);
  return 0;
}
