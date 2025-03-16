
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    float x[N];
    for (int i = 0; i < N; i++) {
        char currency[4];
        scanf("%s", currency);
        if (strcmp(currency, "JPY") == 0) {
            scanf("%f", &x[i]);
        } else if (strcmp(currency, "BTC") == 0) {
            scanf("%f", &x[i]);
            x[i] *= 380000.0;
        }
    }

    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }

    printf("%f\n", sum);

    return 0;
}
// END-OF-CODE