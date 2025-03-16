#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read an integer from standard input
int readInt() {
    int t;
    scanf("%d", &t);
    return t;
}

// Function to read a specified number of integers from standard input
int* readNums(int len) {
    int* nums = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
    }
    return nums;
}

// Function to calculate the first pattern
int pattern1(int* l) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

// Function to calculate the second pattern
int pattern2(int* l) {
    return 2 * l[2] * (l[3] > l[4] ? l[3] : l[4]);
}

// Function to calculate the third pattern
int pattern3(int* l) {
    return 2 * l[2] * (l[3] < l[4] ? l[3] : l[4]) + doch(l);
}

// Function to find the minimum value among a variable number of integers
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        res = fmin(res, num);
    }
    va_end(args);
    return res;
}

// Function to find the maximum value among a variable number of integers
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        res = fmax(res, num);
    }
    va_end(args);
    return res;
}

// Function to calculate a value based on the difference between the last two integers
int doch(int* l) {
    return l[3] > l[4] ? l[0] * (l[3] - l[4]) : l[1] * (l[4] - l[3]);
}

// Main function where the program execution begins
int main() {
    int len = 5;
    int* l = readNums(len);
    // Print the minimum value from the three calculated patterns
    printf("%d\n", min(3, pattern1(l), pattern2(l), pattern3(l)));
    free(l); // Free the allocated memory
    return 0;
}
