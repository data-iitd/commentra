#include <stdio.h>
#include <stdlib.h>

int nextInt() {
    int num;
    scanf("%d", &num); // Read an integer from input.
    return num;
}

void nextInts(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt(); // Fill the array with integers.
    }
}

int main() {
    int n = nextInt(); // Read the number of elements n.
    int *a = (int *)malloc(n * sizeof(int)); // Allocate memory for n integers.
    nextInts(a, n); // Read n integers into the array a.

    int ans = 0; // Initialize ans to 0 to keep track of the number of segments.
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1; // Set l to i and r to i + 1.
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++; // Expand r as long as the condition holds.
        }
        ans++; // Increment ans after finding the segment.
        i = r; // Update i to r.
    }
    
    printf("%d\n", ans); // Output the number of segments ans.
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    free(a); // Free the allocated memory.
    return 0; // Return success.
}

// <END-OF-CODE>
