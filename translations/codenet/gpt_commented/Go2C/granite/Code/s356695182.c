
#include <stdio.h>
#include <math.h>

// Initialize a new scanner to read from standard input
#define sc scanf

// nextInt reads the next integer from standard input
int nextInt() {
    int t;
    sc("%d", &t);
    return t;
}

// scanNums reads a specified number of integers from standard input and returns them as a slice
int* scanNums(int len) {
    int* nums = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        sc("%d", &nums[i]);
    }
    return nums;
}

// pattern1 calculates a specific pattern based on the first five integers in the slice
int pattern1(int* l) {
    int n = (l[0]*l[3]) + (l[1]*l[4]);
    return n;
}

// pattern2 calculates another pattern based on the maximum of the last two integers
int pattern2(int* l) {
    int n = 2 * l[2] * fmax(l[3], l[4]);
    return n;
}

// pattern3 calculates a third pattern that combines the minimum value and a function call
int pattern3(int* l) {
    int n = 2*l[2]*fmin(l[3], l[4]) + doch(l);
    return n;
}

// min returns the minimum value from a variable number of integer arguments
int min(int n,...) {
    va_list args;
    va_start(args, n);
    int res = n;
    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        res = fmin(res, (double)num);
    }
    va_end(args);
    return res;
}

// max returns the maximum value from a variable number of integer arguments
int max(int n,...) {
    va_list args;
    va_start(args, n);
    int res = n;
    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        res = fmax(res, (double)num);
    }
    va_end(args);
    return res;
}

// doch calculates a value based on the difference between the last two integers in the slice
int doch(int* l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

// main function where the program execution begins
int main() {
    int len = 5; // Define the number of integers to read
    int* l = scanNums(len); // Read the integers into a slice
    // Print the minimum value from the three calculated patterns
    printf("%d\n", min(pattern1(l), pattern2(l), pattern3(l)));
    return 0;
}
