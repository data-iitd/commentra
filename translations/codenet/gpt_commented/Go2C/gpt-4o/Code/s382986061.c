#include <stdio.h>

#define MAX_N 1000 // Assuming a maximum size for N

// Declare global variables for the number of elements (N), number of groups (K), 
// and temporary variables (d for group size, a for element).
int N, K;
int d, a;
int as[MAX_N + 1]; // Array to count occurrences of each element, indexed from 1 to N.

int main() {
    // Read the total number of elements (N) and the number of groups (K) from input.
    scanf("%d %d", &N, &K);

    // Initialize the count of each element to 0.
    for (int i = 1; i <= N; i++) {
        as[i] = 0; // Set initial count of each element to 0.
    }

    // Process each group of elements.
    for (int i = 0; i < K; i++) {
        // Read the size of the current group (d).
        scanf("%d", &d);
        // Read each element in the group and increment its count in the array.
        for (int j = 0; j < d; j++) {
            scanf("%d", &a);
            as[a]++; // Increment the count for the element a.
        }
    }

    // Initialize a counter for elements that are not present in any group.
    int ans = 0;
    // Iterate through the counts of each element in the array.
    for (int i = 1; i <= N; i++) {
        // If an element's count is 0, it means it was not present in any group.
        if (as[i] == 0) {
            ans++; // Increment the counter for missing elements.
        }
    }

    // Output the total count of elements that were not present in any group.
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
