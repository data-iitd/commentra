#include <stdio.h>
#include <string.h>

int main() {
  char s[100000],t[100000];
  scanf("%s%s",s,t);
  strcat(s,s);
  printf("%s\n",strstr(s,t)?"Yes":"No");
}

