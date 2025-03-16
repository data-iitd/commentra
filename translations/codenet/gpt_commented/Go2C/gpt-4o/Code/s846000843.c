#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100000
#define INF 2020202020

// Function prototypes
int* cum_sum(int* nums, int n);
int min(int a, int b);
int abs(int a);
int gcd(int a, int b);
int lcm(int a, int b);
void flush();
void read_ints(int* arr, int n);

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Create an array to hold the input integers
    int* aa = (int*)malloc(n * sizeof(int));
    read_ints(aa, n);

    // Compute the cumulative sum of the input integers
    int* cumsum = cum_sum(aa, n);

    // Initialize the answer with a large value
    int ans = INF;

    // Iterate through the cumulative sums to find the minimum difference
    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, abs(cumsum[n] - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    // Output the final answer
    printf("%d\n", ans);

    // Free allocated memory
    free(aa);
    free(cumsum);
    return 0;
}

// Function to compute cumulative sum
int* cum_sum(int* nums, int n) {
    int* sums = (int*)malloc((n + 1) * sizeof(int));
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

// Function to find minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to return absolute value
int abs(int a) {
    return (a >= 0) ? a : -a;
}

// Function to compute GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to compute LCM
int lcm(int a, int b) {
    if (a == 0 && b == 0) return 0;
    return a * (b / gcd(a, b));
}

// Function to read integers from input
void read_ints(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to flush output (not needed in C, but included for completeness)
void flush() {
    fflush(stdout);
}

// <END-OF-CODE>
