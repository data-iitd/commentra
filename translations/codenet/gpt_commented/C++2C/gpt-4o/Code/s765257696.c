#include <stdio.h>

typedef long long ll; // Define a shorthand for long long type
const ll MOD = 1000000007LL; // Define a constant for modulo operations

int main() {
    // Optimize input/output operations
<<<<<<< HEAD
    // Note: C does not have sync_with_stdio or tie functions
=======
    // In C, we don't have sync_with_stdio, cin, or cout, so we use printf and scanf directly.
>>>>>>> 98c87cb78a (data updated)

    int n; // Variable to store the number of elements
    scanf("%d", &n); // Read the number of elements from input

    int p[n]; // Declare an array to hold the elements
    for (int i = 0; i < n; i++) 
        scanf("%d", &p[i]); // Read the elements into the array

    int ans = 0; // Initialize a counter for the number of valid triplets
    // Loop through the array to check for increasing or decreasing triplets
    for (int i = 0; i < n - 2; i++) {
        // Check if the current triplet is strictly decreasing
        if (p[i] > p[i+1] && p[i+1] > p[i+2]) 
            ans++; // Increment the counter for decreasing triplet

        // Check if the current triplet is strictly increasing
        if (p[i] < p[i+1] && p[i+1] < p[i+2]) 
            ans++; // Increment the counter for increasing triplet
    }

    printf("%d\n", ans); // Output the total count of valid triplets
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
