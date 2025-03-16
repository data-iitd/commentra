#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    double x[N], sum = 0;
    char u[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf", &x[i]);
        scanf("%s", u[i]);
    }
    for (int i = 0; i < N; i++) {
        if (strcmp(u[i], "JPY") == 0) {
            sum += x[i];
        } else {
            sum += x[i] * 380000;
        }
    }
    printf("%.2lf\n", sum);
    return 0;
}

