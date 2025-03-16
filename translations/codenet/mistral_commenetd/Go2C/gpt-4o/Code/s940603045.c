#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

// Constants and variables declaration
const int inf = INT_MAX; // Constants for maximum signed integer value

// Function prototypes
int sum(int *a, int size);
int max(int a, int b);
int min(int a, int b);
int abs(int a);

// Main function is the entry point of the program
int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Read input N as a string
    char N[100]; // Assuming N will not exceed 99 characters
    scanf("%s", N);

    // Convert N to an integer
    int n = 0;
    for (int i = 0; i < strlen(N); i++) {
        n += N[i] - '0'; // Convert each digit to an integer and add to the sum
    }

    // Convert N to an integer
    int m = atoi(N);

    // Check if m is divisible by n
    if (n != 0 && m % n == 0) {
        printf("Yes\n"); // Print "Yes" if m is divisible by n
    } else {
        printf("No\n"); // Print "No" if m is not divisible by n
    }

    return 0;
}

// Function to calculate the sum of an array
int sum(int *a, int size) {
    int r = 0;
    for (int i = 0; i < size; i++) {
        r += a[i]; // Calculate the sum of all integers in the given array
    }
    return r;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b; // Return the maximum integer among the given integers
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b; // Return the minimum integer among the given integers
}

// Function to calculate the absolute value of an integer
int abs(int a) {
    return (a < 0) ? -a : a; // Calculate the absolute value of an integer
}

// <END-OF-CODE>
