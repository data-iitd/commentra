#include <stdio.h>

int main(void)
{
  char s[4], t[4];
  scanf("%s", s);
  scanf("%s", t);
  int hit = 0;
  for i in range(0, 3):
    if s[i] == t[i]:
      hit += 1
  print(hit)
  return 0
}

