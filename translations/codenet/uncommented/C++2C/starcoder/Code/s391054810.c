#include <stdio.h>

int main()
{
  int h, w, hh, ww;
  scanf("%d%d%d%d", &h, &w, &hh, &ww);
  printf("%d\n", (h-hh) * (w-ww));
  return 0;
}
