#include <stdio.h> // For input and output functions
#include <stdlib.h> // For memory allocation and other utility functions
#include <string.h> // For string manipulation
#include <math.h> // For mathematical functions

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // Reading the first two integers
    int g = gcd(n, m); // Calculating the GCD of n and m

    char s[100001], t[100001]; // Assuming maximum length of strings is 100000
    scanf("%s %s", s, t); // Reading the two strings

    // Checking character mismatches in the range of the GCD
    for (int k = 0; k < g; k++) {
        if (s[k * n / g] != t[k * m / g]) {
            printf("-1\n"); // If a mismatch is found, print -1 and exit
            return 0;
        }
    }

    // If no mismatches are found, calculate and print the result
    long long result = (long long)n * m / g;
    printf("%lld\n", result);

    return 0;
}
