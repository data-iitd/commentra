#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    // Read the number of currency inputs from the user
    scanf("%d", &N);

    // Create a variable to hold the total sum of converted currency values
    double total_sum = 0.0;

    for (int i = 0; i < N; i++) {
        char currency[20];
        double value;
        // Read the currency input
        scanf("%s", currency);

        // Check if the input is in JPY or BTC and convert accordingly
        if (sscanf(currency, "%lfJPY", &value) == 1) {
            total_sum += value * 1.0; // Convert JPY to float
        } else if (sscanf(currency, "%lfBTC", &value) == 1) {
            total_sum += value * 380000.0; // Convert BTC to float
        }
    }

    // Calculate and print the total sum of the converted currency values
    printf("%lf\n", total_sum);

    return 0;
}

// <END-OF-CODE>
