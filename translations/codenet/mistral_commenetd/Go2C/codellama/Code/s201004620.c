
#include <stdio.h>

int main() {
  char S[10];
  scanf("%s", S);
  if (strcmp(S, "Sunny") == 0) {
    printf("Cloudy\n");
  } else if (strcmp(S, "Cloudy") == 0) {
    printf("Rainy\n");
  } else if (strcmp(S, "Rainy") == 0) {
    printf("Sunny\n");
  }
  return 0;
}

