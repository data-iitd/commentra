#include <stdio.h>  // Including standard input/output library
#include <stdlib.h> // Including standard library for memory allocation and other utilities

// Function to find the maximum of two long integers
long max(long a, long b) {
    return (a > b) ? a : b;
}

int main() {
    int n;  // Variable to store the number of elements in the array
    scanf("%d", &n);  // Reading the number of elements from input

    long *a = (long *)malloc(n * sizeof(long));  // Dynamically allocating an array of size n to store the elements

    for (int i = 0; i < n; i++) {  // Loop to read the elements of the array from the input
        scanf("%ld", &a[i]);
    }

    long *dp = (long *)malloc((n + 1) * sizeof(long));  // Dynamically allocating an array of size n+1 to store the maximum subarray sum ending at each index
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;  // Initializing all elements of the dp array with -1
    }
    dp[n - 1] = a[n - 1];  // Setting the last element of the dp array with the last element of the array

    for (int i = n - 1; i >= 0; i--) {  // Loop to calculate the maximum subarray sum ending at each index
        dp[i] = max(dp[i + 1], a[i]);
    }

    for (int i = 0; i < n; i++) {  // Loop to print the answer for each test case
        if (a[i] > dp[i + 1]) {  // If the current element is greater than the maximum subarray sum ending at the next index
            printf("0 ");  // Print 0 as the answer
        } else {
            printf("%ld ", (dp[i + 1] - a[i] + 1));  // Else print the length of the subarray ending at the current index
        }
    }

    printf("\n");  // Printing a newline character at the end of the output

    free(a);  // Freeing the dynamically allocated memory for the array
    free(dp);  // Freeing the dynamically allocated memory for the dp array

    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
