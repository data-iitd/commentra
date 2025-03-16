#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

// Function to calculate the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to read an integer from standard input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read multiple integers from standard input
void read_ints(int *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int main() {
    int q, h, s, d, n;

    // Reading input values
    q = read_int();
    h = read_int();
    s = read_int();
    d = read_int();
    n = read_int();

    // Calculating the best price for single liters
    int best1L = min(q * 4, min(h * 2, s));

    // Calculating the best price for double liters
    int best2L = min(d, best1L * 2);

    // Checking if the quantity n is even or odd and printing the total cost accordingly
    if (n % 2 == 0) {
        printf("%d\n", best2L * (n / 2));
    } else {
        printf("%d\n", best2L * (n / 2) + best1L);
    }

    return 0;
}
