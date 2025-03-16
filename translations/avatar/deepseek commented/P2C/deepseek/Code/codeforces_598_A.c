#include <stdio.h>

int solve(int n) {
    // Calculate the sum of the first n natural numbers
    int s = (1 + n) * n / 2;
    // Initialize t to 1
    int t = 1;
    // Subtract twice the sum of powers of 2 up to n from s
    while (t <= n) {
        s -= 2 * t;
        t *= 2;
    }
    return s;
}

int main() {
    int t;
    // Read the number of test cases
    scanf("%d", &t);
    // Main loop to iterate over the number of test cases
    for (int i = 0; i < t; i++) {
        int n;
        // Read each n for the test case
        scanf("%d", &n);
        // Print the result of the solve function for the current n
        printf("%d\n", solve(n));
    }
    return 0;
}

