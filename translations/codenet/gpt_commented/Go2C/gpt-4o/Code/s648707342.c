#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
=======
// Define a struct to represent an arm with left and right bounds
>>>>>>> 98c87cb78a (data updated)
typedef struct {
    int l, r;
} arm;

<<<<<<< HEAD
// Comparator function for sorting arms based on their right bounds
=======
// Function to compare two arms based on their right bounds for sorting
>>>>>>> 98c87cb78a (data updated)
int compare(const void *a, const void *b) {
    return ((arm *)a)->r - ((arm *)b)->r;
}

int main() {
<<<<<<< HEAD
    int n;
    scanf("%d", &n); // Read the number of arms

    arm *as = malloc(n * sizeof(arm)); // Allocate memory for arms

=======
    // Read the number of arms
    int n;
    scanf("%d", &n);
    
    // Create an array to hold the arms
    arm *as = (arm *)malloc(n * sizeof(arm));
    
>>>>>>> 98c87cb78a (data updated)
    // Read the arm data from input
    for (int i = 0; i < n; i++) {
        int x, l;
        scanf("%d %d", &x, &l); // Read the center and length of the arm
        as[i].l = x - l; // Calculate the left bound
        as[i].r = x + l; // Calculate the right bound
    }
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    // Sort the arms based on their right bounds
    qsort(as, n, sizeof(arm), compare);

    // Initialize the count of non-overlapping arms and the rightmost bound
    int ans = 1; // Start with the first arm
    int r = as[0].r; // Set the rightmost bound to the right of the first arm
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    // Iterate through the sorted arms to count non-overlapping arms
    for (int i = 1; i < n; i++) {
        // If the left bound of the current arm is greater than or equal to the rightmost bound
        if (as[i].l >= r) {
            ans++; // Increment the count of non-overlapping arms
            r = as[i].r; // Update the rightmost bound to the current arm's right bound
        }
    }
<<<<<<< HEAD

    // Print the total count of non-overlapping arms
    printf("%d\n", ans);

    free(as); // Free the allocated memory
=======
    
    // Print the total count of non-overlapping arms
    printf("%d\n", ans);
    
    // Free the allocated memory
    free(as);
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
