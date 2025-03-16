#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Main function starts here
int main() {
    // Initialize a buffer to read input
    char buffer[1000];
    // Read a line of input from stdin
    fgets(buffer, sizeof(buffer), stdin);
    
    // Check if the string starts with the prefix "YAKI"
    if (strncmp(buffer, "YAKI", 4) == 0) {
        // If it does, print "Yes"
        printf("Yes\n");
    } else {
        // Otherwise, print "No"
        printf("No\n");
    }
    
    return 0; // Return success
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to read the next integer from the input
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to read the next array of integers from the input
int* nextIntArray(int* size) {
    int capacity = 10; // Initial capacity for the array
    int* result = malloc(capacity * sizeof(int));
    *size = 0;
    
    while (1) {
        int value;
        if (scanf("%d", &value) != 1) {
            break; // Break on non-integer input
        }
        // Resize the array if necessary
        if (*size >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(int));
        }
<<<<<<< HEAD
        result[(*size)++] = value; // Store the integer
=======
        result[(*size)++] = value; // Add the integer to the array
>>>>>>> 98c87cb78a (data updated)
    }
    
    return result; // Return the array of integers
}
<<<<<<< HEAD
=======

// Function to preprocess the input buffer (not needed in this simple implementation)
void pre() {
    // This function is not necessary in this context
}

// Function to read a line from the input (not needed in this simple implementation)
void readLine() {
    // This function is not necessary in this context
}

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
