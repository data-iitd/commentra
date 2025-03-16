
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library

int main() {
    int N; // Declare the variable N to store the number of elements
    scanf("%d", &N); // Read the number of elements N from the user

    double x[N]; // Declare the array x to store the values
    char u[N][4]; // Declare the array u to store the currencies

    // Read the values into the arrays x and u
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        scanf("%s", u[i]);
    }

    // Calculate the total value based on the currency
    double total = 0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            total += x[i];
        } else {
            total += x[i] * 380000;
        }
    }

    // Print the result
    printf("%.2lf\n", total);

    return 0; // Return 0 to indicate successful execution
}

