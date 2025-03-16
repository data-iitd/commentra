#include <stdio.h>
#include <string.h>
 
int main() {
  char s[1000];
  scanf("%s", s);
  
  char ans[1000] = "No";
  if (strstr(s, "C") < strstr(s, "F")) {
    strcpy(ans, "Yes");
  }
  if (strstr(s, "C") == NULL) {
    strcpy(ans, "No");
  }
  
  printf("%s\n", ans);
}

