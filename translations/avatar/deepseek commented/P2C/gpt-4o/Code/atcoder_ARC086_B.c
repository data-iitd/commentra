#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

// Function to read an integer input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read an array of integers
void read_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    int N = read_int();  // Read the number of elements
    int *a = (int *)malloc(N * sizeof(int));  // Allocate memory for the array
    read_array(a, N);  // Read the list of elements

    int max_val = 0;  // Initialize the maximum value to 0
    int max_sign = 0;  // Initialize the sign of the maximum value to 0
    int max_index = -1;  // Initialize the index of the maximum value to -1

    // Find the element with the maximum absolute value
    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    // If the maximum value is zero, print 0
    if (max_sign == 0) {
        printf("0\n");
    }
    // If the maximum value is positive, print the sequence of operations
    else if (max_sign == 1) {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);  // Print the swap operations
        }
        for (int i = 0; i < N - 1; i++) {
            printf("%d %d\n", i + 1, i + 2);  // Print the increment operations
        }
    }
    // If the maximum value is negative, print the sequence of operations in reverse
    else {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);  // Print the swap operations
        }
        for (int i = N - 2; i >= 0; i--) {
            printf("%d %d\n", i + 2, i + 1);  // Print the decrement operations in reverse
        }
    }

    free(a);  // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
