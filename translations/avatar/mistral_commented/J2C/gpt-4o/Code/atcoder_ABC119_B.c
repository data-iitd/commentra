#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for memory allocation

double solve(double* x, char** u, int N) {
    double sum = 0.0; // Variable to store the sum of products
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            sum += x[i]; // If currency is JPY, add the value directly
        } else {
            sum += x[i] * 380000; // Otherwise, multiply by the conversion factor
        }
    }
    return sum; // Return the total sum
}

int main() {
    int N; // Variable to store the number of elements
    scanf("%d", &N); // Reading the number of elements from user input

    double* x = (double*)malloc(N * sizeof(double)); // Dynamically allocating memory for double values
    char** u = (char**)malloc(N * sizeof(char*)); // Dynamically allocating memory for currency strings

    // Reading the double values and currency strings from user input
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]); // Reading double value
        u[i] = (char*)malloc(4 * sizeof(char)); // Allocating memory for currency string (assuming max length of 3 + null terminator)
        scanf("%s", u[i]); // Reading currency string
    }

    // Calling the 'solve' function to find the sum of products
    printf("%lf\n", solve(x, u, N));

    // Freeing allocated memory
    for (int i = 0; i < N; ++i) {
        free(u[i]); // Freeing each currency string
    }
    free(u); // Freeing the array of currency strings
    free(x); // Freeing the array of double values

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
