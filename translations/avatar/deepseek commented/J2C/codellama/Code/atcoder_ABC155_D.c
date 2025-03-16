#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define mod (long) 1e9 + 7 // Define constant for modulo operation.
#define DX -1, 0, 1, 0 // Define directions for movement.
#define DY 0, -1, 0, 1

int n; // Declare variable for the size of the array.
long k; // Declare variable for the target value.
long a[100000]; // Declare array to store the values.

int check(long x) {
    long tot = 0; // Initialize the total count.
    
    for (int i = 0; i < n; i++) {
        long now = a[i]; // Get the current element.
        int l = 0, r = n; // Initialize the boundaries for binary search.
        
        if (now >= 0) { // If the current element is non-negative.
            while (l < r) { // Perform binary search.
                int c = (l + r) / 2;
                if (now * a[c] < x) {
                    l = c + 1; // Adjust the left boundary.
                } else {
                    r = c; // Adjust the right boundary.
                }
            }
            tot += l; // Add the result to the total.
        } else { // If the current element is negative.
            while (l < r) { // Perform binary search.
                int c = (l + r) / 2;
                if (now * a[c] >= x) {
                    l = c + 1; // Adjust the left boundary.
                } else {
                    r = c; // Adjust the right boundary.
                }
            }
            tot += (n - l); // Add the result to the total.
        }
        
        if ((long) a[i] * a[i] < x) {
            tot--; // Adjust the total if necessary.
        }
    }
    
    if (tot / 2 < k) {
        return 1; // Return true if the count is less than k.
    } else {
        return 0; // Return false otherwise.
    }
}

int main() {
    scanf("%d", &n); // Read the size of the array.
    scanf("%ld", &k); // Read the target value.
    
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]); // Read the elements of the array.
    }
    
    qsort(a, n, sizeof(long), cmp); // Sort the array.
    
    long INF = (long) (1e18) + 1; // Define a large number as infinity.
    long l = -INF; // Initialize the left boundary of the search.
    long r = INF; // Initialize the right boundary of the search.
    
    while (l + 1 < r) { // Perform binary search.
        long c = (l + r) / 2; // Calculate the middle point.
        if (check(c)) {
            l = c; // Adjust the left boundary.
        } else {
            r = c; // Adjust the right boundary.
        }
    }
    
    printf("%ld\n", l); // Print the result.
    
    return 0;
}

int cmp(const void *a, const void *b) {
    return *(long *) a - *(long *) b; // Compare the elements.
}

