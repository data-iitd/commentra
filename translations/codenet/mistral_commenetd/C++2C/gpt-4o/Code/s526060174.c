#include <stdio.h>

#define rep(S, L) for (int i = S; i < L; ++i) // Define a shorthand for for loop

int main() {
    int n, m; // Declare variables n and m for input size
    int k, a; // Declare variables k and a for intermediate calculations
    int x[32] = {0}; // Initialize an array x of size 32 with zeros (size 32 to accommodate 1 to 31)

    // Read input values for n and m
    scanf("%d %d", &n, &m);

    // Process each input value for n times
    rep(0, n) {
        scanf("%d", &k); // Read the number of elements in the current input

        // Process each element in the current input
        rep(0, k) {
            scanf("%d", &a); // Read the value of the current element
            x[a]++; // Increment the count of the current value in the array x
        }
    }

    // Initialize answer variable to zero
    int ans = 0;

    // Check each value from 1 to m and increment the answer if the count is equal to n
    rep(1, m + 1) {
        if (x[i] == n) { // Check if the count of the current value is equal to n
            ans++; // Increment the answer if true
        }
    }

    // Output the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
