
#include <stdio.h>  // Including standard input/output library
#include <stdlib.h>  // Including standard library for memory allocation and other functions
#include <math.h>  // Including standard library for mathematical functions
#include <string.h>  // Including standard library for string manipulation functions
#include <stdbool.h>  // Including standard library for boolean data type
#include <time.h>  // Including standard library for time-related functions

// Function to read an integer from input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from input
int* readInts(int n) {
    int* A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        A[i] = readInt();
    }
    return A;
}

// Main function to execute the logic
int main() {
    int n = readInt();  // Reading an integer input for 'n'
    int* A = readInts(n);  // Reading a list of integers
    qsort(A, n, sizeof(int));  // Sorting the list of integers in ascending order
    int ans = 0;  // Initializing the answer variable to accumulate the result
    
    // Looping through the last 2*n elements of the sorted list in reverse order
    for (int i = n - 2; i >= n - 2 * n - 1; i -= 2) {
        ans += A[i];  // Adding the current element to the answer
    }
    
    printf("%d\n", ans);  // Printing the final accumulated answer
    
    free(A);  // Freeing the allocated memory for the list of integers
    
    return 0;  // Returning success status
}

// Entry point of the program
int main() {
    return main();  // Calling the main function to execute the program
}

