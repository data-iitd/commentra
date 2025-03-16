

#include <stdio.h>

int main() {
  for (int i = 0; i < 5; i++) {
    int a;
    scanf("%d", &a);
    if (a == 0) {
      printf("%d\n", i + 1);
    }
  }
  return 0;
}
