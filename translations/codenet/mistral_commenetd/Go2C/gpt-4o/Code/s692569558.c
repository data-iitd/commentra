#include <stdio.h>  // Include standard input/output library
#include <stdlib.h> // Include standard library for memory allocation and conversion
#include <string.h> // Include string library for string manipulation

int main() {
    // Initialize variables
    char line[1000]; // Buffer to read lines
    int dn[500];     // Array to store integers
    int count = 0;   // Counter for the number of integers
    int sum = 0;     // Variable to store the sum

    // Read the first two lines (we will ignore the first line)
    fgets(line, sizeof(line), stdin);
    fgets(line, sizeof(line), stdin);

    // Split the second line into integers
    char *token = strtok(line, " ");
    while (token != NULL) {
        dn[count++] = atoi(token); // Convert string to integer and store in dn
        token = strtok(NULL, " ");
    }

    // Calculate the sum of products
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            sum += dn[i] * dn[j]; // Add the product of dn[i] and dn[j] to sum
        }
    }

    // Print the result
    printf("%d\n", sum);

    return 0; // End of program
}

// <END-OF-CODE>
