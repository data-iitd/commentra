
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 1000000

int main() {
    int n; // Number of elements in the array 'a'
    int a[MAX_INPUT]; // Array of integers
    int s[MAX_INPUT]; // Sorted map to store the count of each element
    int ng = 0; // Lower bound of the search range
    int ok = n; // Upper bound of the search range
    int k; // Middle index of the search range
    int current = 0; // Current index in the array 'a'
    int ai; // Current element in the array 'a'
    int p; // Previous index in the array 'a'
    int sp; // Count of 'p' in the TreeMap
    int i; // Loop counter

    // Read the number of elements 'n' and the elements of the array 'a'
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize the TreeMap 's'
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }

    // Run the while loop until the search range is narrowed down to a single element
    while (ok - ng > 1) {
        k = (ng + ok) / 2; // Calculate the middle index of the search range
        if (isPossible(k)) { // If the middle index 'k' is a valid solution, update the upper bound
            ok = k;
        } else { // Otherwise, update the lower bound
            ng = k;
        }
    }

    // Print the solution
    printf("%d\n", ok);

    return 0;
}

int isPossible(int k) {
    int current = 0; // Initialize the current index in the array 'a'
    int ai; // Current element in the array 'a'
    int p; // Previous index in the array 'a'
    int sp; // Count of 'p' in the TreeMap
    int i; // Loop counter

    // Iterate through each element in the array 'a'
    for (i = 0; i < n; i++) {
        ai = a[i]; // Get the current element
        if (ai <= current) { // If the current element is smaller than or equal to the previous one, check if the condition 'k' is valid
            if (k == 1) return 0; // If 'k' is 1, return false as there is no possible solution

            // If there is an element greater than or equal to 'ai' in the TreeMap, remove it
            while (s[i] >= ai) {
                s[i]--;
            }

            p = ai - 1; // Calculate the previous index 'p'
            while (true) { // Find the previous index 'p' with the count 'k' in the TreeMap
                if (p < 0) return 0; // If 'p' is out of the array bounds, return false

                sp = s[p] + 1; // Get the count of 'p' in the TreeMap or initialize it to 1
                s[p] = sp; // Update the count of 'p' in the TreeMap

                if (sp == k) { // If the count of 'p' is equal to 'k', remove it and move to the previous index
                    s[p]--;
                    p--;
                } else { // Otherwise, break the loop
                    break;
                }
            }
        }
        current = ai; // Update the current index
    }

    return 1; // If all elements in the array 'a' are processed, return true as a valid solution is found
}

