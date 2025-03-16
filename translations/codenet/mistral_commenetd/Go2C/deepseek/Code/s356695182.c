#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read an integer from standard input
int nextInt() {
    int t;
    scanf("%d", &t);
    return t;
}

// Function to calculate the first pattern
int pattern1(int l[]) {
    // Calculate the value of n using the given formula
    int n = (l[0] * l[3]) + (l[1] * l[4]);

    // Return the value of n
    return n;
}

// Function to calculate the second pattern
int pattern2(int l[]) {
    // Calculate the maximum of l[3] and l[4]
    int maxNum = fmax(l[3], l[4]);

    // Calculate the value of n using the given formula
    int n = 2 * l[2] * maxNum;

    // Return the value of n
    return n;
}

// Function to calculate the third pattern
int pattern3(int l[]) {
    // Calculate the minimum of l[3] and l[4]
    int minNum = fmin(l[3], l[4]);

    // Calculate the value of n using the given formula
    int n = 2 * l[2] * minNum + doch(l);

    // Return the value of n
    return n;
}

// Function to find the minimum of a list of numbers
int min(int nums[], int len) {
    // If the list is empty, panic with an error message
    if (len == 0) {
        printf("function min() requires at least one argument.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the minimum value as the first number in the list
    int res = nums[0];

    // Iterate through the list and update the minimum value if necessary
    for (int i = 1; i < len; i++) {
        res = (res < nums[i]) ? res : nums[i];
    }

    // Return the minimum value
    return res;
}

// Function to find the maximum of a list of numbers
int max(int nums[], int len) {
    // If the list is empty, panic with an error message
    if (len == 0) {
        printf("function max() requires at least one argument.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the maximum value as the first number in the list
    int res = nums[0];

    // Iterate through the list and update the maximum value if necessary
    for (int i = 1; i < len; i++) {
        res = (res > nums[i]) ? res : nums[i];
    }

    // Return the maximum value
    return res;
}

// Helper function to calculate the difference between the larger and smaller of two numbers
int doch(int l[]) {
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
    // Read the input list from standard input
    int l[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &l[i]);
    }

    // Calculate and print the minimum of the three patterns
    printf("%d\n", min(l, 3));

    return 0;
}
