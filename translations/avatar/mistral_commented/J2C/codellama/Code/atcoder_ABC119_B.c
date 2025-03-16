
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N; // Declaring an integer variable 'N' to store the number of elements

    // Reading the number of elements from the user input
    scanf("%d", &N);

    double *x = (double *)malloc(N * sizeof(double)); // Declaring and initializing an array 'x' of size 'N' to store the double values
    char **u = (char **)malloc(N * sizeof(char *)); // Declaring and initializing an array 'u' of size 'N' to store the currency strings

    // Reading the double values and currency strings from the user input and storing them in respective arrays
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        u[i] = (char *)malloc(10 * sizeof(char));
        scanf("%s", u[i]);
    }

    // Calling the 'solve' function to find the sum of products of double values and their respective currency conversion factors
    printf("%.2lf\n", solve(x, u, N));

    // Freeing up memory allocated to the arrays
    free(x);
    for (int i = 0; i < N; ++i) {
        free(u[i]);
    }
    free(u);

    return 0;
}

double solve(double *x, char **u, int N) {
    double sum = 0; // Declaring a double variable 'sum' to store the sum of products

    // Iterating over the indices of the 'x' array and multiplying the double value at index 'i' with the conversion factor based on the currency string
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            sum += x[i];
        } else {
            sum += x[i] * 380000;
        }
    }

    return sum; // Returning the sum of products
}

