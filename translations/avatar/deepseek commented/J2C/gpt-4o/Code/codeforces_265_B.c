#include <stdio.h> // Importing standard input/output library
#include <stdlib.h> // Importing standard library for utility functions

int main() {
    int n; // Variable to store the size of the array
    scanf("%d", &n); // Read the size of the array
    int arr[n]; // Initialize the array of size n

    // Read n integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize ans with the value of the first element plus 1
    int ans = arr[0] + 1;

    // Iterate through the array and update ans
    for (int i = 1; i < n; i++) {
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }

    // Print the final value of ans
    printf("%d\n", ans);

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
