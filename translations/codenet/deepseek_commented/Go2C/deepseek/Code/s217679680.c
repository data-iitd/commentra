#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* scanArrayInt() {
    int* ret = (int*)malloc(100 * sizeof(int)); // Allocate memory for the array of integers
    char buffer[100]; // Buffer to read the input line
    fgets(buffer, sizeof(buffer), stdin); // Read a line of input
    char* token = strtok(buffer, " "); // Split the input by spaces
    int i = 0; // Initialize the index for the array
    while (token != NULL) { // Loop until there are no more tokens
        ret[i] = atoi(token); // Convert each token to an integer and store it in the array
        token = strtok(NULL, " "); // Get the next token
        i++; // Increment the index
    }
    return ret; // Return the array of integers
}

int main() {
    int* arr = scanArrayInt(); // Call the function to get the input array of integers
    int a = arr[0], b = arr[1]; // Extract the two integers from the input array
    int tap = 0; // Initialize the tap counter
    int consent = 1; // Initialize the consent level
    while (consent < b) { // Loop until consent reaches or exceeds b
        consent = consent + a - 1; // Increment consent by a - 1
        tap++; // Increment the tap counter
    }
    printf("%d\n", tap); // Print the number of taps needed
    free(arr); // Free the allocated memory for the array
    return 0;
}
