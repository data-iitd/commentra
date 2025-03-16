// by syu
#include <stdio.h>  // Include standard I/O library
#include <stdlib.h> // Include standard library for memory allocation and conversions

// Function to read an integer from standard input
int readInt() {
    int value;
    scanf("%d", &value); // Read an integer from input
    return value;        // Return the read integer
}

// Entry point of the program
int main() {
    // Read two integers n and k from standard input
    int n = readInt();
    int k = readInt();
    
    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0 to the console
        printf("0\n");
    } else {
        // If n is not divisible by k, print 1 to the console
        printf("1\n");
    }
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
