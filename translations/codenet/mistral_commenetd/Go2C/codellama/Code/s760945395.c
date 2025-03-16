
#include <stdio.h>

int main() {
  int i;
  int a;

  for (i = 0; i < 5; i++) {
    scanf("%d", &a);
    if (a == 0) {
      printf("%d\n", i + 1);
    }
  }

  return 0;
}

