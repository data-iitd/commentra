
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char *read(int len) {
  char *str = (char *)malloc(MAX_LEN * sizeof(char));
  fgets(str, MAX_LEN, stdin);
  return str;
}

int main() {
  int n;
  scanf("%d", &n);

  if (n == 1) {
    printf("Hello World\n");
  } else {
    char *str1 = read(1);
    char *str2 = read(1);
    int num1 = atoi(str1);
    int num2 = atoi(str2);
    printf("%d\n", num1 + num2);
  }

  return 0;
}

