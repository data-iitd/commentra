#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store the last index of each node
struct Hash {
    int last;
};

// Define a structure to store the path
struct Path {
    int *path;
    int ind;
    int count;
};

// Function to detect loops
int detect_loop(int *L, int N, int K, struct Hash *Hash, struct Path *path) {
    int x = 1;
    int t = -1;
    int flag = 0;
    int i;

    // Initialize the path
    path->path = (int *)malloc(sizeof(int) * (N + 1));
    path->path[0] = -1;
    path->ind = 0;
    path->count = 0;

    // Initialize the hash table
    Hash = (struct Hash *)malloc(sizeof(struct Hash) * (N + 1));
    for (i = 0; i < N + 1; i++) {
        Hash[i].last = 0;
    }

    // Iterate through the nodes to detect loops
    for (i = 0; i < N + 1; i++) {
        int ne = L[x];
        if (Hash[ne].last) {
            flag = 1;
            t = Hash[ne].last;
            break;
        }
        path->path[path->ind] = ne;
        path->ind++;
        Hash[ne].last = path->ind;
        x = ne;
    }

    // Check if a loop was detected
    if (flag == 1) {
        int *loop = (int *)malloc(sizeof(int) * (path->ind - t));
        for (i = t; i < path->ind; i++) {
            loop[i - t] = path->path[i];
        }
        if (K < path->ind) {
            printf("%d\n", path->path[K]);
        } else {
            K = K - path->ind;
            K = K % (path->ind - t);
            printf("%d\n", loop[K]);
        }
    } else {
        printf("%d\n", path->path[K - 1]);
    }

    // Free the memory
    free(path->path);
    free(Hash);

    return 0;
}

int main() {
    int N, K;
    int *L;
    struct Hash *Hash;
    struct Path *path;

    // Read input values for N and K
    scanf("%d %d", &N, &K);

    // Read the list L of length N
    L = (int *)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i < N + 1; i++) {
        scanf("%d", &L[i]);
    }

    // Call the function to detect loops
    detect_loop(L, N, K, Hash, path);

    // Free the memory
    free(L);

    return 0;
}

