#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    double x[N];
    char currency[10];

    for (int i = 0; i < N; i++) {
        scanf("%s", currency);
        if (strcmp(currency, "JPY") == 0) {
            scanf("%lf", &x[i]);
        } else if (strcmp(currency, "BTC") == 0) {
            double value;
            scanf("%lf", &value);
            x[i] = value * 380000.0;
        }
    }

    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }

    printf("%.10f\n", sum);

    return 0;
}
