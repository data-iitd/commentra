#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from input
int scanInt() {
    int num;
    scanf("%d", &num); // Read an integer from input
    return num;
}

// Function to read a string from input
char* scanString() {
    char* str = (char*)malloc(100 * sizeof(char)); // Allocate memory for the string
    scanf("%s", str); // Read a string from input
    return str;
}

// Function to read 'n' integers from input and store them in an array
int* scanInts(int n) {
    int* sl = (int*)malloc(n * sizeof(int)); // Allocate memory for the array
    for (int i = 0; i < n; i++) {
        sl[i] = scanInt(); // Read each integer and store it in the array
    }
    return sl; // Return the array of integers
}

// Function to read 'n' strings from input and store them in an array
char** scanStrings(int n) {
    char** sl = (char**)malloc(n * sizeof(char*)); // Allocate memory for the array of strings
    for (int i = 0; i < n; i++) {
        sl[i] = scanString(); // Read each string and store it in the array
    }
    return sl; // Return the array of strings
}

// Main function is the entry point of the program
int main() {
    // Read three integers from input: r, D, and x
    int r = scanInt();
    int D = scanInt();
    int x = scanInt();
    
    // Perform calculations and print the result for 10 iterations
    for (int i = 1; i <= 10; i++) {
        x = r * x - D; // Update x based on the formula
        printf("%d\n", x); // Print the current value of x
    }
    
    return 0;
}
