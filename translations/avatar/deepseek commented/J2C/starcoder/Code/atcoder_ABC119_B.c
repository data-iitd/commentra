#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    double x[N];
    char u[N][3];
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        scanf("%s", u[i]);
    }
    printf("%.2lf", solve(x, u, N));
    return 0;
}

double solve(double x[], char u[][3], int N) {
    return 0;
}

