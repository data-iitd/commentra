#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    // Ask the user for the number of inputs
    scanf("%d", &N);
    double *x = (double *)malloc(N * sizeof(double)); // Create a list 'x' of size 'N'

    for (int i = 0; i < N; i++) {
        char input[100];
        scanf("%s", input); // Read the input as a string

        // Replace 'JPY' with '* 1.0' and 'BTC' with '* 380000.0'
        double value = 0.0;
        if (strstr(input, "JPY") != NULL) {
            input[strlen(input) - 3] = '\0'; // Remove 'JPY'
            value = atof(input) * 1.0; // Convert to double and multiply by 1.0
        } else if (strstr(input, "BTC") != NULL) {
            input[strlen(input) - 4] = '\0'; // Remove 'BTC'
            value = atof(input) * 380000.0; // Convert to double and multiply by 380000.0
        }
        x[i] = value; // Store the value in the array
    }

    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += x[i]; // Calculate the sum of all elements in the list 'x'
    }

    printf("%f\n", sum); // Print the sum
    free(x); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
