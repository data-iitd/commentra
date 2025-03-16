#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an array of integers from stdin and return the count of integers read
int* scanArrayInt(int* size) {
    // Allocate memory for the array
    int* ret = malloc(2 * sizeof(int));
    *size = 0;

    // Read the input line from stdin
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Split the input line by space
    char* token = strtok(input, " ");
    while (token != NULL) {
        // Convert the string to integer and store it in the array
        ret[*size] = atoi(token);
        (*size)++;
        token = strtok(NULL, " ");
    }

    return ret;
}

// Main function
int main() {
    int size;
    // Read the array of integers from stdin
    int* arr = scanArrayInt(&size);
    
    // Initialize variables a and b with the first two elements of the array
    int a = arr[0], b = arr[1];
    // Initialize variables tap and consent with default values
    int tap = 0, consent = 1;

    // Loop until consent is greater than or equal to b
    while (consent < b) {
        // Increment consent by the sum of a and consent minus one
        consent = consent + a - 1;
        // Increment tap by one for each iteration
        tap++;
    }

    // Print the result, i.e., the number of taps required
    printf("%d\n", tap);

    // Free the allocated memory
    free(arr);
    return 0;
}

// <END-OF-CODE>
