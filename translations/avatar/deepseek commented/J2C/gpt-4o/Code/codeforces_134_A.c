#include <stdio.h> // Include standard input-output library

int main() {
    int n; // Variable to store the size of the array
    scanf("%d", &n); // Read the size of the array
    int arr[n]; // Create an array of size n
    int sum = 0; // Initialize sum to 0

    // Read n integers from the user and store them in the array arr, while updating the sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int c = 0; // Initialize count of valid elements to remove
    // Create an array to store the indices of valid elements
    int indices[n]; // Maximum possible valid indices is n

    // Iterate through the array arr to find elements that can be removed
    for (int i = 0; i < n; i++) {
        // Check if removing the current element keeps the average unchanged
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            indices[c++] = i + 1; // Store the index (plus one) and increment the count
        }
    }

    // Print the count of valid elements
    printf("%d\n", c);
    // Print the indices of these elements
    for (int i = 0; i < c; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n"); // Print a newline at the end

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
