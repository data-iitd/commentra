#include <stdio.h>      // For input and output functions
#include <stdlib.h>     // For dynamic memory allocation
#include <string.h>     // For string manipulation
#include <math.h>       // For mathematical functions

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Read input values for n and m
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the greatest common divisor (GCD) of n and m
    int g = gcd(n, m);

    // Read input strings s and t
    char s[100001], t[100001]; // Assuming maximum length of strings is 100000
    scanf("%s %s", s, t);

    // Perform the required calculation
    long result = -1;
    for (int k = 0; k < g; k++) {
        if (s[k * n / g] != t[k * m / g]) {
            result = -1;
            break;
        }
        result = (long)n * m / g; // Default result if no mismatch is found
    }

    // Print the result
    printf("%ld\n", result);

    return 0;
}

// <END-OF-CODE>
