#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the maximum of two integers.
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to read an integer from standard input.
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Main function is the entry point of the program.
int main() {
    // Read the height H, width W, and number of obstacles N from the standard input.
    int H = readInt();
    int W = readInt();
    int N = readInt();
    
    // Calculate the maximum dimension A between H and W.
    int A = max(H, W);
    
    // Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
    printf("%d\n", (N + A - 1) / A);
    
    return 0;
}

// <END-OF-CODE>
