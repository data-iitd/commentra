#include <stdio.h>
#include <math.h>

// Function to calculate the maximum value in an array
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int value = va_arg(args, int);
        if (value > res) {
            res = value;
        }
    }
    va_end(args);
    return res;
}

// Function to calculate the minimum value in an array
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int value = va_arg(args, int);
        if (value < res) {
            res = value;
        }
    }
    va_end(args);
    return res;
}

// Function to calculate x raised to the power of y
int pow(int x, int y) {
    return (int)pow((double)x, (double)y);
}

// Function to calculate the absolute value of x
int abs(int x) {
    return (x < 0) ? -x : x;
}

// Function to round x down to the nearest integer
int floor(int x) {
    return (int)floor((double)x);
}

// Main function is the entry point of our program
int main() {
    // Declare and initialize variables
    int N, M;
    int ans = 0;

    // Read N and M from the standard input
    scanf("%d %d", &N, &M);

    // Check if N and M are equal to 1
    if (N == 1 && M == 1) {
        // If so, increment the ans variable
        ans += 1;
    } else if (N > 1 && M > 1) {
        // If N and M are greater than 1, calculate the area of the rectangle
        ans += (N - 2) * (M - 2);
    } else {
        // If N or M is equal to 1, calculate the number of points on the edge
        ans += (N * M) - 2;
    }

    // Print the value of ans to the standard output
    printf("%d\n", ans);

    return 0;
}

// Helper type and function for sorting a slice of integers based on their absolute values
// Note: Sorting is not implemented in this translation as it is not used in the main logic

