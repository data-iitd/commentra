#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Reads a single integer from standard input.
int nextInt() {
    int t;
    scanf("%d", &t);
    return t;
}

// Reads a slice of integers from standard input.
int* scanNums(int len) {
    int* nums = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
    }
    return nums;
}

// Computes a value using the first two and last two elements of the input slice.
int pattern1(int* l, int len) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

// Computes another value using the third element and the maximum of the last two elements.
int pattern2(int* l, int len) {
    return 2 * l[2] * fmax(l[3], l[4]);
}

// Computes yet another value using the third element, the minimum of the last two elements, and the result of doch(l).
int pattern3(int* l, int len) {
    return 2 * l[2] * fmin(l[3], l[4]) + doch(l, len);
}

// Returns the minimum value among the given integers.
int min(int nums[], int len) {
    int res = nums[0];
    for (int i = 1; i < len; i++) {
        res = fmin(res, nums[i]);
    }
    return res;
}

// Returns the maximum value among the given integers.
int max(int nums[], int len) {
    int res = nums[0];
    for (int i = 1; i < len; i++) {
        res = fmax(res, nums[i]);
    }
    return res;
}

// Calculates a specific value based on the input slice.
int doch(int* l, int len) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

// Main function to read input, compute the minimum value, and print it.
int main() {
    int len = 5;
    int* l = scanNums(len);
    int result = min((int[]){pattern1(l, len), pattern2(l, len), pattern3(l, len)}, 3);
    printf("%d\n", result);
    free(l);
    return 0;
}
