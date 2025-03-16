#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

// Function to read an integer from input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers from input
void read_int_list(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to compute the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    // Read input values for costs of different types of drinks
    int q, h, s, d;
    scanf("%d %d %d %d", &q, &h, &s, &d);

    // Read the number of drinks to be purchased
    int n = read_int();

    // Calculate the best price for 1 liter of drink
    int best1L = min(min(q * 4, h * 2), s);

    // Calculate the best price for 2 liters of drink
    int best2L = min(d, best1L * 2);

    // Calculate and print the total cost based on whether n is even or odd
    if (n % 2 == 0) {
        printf("%d\n", best2L * (n / 2));  // Total cost for even number of drinks
    } else {
        printf("%d\n", best2L * (n / 2) + best1L);  // Total cost for odd number of drinks
    }

    return 0;
}

// <END-OF-CODE>
