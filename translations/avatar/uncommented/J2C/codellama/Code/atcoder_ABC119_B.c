
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    double *x;
    char **u;
    scanf("%d", &N);
    x = (double *)malloc(N * sizeof(double));
    u = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        u[i] = (char *)malloc(sizeof(char) * 4);
        scanf("%s", u[i]);
    }
    printf("%.2f", solve(x, u));
    for (int i = 0; i < N; ++i) {
        free(u[i]);
    }
    free(u);
    free(x);
    return 0;
}

double solve(double *x, char **u) {
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += x[i] * (strcmp(u[i], "JPY") == 0 ? 1 : 380000);
    }
    return sum;
}

