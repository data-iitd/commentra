#include <stdio.h>

// Function to solve the problem
void solve() {
    // Initialize variables
    int a, b;

    // Read input values from the user
    scanf("%d %d", &a, &b);

    // Initialize output string
    const char* ans;

    // Determine the answer based on the input values
    if (a == 1 && b == 1) {
        // Both a and b are equal to 1, so the answer is a draw
        ans = "Draw";
    } else if (a == 1) {
        // a is equal to 1, so the answer is Alice
        ans = "Alice";
    } else {
        // Neither a nor b is equal to 1, so the answer is Bob
        ans = "Bob";
    }

    // Print the answer to the console
    printf("%s\n", ans);
}

int main() {
    // Call the solve function to solve the problem
    solve();

    return 0;
}

// <END-OF-CODE>
