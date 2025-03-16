#include <stdio.h>

// Solve function takes three integers a, b, and c as input and returns an integer.
int solve(int a, int b, int c) {
    int temp;
    // Check if c is equal to the sum of a and b
    if (c == a + b) {
        temp = b + c;
    } else if (c - 1 > a + b) { // Check if c-1 is greater than the sum of a and b
        temp = (c - 1) - (a + b);
        temp = b + c - temp; // Calculate temp based on the difference
    } else { // If neither condition is met
        temp = b + c;
    }
    return temp;
}

// Main function reads three integers from standard input, calls the solve function with these integers, and prints the result.
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int ans = solve(a, b, c);
    printf("%d\n", ans);

    return 0;
}

