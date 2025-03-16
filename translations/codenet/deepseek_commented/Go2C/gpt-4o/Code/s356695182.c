#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read a single integer from standard input.
int nextInt() {
    int t;
    scanf("%d", &t);
    return t;
}

// Function to read a slice of integers from standard input.
void scanNums(int len, int *nums) {
    for (int i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
    }
}

// Computes a value using the first two and last two elements of the input array.
int pattern1(int *l) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

// Computes another value using the third element and the maximum of the last two elements.
int pattern2(int *l) {
    return 2 * l[2] * fmax(l[3], l[4]);
}

// Computes yet another value using the third element, the minimum of the last two elements, and the result of doch(l).
int pattern3(int *l) {
    return 2 * l[2] * fmin(l[3], l[4]) + doch(l);
}

<<<<<<< HEAD
=======
// Returns the minimum value among the given integers.
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Returns the maximum value among the given integers.
int max(int a, int b) {
    return (a > b) ? a : b;
}

>>>>>>> 98c87cb78a (data updated)
// Calculates a specific value based on the input array.
int doch(int *l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

<<<<<<< HEAD
// Returns the minimum value among the given integers.
int min(int a, int b, int c) {
    return fmin(fmin(a, b), c);
}

=======
>>>>>>> 98c87cb78a (data updated)
// Main function to read input, compute the minimum value, and print it.
int main() {
    int len = 5;
    int l[5];
    scanNums(len, l);
<<<<<<< HEAD
    printf("%d\n", min(pattern1(l), pattern2(l), pattern3(l)));
=======
    int result = min(min(pattern1(l), pattern2(l)), pattern3(l));
    printf("%d\n", result);
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
