
#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for memory allocation and other functions

int main() { // Main function is the entry point of the program
    int n, k; // Declare the variables n and k to store the input values
    scanf("%d %d", &n, &k); // Read the input values n and k from the standard input
    int *logsLength = (int *)malloc(n * sizeof(int)); // Allocate memory for the logsLength array
    for (int i = 0; i < n; ++i) { // Iterate through the logsLength array
        scanf("%d", &logsLength[i]); // Read the next integer and store it in the logsLength array
    }
    int min = 1, max = 1000000000; // Initialize the binary search range
    while (min < max) { // Perform binary search
        int mid = (min + max) / 2; // Calculate the middle value
        if (nei(mid, logsLength, n, k)) { // Check if the current mid can be used to cut all logs
            max = mid; // Adjust the max value to search in the lower half
        } else {
            min = mid + 1; // Adjust the min value to search in the upper half
        }
    }
    printf("%d\n", min); // Print the result
    free(logsLength); // Free the memory allocated for the logsLength array
    return 0; // Return 0 to indicate successful execution
}

int nei(int mid, int *logsLength, int n, int k) { // nei function checks if the current mid can be used to cut all logs
    for (int i = 0; i < n; ++i) { // Iterate through each log
        k -= (logsLength[i] + mid - 1) / mid - 1; // Calculate the number of cuts needed for the current log
        if (k < 0) { // If k is negative, it means we cannot make the required cuts
            return 0; // Return 0 as the current mid cannot be used
        }
    }
    return 1; // Return 1 if all logs can be cut with the given number of k
}

