#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the absolute value of an integer
int abs(int n) {
    return n < 0 ? -n : n;
}

<<<<<<< HEAD
// Function to compare two integers (used for sorting)
=======
// Function to compare two integers for qsort
>>>>>>> 98c87cb78a (data updated)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

<<<<<<< HEAD
// Main function to solve the problem
void solve() {
=======
// Main function
int main() {
>>>>>>> 98c87cb78a (data updated)
    int n;
    // Read the number of elements
    scanf("%d", &n);
    
    // Allocate memory for the integer array
    int *as = (int *)malloc(n * sizeof(int));
    int *xs = (int *)malloc(n * sizeof(int));
    
    // Read the integer array
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        // Adjust each element by subtracting its index and adding 1
        xs[i] = as[i] - i + 1;
    }
    
    // Sort the adjusted values
    qsort(xs, n, sizeof(int), compare);
    
    // Find the median value from the sorted array
    int b = xs[n / 2];
    long long ans = 0; // Use long long to avoid overflow
    
    // Calculate the total distance from each element to the median
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    
    // Output the result
    printf("%lld\n", ans);
    
    // Free allocated memory
    free(as);
    free(xs);
<<<<<<< HEAD
}

// Main function
int main() {
    // Call the solve function to perform the main logic
    solve();
    return 0;
}

// Note: The input is expected to be provided in the format specified in the original Go code.
=======
    
    return 0;
}

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
