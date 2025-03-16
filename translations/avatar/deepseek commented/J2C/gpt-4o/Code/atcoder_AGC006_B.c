#include <stdio.h> // Include standard input-output library

void print(int x, int n) {
    int max = n * 2 - 1; // Calculate the maximum value based on n
    if (x == 1 || x == max) { // Check if x is at the edges
        printf("No\n"); // Print "No" if x is 1 or max
        return; // Exit the function
    }
    printf("Yes\n"); // Print "Yes" if x is within the valid range

    for (int i = x + n - 1; i < x + n + max - 1; i++) { // Generate numbers in the range
        printf("%d\n", (i % max) + 1); // Print each number in the required format
    }
}

int main() {
    int n, x; // Declare variables for input
    scanf("%d %d", &n, &x); // Read the first and second integer input
    print(x, n); // Call the print function with x and n as arguments
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
