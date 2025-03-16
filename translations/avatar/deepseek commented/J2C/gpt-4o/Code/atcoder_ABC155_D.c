#include <stdio.h>
#include <stdlib.h> // For qsort
#include <stdbool.h> // For boolean type

#define MOD 1000000007 // Define constant for modulo operation.
#define INF 1000000000000000000 // Define a large number as infinity.

long long n; // Declare variable for the size of the array.
long long k; // Declare variable for the target value.
long long *a; // Declare array to store the values.

int compare(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b); // Comparison function for qsort.
}

bool check(long long x) {
    long long tot = 0; // Initialize the total count.
    
    for (long long i = 0; i < n; i++) {
        long long now = a[i]; // Get the current element.
        long long l = 0, r = n; // Initialize the boundaries for binary search.
        
        if (now >= 0) { // If the current element is non-negative.
            while (l < r) { // Perform binary search.
                long long c = (l + r) / 2;
                if (now * a[c] < x) {
                    l = c + 1; // Adjust the left boundary.
                } else {
                    r = c; // Adjust the right boundary.
                }
            }
            tot += l; // Add the result to the total.
        } else { // If the current element is negative.
            while (l < r) { // Perform binary search.
                long long c = (l + r) / 2;
                if (now * a[c] >= x) {
                    l = c + 1; // Adjust the left boundary.
                } else {
                    r = c; // Adjust the right boundary.
                }
            }
            tot += (n - l); // Add the result to the total.
        }
        
        if (now * now < x) {
            tot--; // Adjust the total if necessary.
        }
    }
    
    return (tot / 2 < k); // Return true if the count is less than k.
}

int main() {
    scanf("%lld", &n); // Read the size of the array.
    scanf("%lld", &k); // Read the target value.
    a = (long long *)malloc(n * sizeof(long long)); // Initialize the array.
    
    for (long long i = 0; i < n; ++i) {
        scanf("%lld", &a[i]); // Read the elements of the array.
    }
    
    qsort(a, n, sizeof(long long), compare); // Sort the array.
    
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
    
    free(a); // Free the allocated memory.
    return 0;
}

// <END-OF-CODE>
