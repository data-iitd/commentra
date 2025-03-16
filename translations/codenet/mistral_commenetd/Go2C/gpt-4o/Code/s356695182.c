#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read an integer from standard input
int nextInt() {
    int t;
    scanf("%d", &t); // Read an integer from standard input
    return t; // Return the integer
}

// Function to read multiple integers from standard input
void scanNums(int len, int *nums) {
    // Read each number from standard input and store it in the array
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]); // Read a number from standard input
    }
}

// Function to calculate the first pattern
int pattern1(int *l) {
    // Calculate the value of n using the given formula
    int n = (l[0] * l[3]) + (l[1] * l[4]);
    return n; // Return the value of n
}

// Function to calculate the second pattern
int pattern2(int *l) {
    // Calculate the maximum of l[3] and l[4]
    int maxNum = fmax(l[3], l[4]);
    // Calculate the value of n using the given formula
    int n = 2 * l[2] * maxNum;
    return n; // Return the value of n
}

// Function to calculate the third pattern
int pattern3(int *l) {
    // Calculate the minimum of l[3] and l[4]
    int minNum = fmin(l[3], l[4]);
    // Calculate the value of n using the given formula
    int n = 2 * l[2] * minNum + doch(l);
    return n; // Return the value of n
}

// Function to find the minimum of a list of numbers
int min(int a, int b, int c) {
    // Return the minimum value among a, b, and c
    return fmin(fmin(a, b), c);
}

// Helper function to calculate the difference between the larger and smaller of two numbers
int doch(int *l) {
    // If l[3] is greater than l[4], return the product of l[0] and the difference between l[3] and l[4]
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        // Otherwise, return the product of l[1] and the difference between l[4] and l[3]
        return l[1] * (l[4] - l[3]);
    }
}

// Main function to read input and call the pattern functions
int main() {
    // Read the length of the input list
    int len = 5;
    int l[5]; // Array to store the input list

    // Read the input list from standard input
    scanNums(len, l);

    // Calculate and print the minimum of the three patterns
    printf("%d\n", min(pattern1(l), pattern2(l), pattern3(l)));

    return 0; // Return success
}

// <END-OF-CODE>
