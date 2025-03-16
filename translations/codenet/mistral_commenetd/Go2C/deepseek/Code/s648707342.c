#include <stdio.h>
#include <stdlib.h>

// Define a structure for the arm
typedef struct {
    int l, r;
} arm;

// Function to compare two arms based on their right end
int compare(const void *a, const void *b) {
    arm *armA = (arm *)a;
    arm *armB = (arm *)b;
    return armA->r - armB->r;
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of arms

    // Allocate memory for the arms
    arm *as = (arm *)malloc(n * sizeof(arm));

    // Read and initialize each arm structure
    for (int i = 0; i < n; i++) {
        scanf("%*d %d", &as[i].l); // Read the position of the arm
        scanf("%d", &as[i].r); // Read the length of the arm
        // Calculate the left and right fields of the arm structure
        as[i].l = as[i].l - as[i].r;
        as[i].r = as[i].l + 2 * as[i].r;
    }

    // Sort the arms based on the right field
    qsort(as, n, sizeof(arm), compare);

    // Initialize answer variable, ans, and right variable, r
    int ans = 1;
    int r = as[0].r;

    // Iterate through the arms and update the answer and right variable accordingly
    for (int i = 1; i < n; i++) {
        if (as[i].l >= r) { // Check if the left end of the current arm is greater than or equal to the right end of the previous arm
            ans++; // Increment the answer if it is
            r = as[i].r; // Update the right variable with the right end of the current arm
        }
    }

    // Print the answer
    printf("%d\n", ans);

    // Free the allocated memory
    free(as);

    // End of code
    return 0;
}
