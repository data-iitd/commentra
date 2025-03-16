
#include <stdio.h> // Include necessary libraries
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int N; // Declare and initialize the integer N
    scanf("%d", &N);

    int size = 1 << N; // Calculate the size of the array S, which is 2^N
    int S[size]; // Declare an array S to store integers
    bool spawned[size]; // Declare a boolean array to track spawned elements
    spawned[size - 1] = true; // Set the last element of spawned to true, indicating it's initially active

    // Read integers into the array S
    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }

    qsort(S, size, sizeof(int)); // Sort the array S

    int active[size]; // Declare an array to keep track of active elements
    int active_count = 1; // Initialize the count of active elements
    active[0] = S[size - 1]; // Add the largest element from S to the active list and mark it as spawned
    spawned[size - 1] = true;

    // Iterate N times
    for (int i = 0; i < N; i++) {
        qsort(active, active_count, sizeof(int), greater); // Sort the active list in reverse order
        int next = size - 1; // Initialize next to find new activated elements
        int activated_count = 0; // Initialize the count of activated elements

        // Find new activated elements
        for (int j = 0; j < active_count; j++) {
            while (next >= 0 && (S[next] >= active[j] || spawned[next])) {
                next--;
            }
            if (next < 0) {
                printf("No\n"); // If no new activated elements are found, print "No"
                return 0;
            }
            spawned[next] = true; // Mark the found element as spawned
            active[active_count + activated_count] = S[next]; // Add the found element to the activated list
            activated_count++;
        }
        active_count += activated_count; // Update the count of active elements
    }
    printf("Yes\n"); // If N iterations are successful, print "Yes"

    return 0; // Return 0 to indicate successful execution
}
