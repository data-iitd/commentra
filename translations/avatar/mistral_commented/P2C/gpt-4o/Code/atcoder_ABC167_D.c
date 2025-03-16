#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100000

// Function to find the K-th node in the path or cycle
int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int L[MAX_NODES + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
    }
    L[0] = -1; // Adding a special node with index -1 at the beginning

    int path[MAX_NODES + 1];
    path[0] = 1; // Starting from node 1

    int ind = 0;
    int count = 0;
    int x = 1;
    int t = -1;
    int flag = 0; // Boolean variable to check for cycles

    int Hash[MAX_NODES + 1] = {0}; // Hash table initialized to 0

    for (int i = 0; i <= N; i++) {
        int ne = L[x];

        if (Hash[ne] != 0) {
            flag = 1; // Cycle detected
            t = Hash[ne];
            break;
        }

        path[ind + 1] = ne; // Append the next edge to the path
        ind++;
        Hash[ne] = ind; // Store the index of the current node
        x = ne; // Update the current node
    }

    if (flag) {
        // Cycle detected
        int loop_size = ind - t + 1; // Size of the loop
        if (ind < K) {
            printf("%d\n", path[K]); // Print K-th node in the path
        } else {
            K = K - ind; // Update K
            K = K % loop_size; // Find the position in the loop
            if (K == 0) K = loop_size; // Adjust if K is 0
            printf("%d\n", path[t + K - 1]); // Print K-th node in the loop
        }
    } else {
        // No cycle detected
        printf("%d\n", path[K - 1]); // Print K-th node in the path
    }

    return 0;
}
