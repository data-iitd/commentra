#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

// Function to read an integer from standard input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to calculate the least common multiple
int lcm(int x, int y) {
    return (x / gcd(x, y)) * y;
}

// Function to calculate the least common multiple of an array of numbers
int lcm_list(int *nums, int size) {
    int result = 1;
    for (int i = 0; i < size; i++) {
        result = lcm(result, nums[i]);
    }
    return result;
}

int main() {
    // Read input values
    int q = read_int();
    int h = read_int();
    int s = read_int();
    int d = read_int();
    int n = read_int();

    // Calculate the length of the longest segment that can be formed
    int best1L = (q * 4 < h * 2) ? (q * 4) : (h * 2);
    best1L = (best1L < s) ? best1L : s;
    
    int best2L = (d < best1L * 2) ? d : (best1L * 2);

    // Check if n is even
    if (n % 2 == 0) {
        // If it is, print the length of the longest segment that can be formed
        printf("%d\n", best2L * (n / 2));
    } else {
        // If n is odd, print the length of the longest segment that can be formed
        printf("%d\n", best2L * (n / 2) + best1L);
    }

    return 0;
}

// <END-OF-CODE>
