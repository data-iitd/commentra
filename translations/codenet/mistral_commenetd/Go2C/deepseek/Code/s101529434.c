#include <stdio.h>

int main() {
    // Declare two integer variables, K and X
    int K, X;

    // Read two integers from the standard input and assign them to the variables K and X respectively
    scanf("%d %d", &K, &X);

    // Check if the condition 500*K >= X is true
    if (500 * K >= X) {
        // If the condition is true, print the string "Yes" to the standard output
        printf("Yes\n");
    } else {
        // If the condition is false, print the string "No" to the standard output
        printf("No\n");
    }

    return 0;
}

