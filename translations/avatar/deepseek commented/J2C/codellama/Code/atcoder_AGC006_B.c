#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the required output
void print(int x, int n) {
    int max = n * 2 - 1; // Calculate the maximum value based on n
    if (x == 1 || x == max) { // Check if x is at the edges
        printf("No\n"); // Print "No" if x is 1 or max
        return; // Exit the function
    }
    printf("Yes\n"); // Print "Yes" if x is within the valid range
    char sep[2] = "\n"; // Define the line separator
    char ans[max]; // Define the answer string
    for (int i = x + n - 1; i < x + n + max - 1; i++) { // Iterate over the required range
        int j = i % max + 1; // Calculate the required value
        sprintf(ans + (i - x - n + 1) * 2, "%d%s", j, sep); // Format and append to the answer string
    }
    printf("%s", ans); // Print the constructed string
}

int main() {
    int n, x; // Declare variables
    scanf("%d %d", &n, &x); // Read the input
    print(x, n); // Call the print function with x and n as arguments
    return 0; // Return 0
}

