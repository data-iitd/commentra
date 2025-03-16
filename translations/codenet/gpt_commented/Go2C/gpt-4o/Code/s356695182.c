#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read an integer from standard input
int nextInt() {
    int num;
    scanf("%d", &num); // Read an integer from standard input
    return num; // Return the integer value
}

// Function to read a specified number of integers and return them in an array
void scanNums(int len, int *nums) {
    for (int i = 0; i < len; i++) {
        nums[i] = nextInt(); // Read an integer and store it in the array
    }
}

// Function to calculate the first pattern
int pattern1(int *l) {
    return (l[0] * l[3]) + (l[1] * l[4]); // Calculate and return the result
}

// Function to calculate the second pattern
int pattern2(int *l) {
    return 2 * l[2] * fmax(l[3], l[4]); // Calculate and return the result using fmax
}

// Function to calculate the third pattern
int pattern3(int *l) {
    return 2 * l[2] * fmin(l[3], l[4]) + doch(l); // Calculate and return the result
}

// Function to calculate a value based on the difference between the last two integers
int doch(int *l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]); // Return the product if the fourth integer is greater
    } else {
        return l[1] * (l[4] - l[3]); // Return the product if the fifth integer is greater
    }
}

// Function to find the minimum value from a variable number of integers
int min(int a, int b, int c) {
    return fmin(fmin(a, b), c); // Return the minimum value
}

// Main function where the program execution begins
int main() {
    int len = 5; // Define the number of integers to read
    int l[5]; // Declare an array to hold the integers
    scanNums(len, l); // Read the integers into the array
    // Print the minimum value from the three calculated patterns
    printf("%d\n", min(pattern1(l), pattern2(l), pattern3(l)));
    return 0; // Return success
}

// <END-OF-CODE>
