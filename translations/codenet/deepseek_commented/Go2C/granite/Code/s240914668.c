
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements n.

    int *a = (int *)malloc(sizeof(int) * n); // Allocate memory for the array a.
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read n integers into the array a.
    }

    int ans = 0; // Initialize ans to 0 to keep track of the number of segments.
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1; // Set l to i and r to i+1.
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++; // Expand r as long as the condition holds.
        }
        ans++; // Increment ans after finding the segment.
        i = r; // Update i to r.
    }
    printf("%d\n", ans); // Output the number of segments ans.

    free(a); // Free the memory allocated for the array a.
    return 0;
}
