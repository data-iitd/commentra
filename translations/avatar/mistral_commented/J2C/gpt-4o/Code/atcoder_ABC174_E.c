#include <stdio.h>
#include <stdlib.h>

// Function to check if the number of days needed to cut the logs is greater than or equal to k
int nei(int mid, int *logsLength, int n, int k) {
    int daysNeeded = 0; // Initialize the days needed to zero

    // Iterate through all the logs and calculate the days needed to cut them
    for (int i = 0; i < n; i++) {
        daysNeeded += (logsLength[i] + mid - 1) / mid; // Calculate the days needed to cut the current log
    }

    return daysNeeded <= k; // Return true if days needed is less than or equal to k
}

// Function to perform binary search to find the minimum day
int binarySearch(int *logsLength, int n, int k) {
    int min = 1, max = 1000000000 + 1000; // Initialize the minimum and maximum possible days

    // Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
    while (min < max) {
        int mid = (min + max) / 2; // Calculate the middle day
        if (nei(mid, logsLength, n, k)) // If the number of days needed to cut the logs is less than or equal to k
            max = mid; // Narrow down the search space to the left
        else
            min = mid + 1; // Narrow down the search space to the right
    }

    return min; // Return the minimum day as the result
}

// Main function to start the program
int main() {
    int n, k; // Variables to store the number of logs and the number of days
    scanf("%d %d", &n, &k); // Read the number of logs and the number of days

    int *logsLength = (int *)malloc(n * sizeof(int)); // Allocate memory for the logs length array
    for (int i = 0; i < n; i++) {
        scanf("%d", &logsLength[i]); // Read the length of each log
    }

    int result = binarySearch(logsLength, n, k); // Call the binary search function
    printf("%d\n", result); // Print the minimum day as the output

    free(logsLength); // Free the allocated memory
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
