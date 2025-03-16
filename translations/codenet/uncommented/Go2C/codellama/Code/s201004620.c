#include <stdio.h>

int main() {
  char S[10];
  scanf("%s", S);
  switch (S) {
  case "Sunny" : printf("Cloudy\n");
  case "Cloudy" : printf("Rainy\n");
  case "Rainy" : printf("Sunny\n");
       
  }
  return 0;
}