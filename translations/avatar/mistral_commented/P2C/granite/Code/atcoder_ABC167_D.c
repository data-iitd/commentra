
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Taking the number of nodes 'N' and the number of edges 'K' as input
    int N, K;
    scanf("%d %d", &N, &K);

    // Initializing the list 'L' with the given number of edges
    int L[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    // Adding a special node with index -1 at the beginning of the list 'L'
    L[0] = -1;

    // Initializing an empty list 'path' to store the shortest path
    int path[N+1];
    path[0] = 1;

    // Initializing variables 'ind' and 'count'
    int ind = 0, count = 0;

    // Initializing variables 'x' and 't'
    int x = 1, t = -1;

    // Initializing a boolean variable 'flag'
    int flag = 0;

    // Creating an empty dictionary 'Hash' using defaultdict
    int Hash[N+1];
    for (int i = 0; i <= N; i++) {
        Hash[i] = 0;
    }

    // Traversing through all the nodes from 0 to 'N'
    for (int i = 0; i <= N; i++) {
        // Getting the next edge 'ne' from the current node 'x'
        int ne = L[x];

        // Checking if the current node 'ne' is already in the hash table 'Hash'
        if (Hash[ne]!= 0) {
            // Setting the boolean variable 'flag' to True and storing the index of the previous occurrence of the node 'ne' in 't'
            flag = 1;
            t = Hash[ne];
            break;
        }

        // Appending the next edge 'ne' to the list 'path'
        path[ind+1] = ne;

        // Incrementing the index 'ind' and storing it in the hash table 'Hash' with the key as the current node 'ne' and value as 'ind'
        ind++;
        Hash[ne] = ind;

        // Updating the current node 'x' to the next node 'ne'
        x = ne;
    }

    // Checking if there is a cycle in the graph
    if (flag == 1) {
        // Storing the list of nodes in the cycle 'loop'
        int loop[N];
        for (int i = t; i <= ind; i++) {
            loop[i-t] = path[i];
        }

        // Checking if the length of the path is less than 'K'
        if (ind+1 < K) {
            // Printing the 'K'th node in the path
            printf("%d\n", path[K]);
        }

        // If the length of the path is greater than or equal to 'K', then we need to find the 'K'th node in the cycle 'loop'
        else {
            // Updating the value of 'K' by subtracting the length of the path and taking the modulo with the length of the cycle 'loop'
            K = K - (ind+1);
            K = K % (ind-t+1);

            // Printing the 'K'th node in the cycle 'loop'
            printf("%d\n", loop[K]);
        }
    }

    // If there is no cycle in the graph, then we simply print the 'K'th node in the path
    else {
        // Printing the 'K'th node in the path
        printf("%d\n", path[K]);
    }

    return 0;
}
