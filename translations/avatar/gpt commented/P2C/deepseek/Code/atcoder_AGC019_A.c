#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to compute the ceiling of a divided by b
int ceil(int a, int b) {
    return (a + b - 1) / b;
}

// Function to compute the least common multiple of two numbers
int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}

// Function to compute the greatest common divisor of two numbers
int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Function to read an integer from input
int read_int() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a list of integers from input
void read_ints(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    // Read input values for costs of different types of drinks
    int q, h, s, d;
    scanf("%d %d %d %d", &q, &h, &s, &d);

    // Read the number of drinks to be purchased
    int n = read_int();

    // Calculate the best price for 1 liter of drink
    int best1L = q < h ? (q < s ? q : s) : (h < s ? h : s);
    best1L = best1L < (q < h ? (q < s ? q : s) : (h < s ? h : s)) ? best1L : (q < h ? (q < s ? q : s) : (h < s ? h : s));
    best1L = best1L * 4 < best1L * 2 ? best1L * 4 : best1L * 2;
    best1L = best1L < s ? best1L : s;

    // Calculate the best price for 2 liters of drink
    int best2L = d < best1L * 2 ? d : best1L * 2;

    // Calculate and print the total cost based on whether n is even or odd
    if (n % 2 == 0) {
        printf("%d\n", best2L * (n / 2));  // Total cost for even number of drinks
    } else {
        printf("%d\n", best2L * (n / 2) + best1L);  // Total cost for odd number of drinks
    }

    return 0;
}
