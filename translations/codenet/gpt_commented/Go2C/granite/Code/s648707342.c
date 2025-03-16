
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent an arm with left and right bounds
typedef struct {
    int l, r;
} arm;

// Function to compare two arms based on their right bounds
int compare_arm(const void *a, const void *b) {
    arm *aa = (arm *)a;
    arm *bb = (arm *)b;
    return aa->r - bb->r;
}

int main() {
    // Read the number of arms
    int n;
    scanf("%d", &n);

    // Create a slice to hold the arms
    arm *as = (arm *)malloc(sizeof(arm) * n);

    // Read the arm data from input
    for (int i = 0; i < n; i++) {
        int x, l;
        scanf("%d %d", &x, &l);
        as[i].l = x - l; // Calculate the left bound
        as[i].r = x + l; // Calculate the right bound
    }

    // Sort the arms based on their right bounds
    qsort(as, n, sizeof(arm), compare_arm);

    // Initialize the count of non-overlapping arms and the rightmost bound
    int ans = 1; // Start with the first arm
    int r = as[0].r; // Set the rightmost bound to the right of the first arm

    // Iterate through the sorted arms to count non-overlapping arms
    for (int i = 1; i < n; i++) {
        // If the left bound of the current arm is greater than or equal to the rightmost bound
        if (as[i].l >= r) {
            ans++; // Increment the count of non-overlapping arms
            r = as[i].r; // Update the rightmost bound to the current arm's right bound
        }
    }

    // Print the total count of non-overlapping arms
    printf("%d\n", ans);

    // Free the memory allocated for the arms
    free(as);

    return 0;
}
