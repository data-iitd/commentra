#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Read the size of the array
    int arr[n]; // Create an array of size n
    int sum = 0; // Initialize sum to 0

    // Read n integers from the user and store them in the array arr, while updating the sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int c = 0; // Initialize count of valid elements to remove
    char buffer[1000]; // Buffer to build the output string
    int bufferIndex = 0; // Index for the buffer

    // Iterate through the array arr to find elements that can be removed
    for (int i = 0; i < n; i++) {
        // Check if removing the current element keeps the average unchanged
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++; // Increment the count
            bufferIndex += sprintf(buffer + bufferIndex, "%d ", i + 1); // Append the index (plus one) to the buffer
        }
    }

    // Print the count of valid elements and the indices of these elements
    printf("%d\n", c);
    printf("%s\n", buffer);

    return 0;
}
