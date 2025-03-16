
#include <stdio.h>
#include <stdlib.h>

double solve(double *x, char **u, int N) {
  double sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += x[i] * (u[i][0] == 'J'? 1 : 380000);
  }
  return sum;
}

int main(int argc, char **argv) {
  int N = atoi(argv[1]);
  double *x = (double *)malloc(sizeof(double) * N);
  char **u = (char **)malloc(sizeof(char *) * N);
  for (int i = 0; i < N; ++i) {
    x[i] = atof(argv[2 * i + 2]);
    u[i] = argv[2 * i + 3];
  }
  printf("%f\n", solve(x, u, N));
  free(x);
  free(u);
  return 0;
}

