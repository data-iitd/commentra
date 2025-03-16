
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n; // Number of elements in the array
    int a[100000]; // Array to store the input integers
    int s[100001] = {0}; // Array to keep track of counts of integers

    // Read input values and initialize variables
    scanf("%d", &n); // Read the number of elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read the array elements
    }

    int ng = 0; // Lower bound for binary search
    int ok = n; // Upper bound for binary search

    // Perform binary search to find the maximum k
    while (ok - ng > 1) {
        int k = (ng + ok) / 2; // Calculate mid-point
        // Check if it is possible to achieve the current k
        memset(s, 0, sizeof(s)); // Clear the array for new calculations
        int current = 0; // Initialize current value

        // Iterate through each element in the array
        for (int i = 0; i < n; i++) {
            // If the current element is less than or equal to the current value
            if (a[i] <= current) {
                // If k is 1, return false as we cannot have duplicates
                if (k == 1) {
                    ok = k; // Adjust upper bound
                    break;
                }

                // Remove elements from the array that are greater than or equal to ai
                for (int j = a[i] - 1; j >= 0; j--) {
                    if (s[j] >= k) {
                        s[j] = 0; // Reset the count to 0
                    } else {
                        s[j]++; // Increment the count
                        break; // Exit the loop if count reaches k
                    }
                }
            }
            current = a[i]; // Update current to the current element
        }
        if (ok == k) break; // If the condition is satisfied, adjust upper bound
        ng = k; // If not possible, adjust lower bound
    }
    // Output the result
    printf("%d\n", ok);

    return 0;
}
