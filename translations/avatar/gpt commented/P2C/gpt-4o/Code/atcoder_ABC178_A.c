#include <stdio.h>

void solve(int tc) {
    int a;
    // Read an integer from standard input
    scanf("%d", &a);
    
    // Print 1 if the integer is 0, otherwise print 0
    printf("%d\n", (a == 0) ? 1 : 0);
}

int main() {
    int tcs = 1; // Initialize the number of test cases
    int tc = 1;  // Start with the first test case

    // Loop through each test case until the specified number of test cases is reached
    while (tc <= tcs) {
        solve(tc); // Call the solve function for the current test case
        tc++;      // Increment the test case counter
    }

    return 0;
}

// <END-OF-CODE>
