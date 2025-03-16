#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int mod = (int) 1e9 + 7; // Define constant for modulo operation.
int DX[] = { -1, 0, 1, 0 }, DY[] = { 0, -1, 0, 1 }; // Define directions for movement.

int n; // Declare variable for the size of the array.
long long k; // Declare variable for the target value.
long long a[]; // Declare array to store the values.

int main() {
    scanf("%d", &n); // Read the size of the array.
    scanf("%lld", &k); // Read the target value.
    a = (long long *) malloc(n * sizeof(long long)); // Initialize the array.
    
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]); // Read the elements of the array.
    }
    
    qsort(a, n, sizeof(long long), cmpfunc); // Sort the array.
    
    long long INF = (long long) (1e18) + 1; // Define a large number as infinity.
    long long l = -INF; // Initialize the left boundary of the search.
    long long r = INF; // Initialize the right boundary of the search.
    
    while (l + 1 < r) { // Perform binary search.
        long long c = (l + r) / 2; // Calculate the middle point.
        if (check(c)) {
            l = c; // Adjust the left boundary.
        } else {
            r = c; // Adjust the right boundary.
        }
    }
    
    printf("%lld\n", l); // Print the result.
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return ( *(long long *) a - *(long long *) b );
}

bool check(long long x) {
    long long tot = 0; // Initialize the total count.
    
    for (int i = 0; i < n; i++) {
        long long now = a[i]; // Get the current element.
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
        
        if ((long long) a[i] * a[i] < x) {
            tot--; // Adjust the total if necessary.
        }
    }
    
    if (tot / 2 < k) {
        return true; // Return true if the count is less than k.
    } else {
        return false; // Return false otherwise.
    }
}

