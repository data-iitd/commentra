#include <stdio.h>  // For standard I/O functions
#include <stdlib.h> // For standard library functions
#include <stdbool.h> // For boolean type

// Function to read an integer from standard input
int readInt() {
    int value;
    scanf("%d", &value); // Read an integer from input
    return value; // Return the read integer
}

// Main function
int main() {
    // Read two integers n and k from input
    int n = readInt();
    int k = readInt();
    
    // Check if n is divisible by k
    if (n % k == 0) {
        // If divisible, print 0
        printf("0\n");
    } else {
        // If not divisible, print 1
        printf("1\n");
    }
    
    return 0; // Return success
}

// <END-OF-CODE>
