#include <stdio.h>
#include <stdlib.h>

// Function to read a line of integers from stdin
int* readInts(int* size) {
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin); // Read a line of input
    int* integers = malloc(10 * sizeof(int)); // Allocate initial space for integers
    *size = 0; // Initialize size
    char* token = strtok(buffer, " "); // Tokenize the input
    while (token != NULL) {
        integers[*size] = atoi(token); // Convert string to integer
        (*size)++; // Increment size
        if (*size % 10 == 0) { // Resize if necessary
            integers = realloc(integers, (*size + 10) * sizeof(int));
        }
        token = strtok(NULL, " "); // Get next token
    }
    return integers; // Return the array of integers
}

<<<<<<< HEAD
// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
=======
// Function to find the maximum of a variable number of integers
int Max(int count, int* integers) {
    int m = integers[0]; // Initialize max with the first integer
    for (int i = 1; i < count; i++) {
        if (m < integers[i]) {
            m = integers[i]; // Update max if a larger integer is found
        }
    }
    return m; // Return the maximum integer
}

// Function to find the minimum of a variable number of integers
int Min(int count, int* integers) {
    int m = integers[0]; // Initialize min with the first integer
    for (int i = 1; i < count; i++) {
        if (m > integers[i]) {
            m = integers[i]; // Update min if a smaller integer is found
        }
    }
    return m; // Return the minimum integer
}

// Function to calculate the power of an integer base raised to an integer exponent
int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        fprintf(stderr, "[argument error]: PowInt does not accept negative integers\n");
        exit(EXIT_FAILURE);
    }
    int result = 1;
    for (int i = 0; i < e; i++) {
        result *= a; // Calculate power
    }
    return result; // Return the result
}

// Function to return the absolute value of an integer
int AbsInt(int a) {
    return (a < 0) ? -a : a; // Return absolute value
}

// Function to delete an element at a specified index from an array
int* DeleteElement(int* s, int* size, int i) {
    if (i < 0 || i >= *size) {
        fprintf(stderr, "[index error]\n");
        exit(EXIT_FAILURE);
    }
    int* newArray = malloc((*size - 1) * sizeof(int)); // Allocate new array
    for (int j = 0, k = 0; j < *size; j++) {
        if (j != i) {
            newArray[k++] = s[j]; // Copy elements except the one to delete
        }
    }
    (*size)--; // Decrease size
    return newArray; // Return new array
>>>>>>> 98c87cb78a (data updated)
}

// Main function where the program execution begins
int main() {
    int size;
    int* tmp = readInts(&size); // Read a line of integers
    int x = tmp[0]; // Store the first integer in variable x
    int i = 1; // Initialize counter
    int sum = 0; // Initialize sum
    while (1) {
        sum += i; // Incrementally add to sum
        if (sum >= x) { // Check if sum has reached or exceeded x
            break; // Exit the loop if condition is met
        }
        i++; // Increment counter
    }
    printf("%d\n", i); // Print the result
    free(tmp); // Free allocated memory
    return 0; // Return success
}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
