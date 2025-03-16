#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Initialize variables for processing the input
    int ans = 0;
    int aPrev = 0;

    // Process each test case
    for (int i = 0; i < n; i++) {
        // Read the next integer as 'a'
        int a;
        scanf("%d", &a);

        // Check if 'a' is valid based on the conditions in the problem statement
        if (a > i || a > aPrev + 1) { // 'a' is not valid, print -1 and exit
            printf("-1\n");
            return 0;
        } else if (a == aPrev + 1) { // Increment the answer if 'a' is consecutive with the previous number
            ans++;
        } else { // Add 'a' to the answer if it's not consecutive but greater than the previous number
            ans += a;
        }

        // Update the previous number
        aPrev = a;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
