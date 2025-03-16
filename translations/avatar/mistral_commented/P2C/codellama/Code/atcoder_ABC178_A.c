#include <stdio.h>

// Function to solve a single test case
void solve(int tc) {
    // Read the next test case and store it in a variable 'a'
    int a;
    scanf("%d", &a);

    // Print the solution for the current test case
    printf("%d\n", (a == 0) ? 1 : 0);
}

// Initialize the number of test cases and the test case counter
int tcs = 1, tc = 1;

// Run the solution function for each test case
while (tc <= tcs) {
    // Solve the current test case
    solve(tc);

    // Increment the test case counter
    tc += 1;
}

