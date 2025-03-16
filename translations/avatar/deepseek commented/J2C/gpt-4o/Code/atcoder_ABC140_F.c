#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int main() {
    int N;
    scanf("%d", &N); // Read the integer N from standard input
    int size = 1 << N; // Calculate the size of the array S, which is 2^N
    int *S = (int *)malloc(size * sizeof(int)); // Initialize an array S to store integers
    bool *spawned = (bool *)malloc(size * sizeof(bool)); // Initialize a boolean array to track spawned elements
    spawned[size - 1] = true; // Set the last element of spawned to true, indicating it's initially active

    // Read integers into the array S
    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }

    qsort(S, size, sizeof(int), compare); // Sort the array S
    int *active = (int *)malloc(size * sizeof(int)); // Initialize an array to keep track of active elements
    int active_size = 0; // Size of the active array
    active[active_size++] = S[size - 1]; // Add the largest element from S to the active array and mark it as spawned
    spawned[size - 1] = true;

    // Iterate N times
    for (int i = 0; i < N; i++) {
        qsort(active, active_size, sizeof(int), compare); // Sort the active array in reverse order
        int *activated = (int *)malloc(size * sizeof(int)); // Initialize an array to find new activated elements
        int activated_size = 0; // Size of the activated array
        int next = size - 1; // Initialize next to find new activated elements

        // Find new activated elements
        for (int j = 0; j < active_size; j++) {
            int slime = active[j];
            while (next >= 0 && (S[next] >= slime || spawned[next])) {
                next--;
            }
            if (next < 0) {
                printf("No\n"); // If no new activated elements are found, print "No"
                free(S);
                free(spawned);
                free(active);
                free(activated);
                return 0;
            }
            spawned[next] = true; // Mark the found element as spawned
            activated[activated_size++] = S[next]; // Add the found element to the activated array
        }
        for (int j = 0; j < activated_size; j++) {
            active[active_size++] = activated[j]; // Add the activated elements to the active array
        }
        free(activated); // Free the activated array
    }
    printf("Yes\n"); // If N iterations are successful, print "Yes"

    free(S);
    free(spawned);
    free(active);
    return 0;
}

// <END-OF-CODE>
