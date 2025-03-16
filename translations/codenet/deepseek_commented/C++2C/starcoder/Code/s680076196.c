#include <stdio.h>

int main(){
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  int area = (a - c) * (b - d);

  printf("%d\n", area);
}

