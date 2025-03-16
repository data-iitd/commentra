
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum sum of elements to the left of a given index
int maxLeft(int n) {
    // Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n > 2? n - 2 : 0;
}

// Driver code
int main() {
    // Read the number of test cases from the input
    int t;
    scanf("%d", &t);

    // Iterate through each test case
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n); // Read the number of elements in the array

        // Print the maximum left sum
        printf("%d\n", maxLeft(n));
    }

    return 0;
}

