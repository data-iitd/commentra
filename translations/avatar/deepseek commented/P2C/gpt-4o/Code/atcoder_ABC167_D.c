#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int L[MAX_SIZE];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
    }
    L[0] = -1; // Insert -1 at the beginning of the list L

    int path[MAX_SIZE];
    path[0] = 1; // Initialize the path list with the first element 1
    int ind = 0; // Initialize index tracker to 0
    int count = 0; // Initialize count to 0
    int x = 1; // Initialize current position to 1
    int t = -1; // Initialize loop start index to -1
    int flag = 0; // Initialize flag to indicate loop detection
    int Hash[MAX_SIZE] = {0}; // Initialize a Hash array to keep track of indices of elements in path

    // Main loop to traverse the path
    for (int i = 0; i <= N; i++) {
        int ne = L[x]; // Get the next element in the path

        // Check if the next element is already in the Hash
        if (Hash[ne]) {
            // Loop detected, set flag and record the start index
            flag = 1;
            t = Hash[ne] - 1; // Adjust for 0-based index
            break;
        }

        // Append the next element to the path and update index
        path[ind++] = ne;

        // Update the Hash with the current index
        Hash[ne] = ind;

        // Move to the next element
        x = ne;
    }

    // Check if a loop is detected
    if (flag) {
        // Create a loop slice from the detected start index to the end
        int loop_size = ind - t - 1; // Length of the loop
        if (K < ind) {
            printf("%d\n", path[K]);
        } else {
            K = K - ind; // Adjust K for the loop length
            K = K % loop_size; // Get the position in the loop
            printf("%d\n", path[t + 1 + K]); // Print the K-th element of the loop
        }
    } else {
        // If no loop, print the (K-1)-th element of the path
        printf("%d\n", path[K - 1]);
    }

    return 0;
}

// <END-OF-CODE>
