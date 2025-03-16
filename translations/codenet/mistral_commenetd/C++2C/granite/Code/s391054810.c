

#include <stdio.h>

int main()
{
  int h, w, hh, ww;

  scanf("%d %d %d %d", &h, &w, &hh, &ww);

  int difference_h = h - hh;
  int difference_w = w - ww;

  printf("The area of the rectangle is: %d\n", difference_h * difference_w);

  return 0;
}
