#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} arm;

// Comparison function for sorting arms based on their right end
int compare(const void *a, const void *b) {
    return ((arm *)a)->r - ((arm *)b)->r;
}

// Function to read an integer from standard input
int scanInt() {
    int iv;
    scanf("%d", &iv); // Read an integer
    return iv; // Return the integer
}

// Main function
int main() {
    // Read the number of arms, n
    int n = scanInt();

    // Initialize an array of arm structures
    arm *as = (arm *)malloc(n * sizeof(arm));

    // Read and initialize each arm structure in the array
    for (int i = 0; i < n; i++) {
        int x = scanInt();
        int l = scanInt();

        // Initialize the left and right fields of the arm structure
        as[i].l = x - l;
        as[i].r = x + l;
    }

    // Sort the array based on the right field of the arm structures
    qsort(as, n, sizeof(arm), compare);

    // Initialize answer variable, ans, and right variable, r
    int ans = 1;
    int r = as[0].r;

    // Iterate through the array and update the answer and right variable accordingly
    for (int i = 1; i < n; i++) {
        if (as[i].l >= r) { // Check if the left end of the current arm is greater than or equal to the right end of the previous arm
            ans++; // Increment the answer if it is
            r = as[i].r; // Update the right variable with the right end of the current arm
        }
    }

    // Print the answer
    printf("%d\n", ans);

    // Free allocated memory
    free(as);

    return 0;
}

// <END-OF-CODE>
