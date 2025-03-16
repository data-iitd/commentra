
#include <stdio.h>

// Define a function to solve the problem for a given n
int solve(int n) {
    // Calculate the sum of the first n natural numbers using the formula n(n + 1) / 2
    int s = (1 + n) * n / 2;
    
    // Initialize a variable to track the power of 2
    int t = 1;
    
    // Subtract twice the value of powers of 2 from the sum until t exceeds n
    while (t <= n) {
        s -= 2 * t;  // Subtract 2 times the current power of 2 from the sum
        t *= 2;      // Move to the next power of 2
    }
    
    // Return the final computed sum
    return s;
}

int main() {
    // Read the number of test cases
    int t;
    scanf("%d", &t);
    
    // Loop over each test case
    for (int i = 0; i < t; i++) {
        // Read the input value for n
        int n;
        scanf("%d", &n);
        
        // Print the result of the solve function for the current n
        printf("%d\n", solve(n));
    }
    
    return 0;
}
