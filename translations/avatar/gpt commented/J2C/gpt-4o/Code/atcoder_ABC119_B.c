#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CURRENCY_UNITS 100

// Function to solve the currency conversion problem
double solve(double x[], char u[][4], int N) {
    double total = 0.0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            total += x[i]; // JPY to standard currency (1)
        } else {
            total += x[i] * 380000; // Other currencies to JPY (380000)
        }
    }
    return total;
}

int main() {
    // Read the number of currency entries
    int N;
    scanf("%d", &N);

    // Initialize arrays to hold the amounts and their corresponding currency units
    double x[MAX_CURRENCY_UNITS];
    char u[MAX_CURRENCY_UNITS][4]; // Assuming currency unit will not exceed 3 characters + null terminator

    // Loop to read each amount and its currency unit
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]); // Read the amount
        scanf("%s", u[i]);   // Read the currency unit
    }

    // Calculate the total value in a standard currency and print the result
    printf("%.6f\n", solve(x, u, N));

    return 0;
}

// <END-OF-CODE>
