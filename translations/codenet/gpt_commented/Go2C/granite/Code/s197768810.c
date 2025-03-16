
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the scanner to split input by whitespace
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize a slice to hold m integers
    int a[m];

    // Initialize a variable to hold the sum of the integers read
    int sum = 0;

    // Read m integers from input and calculate their sum
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]); // Read an integer and store it in the slice
        sum += a[i]; // Add the integer to the sum
    }

    // Check if the sum of the integers exceeds n
    if (sum > n) {
        printf("-1\n"); // Print -1 if the sum is greater than n
        return 0; // Exit the function
    }

    // Print the difference between n and the sum of the integers
    printf("%d\n", n - sum);

    return 0; // Return 0 to indicate successful execution
}
