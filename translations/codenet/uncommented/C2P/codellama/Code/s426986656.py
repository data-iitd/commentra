#include <stdio.h>

int main(void) {
  int A, B, flag = 0;
  scanf("%d %d", &A, &B);

  for i in range(1, 4):
    if (A*B*i)%2 == 1:
      flag = 1
      break

  if flag:
    print("Yes")
  else:
    print("No")

  return 0
}

