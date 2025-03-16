#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000  // Define a maximum size for the list

int main() {
    int N, K;
    scanf("%d %d", &N, &K);  // Read input values for N and K

    int L[MAX_N + 1];  // Array to hold the list L
    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);  // Read the list L of length N
    }
    L[0] = -1;  // Insert a placeholder value at the beginning of the list

    int path[MAX_N + 1];  // Array to store the path
    int ind = 0;  // Index to track the position in the path
    int count = 0;  // Not used in the current logic
    int x = 1;  // Current node starting from 1
    int t = -1;  // To store the index of the start of the loop if found
    int flag = 0;  // Flag to indicate if a loop is detected
    int Hash[MAX_N + 1] = {0};  // Array to store the last index of each node

    // Iterate through the nodes to detect loops
    for (int i = 0; i <= N; i++) {
        int ne = L[x];  // Get the next node from the list L
        // Check if the next node has been visited before
        if (Hash[ne]) {
            flag = 1;  // Set the flag to indicate a loop is found
            t = Hash[ne];  // Store the index where the loop starts
            break;  // Exit the loop since a cycle is detected
        }
        // Append the next node to the path
        path[ind++] = ne;  // Store the next node in the path
        Hash[ne] = ind;  // Update the last index of the current node
        x = ne;  // Move to the next node
    }

    // Check if a loop was detected
    if (flag) {
        int loop[MAX_N + 1];  // Array to store the loop
        int loop_size = ind - t;  // Size of the loop
        for (int i = t; i < ind; i++) {
            loop[i - t] = path[i];  // Extract the loop from the path
        }
        // Check if K is within the length of the path
        if (K < ind) {
            printf("%d\n", path[K]);  // Print the K-th node in the path
        } else {
            K = K - ind;  // Adjust K to account for the full path length
            K = K % loop_size;  // Get the position within the loop
            printf("%d\n", loop[K]);  // Print the K-th node in the loop
        }
    } else {
        printf("%d\n", path[K - 1]);  // If no loop, print the K-th node in the path
    }

    return 0;
}
