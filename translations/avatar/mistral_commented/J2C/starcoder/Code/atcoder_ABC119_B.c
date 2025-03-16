
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    double x[N];
    char u[N][5];
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        scanf("%s", u[i]);
    }
    printf("%.2lf\n", solve(x, u, N));
    return 0;
}

double solve(double x[], char u[][5], int N) {
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            sum += x[i] * 1;
        } else {
            sum += x[i] * 380000;
        }
    }
    return sum;
}

