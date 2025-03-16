#include <stdio.h>
#include <string.h>

int main() {
  char s[100];
  scanf("%s", s);
  
  char ans[4] = "No";
  int cIndex = -1;
  int fIndex = -1;
  
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == 'C') {
      cIndex = i;
      break;
    }
  }
  
  if (cIndex != -1) {
    for (int i = cIndex + 1; i < strlen(s); i++) {
      if (s[i] == 'F') {
        fIndex = i;
        break;
      }
    }
  }
  
  if (cIndex != -1 && fIndex != -1 && cIndex < fIndex) {
    strcpy(ans, "Yes");
  }
  
  printf("%s\n", ans);
  return 0;
}
