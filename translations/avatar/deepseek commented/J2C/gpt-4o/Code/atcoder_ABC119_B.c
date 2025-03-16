#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double solve(double* x, char** u, int N) {
    double total = 0.0;
    for (int i = 0; i < N; ++i) {
        total += x[i] * (strcmp(u[i], "JPY") == 0 ? 1 : 380000);
    }
    return total;
}

int main() {
    int N;
    scanf("%d", &N); // Read the number of elements N from the user

    double* x = (double*)malloc(N * sizeof(double)); // Allocate memory for the values
    char** u = (char**)malloc(N * sizeof(char*)); // Allocate memory for the currencies

    // Read the values into the arrays x and u
    for (int i = 0; i < N; ++i) {
        u[i] = (char*)malloc(4 * sizeof(char)); // Allocate memory for currency strings
        scanf("%lf %s", &x[i], u[i]);
    }

    // Call the solve method and print the result
    printf("%lf\n", solve(x, u, N));

    // Free allocated memory
    for (int i = 0; i < N; ++i) {
        free(u[i]); // Free each currency string
    }
    free(u); // Free the array of currency strings
    free(x); // Free the array of values

    return 0;
}

// <END-OF-CODE>
