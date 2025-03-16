#include <stdio.h>
#include <stdlib.h>

void out(int x) {
    printf("%d\n", x);
}

int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

void sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N = getInt();
    int C = getInt();
    int K = getInt();
    int *t = (int *)malloc(N * sizeof(int)); // Allocate memory for time values

    // Read N time values from input
    for (int i = 0; i < N; i++) {
        t[i] = getInt(); // Store each time value in the array
    }

    sort(t, N); // Sort the time values in ascending order

    // Initialize variables for counting groups and tracking the end time
    int ans = 1; // Start with one group
    int cnt = 1; // Count of elements in the current group
    int end = t[0] + K; // Calculate the end time for the first group

    // Iterate through the sorted time values
    for (int i = 1; i < N; i++) {
        // Check if we can add the current time to the current group
        if (cnt < C && t[i] <= end) {
            cnt++; // Increment the count of the current group
        } else {
            // Start a new group since the current time exceeds the end time
            cnt = 1; // Reset the count for the new group
            end = t[i] + K; // Update the end time for the new group
            ans++; // Increment the group count
        }
    }

    out(ans); // Output the total number of groups formed
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    free(t); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
