#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    double x[N];
    char u[N][10];

    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        scanf("%s", u[i]);
    }

    double total = 0.0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            total += x[i];
        } else {
            total += x[i] * 380000;
        }
    }

    printf("%.2f\n", total);

    return 0;
}
