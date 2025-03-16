#include <stdio.h>

// Define a function to solve the problem for a given test case
void solve(int tc) {
    int a;
    
    // Read an integer from standard input and strip any extra whitespace
    scanf("%d", &a);
    
    // Print 1 if the integer is 0, otherwise print 0
    printf("%d\n", (a == 0) ? 1 : 0);
}

// Initialize the number of test cases
int tcs = 1;

int main() {
    // Start with the first test case
    int tc = 1;
    
    // Loop through each test case until the specified number of test cases is reached
    while (tc <= tcs) {
        // Call the solve function for the current test case
        solve(tc);
        // Increment the test case counter
        tc++;
    }
    
    return 0;
}
