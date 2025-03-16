
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  scanf("%d", &N);
  char **S = (char **)malloc(sizeof(char *) * N);
  for (int i = 0; i < N; i++) {
    S[i] = (char *)malloc(sizeof(char) * N);
    scanf("%s", S[i]);
  }

  // Your C code here

  // Print the result
  printf("%d\n", result);

  // Free memory
  for (int i = 0; i < N; i++) {
    free(S[i]);
  }
  free(S);

  return 0;
}
