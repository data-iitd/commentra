#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    // Read the number of intervals
    scanf("%d", &n);

    // Initialize the index for the result
    int id = 0;

    // Read the first interval's bounds
    int l, r;
    scanf("%d %d", &l, &r);

    // Iterate through the remaining intervals
    for (int i = 1; i < n; i++) {
        // Read the current interval's bounds
        int li, ri;
        scanf("%d %d", &li, &ri);
        
        // Check if the current interval completely contains the previous one
        if (li <= l && r <= ri) {
            id = i;  // Update the index to the current interval
        }
        // Check if the current interval overlaps with the previous one
        else if (li < l || r < ri) {
            id = n;  // Mark as overlapping by setting id to n
        }
        
        // Update the bounds of the union of intervals
        l = (l < li) ? l : li;  // Update the left bound
        r = (r > ri) ? r : ri;  // Update the right bound
    }

    // Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
    printf("%d\n", (id == n) ? -1 : id + 1);

    return 0;
}

// <END-OF-CODE>
