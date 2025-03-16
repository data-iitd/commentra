#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main() {
    int N, K;
    int L[MAX_N + 1];
    int path[MAX_N + 1];
    int Hash[MAX_N + 1];
    int ind = 0, count = 0, x = 1, t = -1;
    int flag = 0;

    // Taking the number of nodes 'N' and the number of edges 'K' as input
    scanf("%d %d", &N, &K);

    // Initializing the list 'L' with the given number of edges
    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
    }

    // Adding a special node with index -1 at the beginning of the list 'L'
    L[0] = -1;

    // Initializing the path list with the first node
    path[0] = 1;

    // Initializing the hash table
    for (int i = 0; i <= N; i++) {
        Hash[i] = 0;
    }

    // Traversing through all the nodes from 0 to 'N'
    while (1) {
        // Getting the next edge 'ne' from the current node 'x'
        int ne = L[x];

        // Checking if the current node 'ne' is already in the hash table 'Hash'
        if (Hash[ne] != 0) {
            // Setting the boolean variable 'flag' to True and storing the index of the previous occurrence of the node 'ne' in 't'
            flag = 1;
            t = Hash[ne];
            break;
        }

        // Appending the next edge 'ne' to the path list
        path[++ind] = ne;

        // Storing the index of the current node 'ne' in the hash table 'Hash'
        Hash[ne] = ind;

        // Updating the current node 'x' to the next node 'ne'
        x = ne;
    }

    // Checking if there is a cycle in the graph
    if (flag == 1) {
        // Storing the list of nodes in the cycle 'loop'
        int loop[MAX_N + 1];
        for (int i = t; i <= ind; i++) {
            loop[count++] = path[i];
        }

        // Checking if the length of the path is less than 'K'
        if (ind < K) {
            // Printing the 'K'th node in the path
            printf("%d\n", path[K]);
        } else {
            // Updating the value of 'K' by subtracting the length of the path and taking the modulo with the length of the cycle 'loop'
            K = K - ind;
            K = K % count;

            // Printing the 'K'th node in the cycle 'loop'
            printf("%d\n", loop[K]);
        }
    } else {
        // Printing the 'K'th node in the path
        printf("%d\n", path[K - 1]);
    }

    return 0;
}
