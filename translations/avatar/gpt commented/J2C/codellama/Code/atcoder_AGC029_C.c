#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 1000000

int n; // Number of elements in the array
int a[MAX_INPUT]; // Array to store the input integers
int s[MAX_INPUT]; // Array to keep track of counts of integers

int main() {
    // Create an instance of Main and invoke the solve method
    set(); // Initialize input values
    int ng = 0; // Lower bound for binary search
    int ok = n; // Upper bound for binary search

    // Perform binary search to find the maximum k
    while (ok - ng > 1) {
        int k = (ng + ok) / 2; // Calculate mid-point
        // Check if it is possible to achieve the current k
        if (isPossible(k)) {
            ok = k; // If possible, adjust upper bound
        } else {
            ng = k; // If not possible, adjust lower bound
        }
    }
    // Output the result
    printf("%d\n", ok);
    return 0;
}

void set() {
    // Read input values and initialize variables
    scanf("%d", &n); // Read the number of elements
    // Read the array elements and convert them to an integer array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    memset(s, 0, sizeof(s)); // Initialize the TreeMap
}

int isPossible(int k) {
    // Check if it is possible to achieve the given k
    memset(s, 0, sizeof(s)); // Clear the TreeMap for new calculations
    int current = 0; // Initialize current value

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {
        // If the current element is less than or equal to the current value
        if (a[i] <= current) {
            // If k is 1, return false as we cannot have duplicates
            if (k == 1) return 0;

            // Remove elements from TreeMap that are greater than or equal to ai
            while (s[n - 1] >= a[i]) {
                s[n - 1] = 0; // Remove the last entry
                n--;
            }

            int p = a[i] - 1; // Start checking from the previous number
            while (1) {
                // If p is less than 0, return false
                if (p < 0) return 0;

                // Get the count of p from TreeMap and increment it
                int sp = s[p] + 1;
                s[p] = sp; // Update the TreeMap with the new count

                // If the count reaches k, remove p from TreeMap and decrement p
                if (sp == k) {
                    s[p] = 0;
                    p--;
                } else {
                    break; // Exit the loop if count is less than k
                }
            }
        }
        current = a[i]; // Update current to the current element
    }
    return 1; // Return true if the condition is satisfied
}

