#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

// Function to read an integer from input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from input
void read_int_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    // Read the number of elements
    int N = read_int();
    
    // Allocate memory for the array of integers
    int *a = (int *)malloc(N * sizeof(int));
    
    // Read the list of integers
    read_int_array(a, N);
    
    // Initialize variables to track the maximum absolute value, its sign, and index
    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Loop through the list to find the maximum absolute value and its properties
    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    // Check the sign of the maximum value and print results accordingly
    if (max_sign == 0) {
        // If the maximum sign is zero, print 0
        printf("0\n");
    } else {
        // If the maximum sign is positive or negative, print the number of operations and the operations
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        if (max_sign == 1) {
            for (int i = 0; i < N - 1; i++) {
                printf("%d %d\n", i + 1, i + 2);
            }
        } else {
            for (int i = N - 1; i > 0; i--) {
                printf("%d %d\n", i + 1, i);
            }
        }
    }

    // Free allocated memory
    free(a);
    
    return 0;
}

// <END-OF-CODE>
