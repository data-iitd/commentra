
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    // Read the number of currency entries
    int N;
    scanf("%d", &N);

    // Initialize arrays to hold the amounts and their corresponding currency units
    double x[N];
    char u[N][4];

    // Loop to read each amount and its currency unit
    for (int i = 0; i < N; ++i) {
        // Read the amount
        scanf("%lf", &x[i]);
        // Read the currency unit
        scanf("%s", u[i]);
    }

    // Calculate the total value in a standard currency and print the result
    double total = 0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            total += x[i];
        } else {
            total += x[i] * 380000;
        }
    }
    printf("%f\n", total);

    // Close the scanner to prevent resource leaks
    // Return 0 to indicate successful execution
    return 0;
}
