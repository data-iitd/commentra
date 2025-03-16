#include <stdio.h>

// Function to calculate the sum of the first n natural numbers
int sum_of_first_n(int n) {
    return (1 + n) * n / 2;
}

// Function to solve the problem for a given n
int solve(int n) {
    int s = sum_of_first_n(n);
    int t = 1;
    
    // Subtract twice the value of powers of 2 from the sum until t exceeds n
    while (t <= n) {
        s -= 2 * t;  // Subtract 2 times the current power of 2 from the sum
        t *= 2;      // Move to the next power of 2
    }
    
    return s;
}

int main() {
    int t;
    scanf("%d", &t);  // Read the number of test cases
    
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);  // Read the input value for n
        printf("%d\n", solve(n));  // Print the result of the solve function for the current n
    }
    
    return 0;
}

