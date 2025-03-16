#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100000

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate the absolute value
int abs(int n) {
    return n < 0 ? -n : n;
}

// The solve function reads an integer n and a slice of integers as.
// It then creates a new array xs where each element is calculated as a - i + 1.
// The array xs is sorted.
// The median of the sorted xs is chosen as b.
// The function calculates the sum of absolute differences between each element in xs and b.
// The result is printed.
void solve() {
    int n;
    scanf("%d", &n);
    
    int as[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int xs[MAX_N];
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }
    
    qsort(xs, n, sizeof(int), compare); // Sort the array xs

    int b = xs[n / 2]; // Choose the median as b
    long long ans = 0; // Use long long to avoid overflow
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    
    printf("%lld\n", ans);
}

// The main function initializes the program and calls the solve function.
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
