#include <stdio.h>      // For standard input/output functions
#include <stdlib.h>     // For dynamic memory allocation
#include <math.h>       // For mathematical functions
#include <stdint.h>     // For fixed-width integer types

// Function to calculate the binomial coefficient C(n, m)
unsigned long long C(int n, int m) {
    unsigned long long res = 1;  // Initialize result as 1

    // Calculate the binomial coefficient for n choose m
    for (int i = m - n + 1; i <= m; i++) {
        res *= i;  // Multiply with current term
    }

    for (int i = 1; i <= n; i++) {
        res /= i;  // Divide with denominator
    }

    return res;  // Return the calculated binomial coefficient
}

int main() {
    int n, p;  // Declare variables n and p
    int k0 = 0, k1 = 0;  // Initialize counters k0 and k1 to 0

    scanf("%d", &n);  // Read the value of n from standard input
    scanf("%d", &p);  // Read the value of p from standard input

    // Read the values of n elements and count the number of odd and even elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);  // Read the current element

        if (x % 2 == 1) {
            k1++;  // Increment the counter k1 if the current element is odd
        } else {
            k0++;  // Increment the counter k0 if the current element is even
        }
    }

    unsigned long long ans = 1;  // Initialize answer as 1

    // Calculate the answer based on the given conditions
    ans <<= k0;  // Multiply answer by 2^k0 (using bitwise left shift)

    if (p == 0) {  // If p is 0, calculate the answer using the given formula
        unsigned long long add = 0;  // Initialize add as 0

        for (int i = 0; i <= k1; i += 2) {
            add += C(i, k1);  // Calculate the sum of C(i, k1) for i from 0 to k1 with a step of 2
        }

        ans *= add;  // Multiply the answer with the calculated sum

        printf("%llu\n", ans);  // Print the final answer
    } else {  // If p is not 0, calculate the answer using a similar formula
        unsigned long long add = 0;  // Initialize add as 0

        for (int i = 1; i <= k1; i += 2) {
            add += C(i, k1);  // Calculate the sum of C(i, k1) for i from 1 to k1 with a step of 2
        }

        ans *= add;  // Multiply the answer with the calculated sum

        printf("%llu\n", ans);  // Print the final answer
    }

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
