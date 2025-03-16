
#include <stdio.h> // Include the standard input/output library

int main() {
    int n, x; // Declare variables for n and x
    scanf("%d %d", &n, &x); // Read the input values for n and x
    int max = n * 2 - 1; // Calculate the maximum value based on n
    if (x == 1 || x == max) { // Check if x is at the edges
        printf("No\n"); // Print "No" if x is 1 or max
        return 0; // Exit the program
    }
    printf("Yes\n"); // Print "Yes" if x is within the valid range
    for (int i = x + n - 1; i < x + n + max - 1; i++) { // Iterate over the required range
        int num = (i % max + 1); // Calculate the current number
        printf("%d\n", num); // Print the current number
    }
    return 0; // Return 0 to indicate successful execution
}

