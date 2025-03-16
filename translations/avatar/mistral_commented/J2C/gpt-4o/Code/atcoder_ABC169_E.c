#include <stdio.h>      // Including standard input-output library
#include <stdlib.h>     // Including standard library for memory allocation and conversions
#include <string.h>     // Including string library for string manipulation
#include <math.h>       // Including math library for mathematical functions

#define MAX_SIZE 100000 // Defining a maximum size for the arrays

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b; // Comparison function for qsort
}

int main() {
    int num = 998244353; // Initializing a variable 'num' with a value
    int n; // Variable to store the number of test cases
    scanf("%d", &n); // Reading the number of test cases from the input

    int ai[MAX_SIZE]; // Array to store the first array elements
    int bi[MAX_SIZE]; // Array to store the second array elements

    for (int i = 0; i < n; i++) { // Iterating through the test cases
        scanf("%d %d", &ai[i], &bi[i]); // Reading the elements into the arrays
    }

    // Sorting the arrays in ascending order
    qsort(ai, n, sizeof(int), compare);
    qsort(bi, n, sizeof(int), compare);

    if (n % 2 == 1) { // Checking if the number of test cases is odd
        printf("%d\n", bi[n / 2] - ai[n / 2] + 1); // Calculating and printing the answer for odd number of test cases
    } else {
        double b = (ai[n / 2] + ai[n / 2 - 1]) / 2.0; // Calculating the average of the middle two elements of the first array
        double c = (bi[n / 2] + bi[n / 2 - 1]) / 2.0; // Calculating the average of the middle two elements of the second array
        printf("%d\n", (int)(2 * (c - b) + 1)); // Calculating and printing the answer for even number of test cases
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
