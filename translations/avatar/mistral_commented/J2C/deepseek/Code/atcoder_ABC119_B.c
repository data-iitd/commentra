#include <stdio.h>
#include <stdlib.h>

double solve(double* x, char** u, int N) {
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            sum += x[i];
        } else if (strcmp(u[i], "USD") == 0 || strcmp(u[i], "EUR") == 0) {
            sum += x[i] * 380000;
        }
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);

    double* x = (double*)malloc(N * sizeof(double));
    char** u = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; ++i) {
        u[i] = (char*)malloc(10 * sizeof(char));
    }

    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        scanf("%s", u[i]);
    }

    double result = solve(x, u, N);
    printf("%.2f\n", result);

    free(x);
    for (int i = 0; i < N; ++i) {
        free(u[i]);
    }
    free(u);

    return 0;
}

