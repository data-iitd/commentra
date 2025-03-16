#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main() {
    int N, K;
    int L[MAX_N + 1];
    int path[MAX_N + 1];
    int Hash[MAX_N + 1];
    int ind = 0, count = 0, x = 1, t = -1, flag = 0;

    // Read the values of N and K from input
    scanf("%d %d", &N, &K);

    // Read the list L of integers from input
    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
    }

    // Insert -1 at the beginning of the list L
    L[0] = -1;

    // Initialize the path list with the first element 1
    path[0] = 1;

    // Initialize flag to indicate loop detection
    for (int i = 0; i <= N; i++) {
        Hash[i] = 0;
    }

    // Main loop to traverse the path
    for (int i = 0; i <= N; i++) {
        // Get the next element in the path
        int ne = L[x];

        // Check if the next element is already in the Hash
        if (Hash[ne]) {
            // Loop detected, set flag and record the start index
            flag = 1;
            t = Hash[ne];
            break;
        }

        // Append the next element to the path and update index
        path[ind + 1] = ne;
        ind++;

        // Update the Hash with the current index
        Hash[ne] = ind;

        // Move to the next element
        x = ne;
    }

    // Check if a loop is detected
    if (flag) {
        // Create a loop slice from the detected start index to the end
        int loop[MAX_N + 1];
        int loop_len = 0;
        for (int i = t; i <= N; i++) {
            loop[loop_len++] = path[i];
        }

        // If K is within the bounds of the path length, print the K-th element
        if (K < ind + 1) {
            printf("%d\n", path[K]);
        } else {
            // Adjust K for the loop length
            K = K - ind - 1;
            K = K % loop_len;
            // Print the K-th element of the loop
            printf("%d\n", loop[K]);
        }
    } else {
        // If no loop, print the (K-1)-th element of the path
        printf("%d\n", path[K - 1]);
    }

    return 0;
}
