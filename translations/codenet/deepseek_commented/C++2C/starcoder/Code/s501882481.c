#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char S[100];
  scanf("%s", S);
  if (strcmp(S, "Sunny") == 0) {
    printf("Cloudy");
  } else if (strcmp(S, "Cloudy") == 0) {
    printf("Rainy");
  } else {
    printf("Sunny");
  }
  return 0;
}

