
#include <stdio.h>

int main() {
  char s[100],t[100];
  scanf("%s%s",s,t);
  strcat(s,s);
  puts(strstr(s,t)?"Yes":"No");
}
