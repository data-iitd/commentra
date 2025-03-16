#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char S[100];
  scanf("%s", S);
  if (strcmp(S, "Sunny") == 0) {
    printf("Cloudy\n");
  } else if (strcmp(S, "Cloudy") == 0) {
    printf("Rainy\n");
  } else {
    printf("Sunny\n");
  }
  return 0;
}

