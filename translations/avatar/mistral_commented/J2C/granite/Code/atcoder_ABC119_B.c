

#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library for memory allocation and deallocation

double solve(double *x, char **u, int N); // Function declaration for the'solve' function

int main() {
    int N; // Declaring an integer variable 'N' to store the number of elements

    // Reading the number of elements from the user input
    scanf("%d", &N);

    double *x = (double *)malloc(N * sizeof(double)); // Allocating memory for the 'x' array of size 'N'
    char **u = (char **)malloc(N * sizeof(char *)); // Allocating memory for the 'u' array of size 'N'

    // Reading the double values and currency strings from the user input and storing them in respective arrays
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        u[i] = (char *)malloc(4 * sizeof(char)); // Allocating memory for the currency string at index 'i'
        scanf("%s", u[i]);
    }

    // Calling the'solve' function to find the sum of products of double values and their respective currency conversion factors
    printf("%lf\n", solve(x, u, N));

    // Freeing the allocated memory for the 'x' and 'u' arrays
    for (int i = 0; i < N; ++i) {
        free(u[i]); // Freeing the memory allocated for the currency string at index 'i'
    }
    free(x); // Freeing the memory allocated for the 'x' array
    free(u); // Freeing the memory allocated for the 'u' array

    return 0; // Returning 0 to indicate successful execution
}

double solve(double *x, char **u, int N) {
    double sum = 0.0; // Declaring and initializing a variable'sum' to store the sum of products

    // Iterating over the elements of the 'x' and 'u' arrays and calculating the sum of products
    for (int i = 0; i < N; ++i) {
        sum += x[i] * (strcmp(u[i], "JPY") == 0? 1 : 380000); // Comparing the currency string at index 'i' with "JPY" and multiplying the double value at index 'i' with the appropriate conversion factor
    }

    return sum; // Returning the calculated sum
}

