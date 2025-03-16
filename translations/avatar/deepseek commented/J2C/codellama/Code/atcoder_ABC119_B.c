#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    double *x;
    char **u;

    // Read the number of elements N from the user
    scanf("%d", &N);

    // Initialize the arrays x and u
    x = (double *)malloc(N * sizeof(double));
    u = (char **)malloc(N * sizeof(char *));

    // Read the values into the arrays x and u
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        u[i] = (char *)malloc(sizeof(char) * 4);
        scanf("%s", u[i]);
    }

    // Call the solve method and print the result
    printf("%.2lf\n", solve(x, u, N));

    // Free up the memory allocated for the arrays
    free(x);
    for (int i = 0; i < N; ++i) {
        free(u[i]);
    }
    free(u);

    return 0;
}

// Define the solve method to calculate the total value based on the currency
double solve(double *x, char **u, int N) {
    double total = 0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            total += x[i];
        } else {
            total += x[i] * 380000;
        }
    }
    return total;
}

