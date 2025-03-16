#include <stdio.h>

// Function to reverse the digits of an integer n
int reverse(int n) {
    // If n is a single digit, return n multiplied by 10
    if (n < 10) return n * 10;

    int t = n, r = 0;

    // Loop to reverse the digits of n
    while (t > 0) {
        r = (r * 10) + (t % 10); // Add the last digit of t to r
        t = t / 10; // Remove the last digit from t
    }

    // Return the reversed integer
    return r;
}

int main() {
    // Declare variables for input
    int n, m;

    // Read two integers n and m from input
    scanf("%d %d", &n, &m);

    // Reverse the integer m and store the result in t
    int t = reverse(m);

    // Print the sum of t and n
    printf("%d\n", t + n);

    return 0;
}

// <END-OF-CODE>
