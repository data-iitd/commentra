#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

// Function to read an integer input
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers as input
void III(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to determine the sign of a number
int my_sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main() {
    int N = I();
    int *a = (int *)malloc(N * sizeof(int));
    III(a, N);

    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Iterate through the list 'a' to find the maximum absolute value and its sign
    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    // Determine the output based on the sign of the maximum value
    if (max_sign == 0) {
        // If the maximum value is zero, print zero
        printf("0\n");
    } else {
        // If the maximum value is positive or negative, print the required output
        printf("%d\n", 2 * N - 1);
        printf("%d %d\n", max_index + 1, 1);
        
        if (max_sign == 1) {
            // Print the indices of the other elements in pairs
            for (int i = 1; i < N; i++) {
                printf("%d %d\n", i + 1, i + 2);
            }
        } else {
            // Print the indices of the other elements in reverse order
            for (int i = N - 1; i > 0; i--) {
                printf("%d %d\n", i + 1, i);
            }
        }
    }

    free(a);
    return 0;
}

// <END-OF-CODE>
