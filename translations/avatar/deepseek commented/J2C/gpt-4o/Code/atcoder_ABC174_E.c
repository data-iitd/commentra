#include <stdio.h> // For standard input and output
#include <stdlib.h> // For dynamic memory allocation
#include <string.h> // For string manipulation

// Function to check if we can cut the logs with the given mid length
int canCut(int mid, int *logsLength, int n, int k) {
    for (int i = 0; i < n; i++) {
        k -= (logsLength[i] + mid - 1) / mid - 1; // Calculate the number of cuts needed
        if (k < 0) {
            return 0; // Return false if we cannot make the required cuts
        }
    }
    return 1; // Return true if all logs can be cut with the given number of k
}

int main() {
    int n, k; // Number of logs and number of cuts allowed
    scanf("%d %d", &n, &k); // Read the number of logs and cuts allowed

    int *logsLength = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for logs lengths
    for (int i = 0; i < n; i++) {
        scanf("%d", &logsLength[i]); // Read the lengths of the logs
    }

    int min = 1, max = 1000000000 + 1000; // Initialize the binary search range
    while (min < max) { // Perform binary search
        int mid = (min + max) / 2; // Calculate the middle value
        if (canCut(mid, logsLength, n, k)) { // Check if the current mid can be used to cut all logs
            max = mid; // Adjust the max value to search in the lower half
        } else {
            min = mid + 1; // Adjust the min value to search in the upper half
        }
    }

    printf("%d\n", min); // Print the result
    free(logsLength); // Free the allocated memory
    return 0; // Return success
}

// <END-OF-CODE>
