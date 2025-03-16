#include <stdio.h>

// Function to calculate the maximum sum of elements to the left of a given index
int maxLeft(int n) {
    // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n > 2 ? n - 2 : 0;
}

int main() {
    int t; // Number of test cases

    // Read the number of test cases from the input
    scanf("%d", &t);

    // Iterate through each test case
    for (int i = 0; i < t; i++) {
        int n; // Number of elements in the array

        // Read the number of elements in the array
        scanf("%d", &n);

        // Print the maximum left sum
        printf("%d\n", maxLeft(n));
    }

    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
