#include <stdio.h>

void solve(int tc) {
    int a;
    // Read an integer input from standard input
    scanf("%d", &a);
    // Print 1 if the input is 0, otherwise print 0
    printf("%d\n", (a == 0) ? 1 : 0);
}

int main() {
    int tcs = 1; // Set the number of test cases to 1
    int tc = 1;  // Initialize the current test case number

    // Enter a while loop that continues as long as the current test case number is less than or equal to the total number of test cases
    while (tc <= tcs) {
        solve(tc); // Call the solve function with the current test case number
        tc++;      // Increment the current test case number
    }

    return 0;
}

// <END-OF-CODE>
