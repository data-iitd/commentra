
#include <stdio.h>
#include <stdlib.h>

// Create a new Scanner object to read input from the console
int main() {
    int t, n, i;
    scanf("%d", &t); // Initialize the Scanner object

    // Iterate through each test case
    for (i = 0; i < t; i++) {
        scanf("%d", &n); // Read the number of elements in the array

        // Print the maximum left sum
        printf("%d\n", maxLeft(n));
    }

    // Close the Scanner object to free up system resources
    // scan.close();

    return 0;
}

// Function to calculate the maximum sum of elements to the left of a given index
int maxLeft(int n) {
    // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n > 2 ? n - 2 : 0;
}

