#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);  // Take an integer input N, which represents the number of elements.
    double x[N];

    for (int i = 0; i < N; i++) {
        char currency[10];
        double value;
        scanf("%lf %s", &value, currency);  // Take the value and currency as input

        if (strcmp(currency, "JPY") == 0) {
            x[i] = value * 1.0;  // Replace 'JPY' with '* 1.0'
        } else if (strcmp(currency, "BTC") == 0) {
            x[i] = value * 380000.0;  // Replace 'BTC' with '* 380000.0'
        }
    }

    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];  // Calculate the sum of the elements in the list x.
    }

    printf("%.2f\n", sum);  // Print the sum of the elements in the list x.

    return 0;
}
