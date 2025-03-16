#include <stdio.h>
#include <stdlib.h>

double solve(double x[], char *u[], int N) {
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            sum += x[i];
        } else if (strcmp(u[i], "BTC") == 0) {
            sum += x[i] * 380000;
        }
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);
    double x[N];
    char *u[N];
    for (int i = 0; i < N; ++i) {
        u[i] = (char *)malloc(10 * sizeof(char));
        scanf("%lf %s", &x[i], u[i]);
    }
    printf("%.10f\n", solve(x, u, N));
    for (int i = 0; i < N; ++i) {
        free(u[i]);
    }
    return 0;
}
