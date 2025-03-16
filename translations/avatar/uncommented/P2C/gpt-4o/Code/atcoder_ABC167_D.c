#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int L[MAX_N + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &L[i]);
    }
    L[0] = -1; // Insert -1 at the beginning

    int path[MAX_N + 1];
    int Hash[MAX_N + 1] = {0}; // Hash table initialized to 0
    int ind = 0, x = 1, t = -1, flag = 0;

    path[0] = 1; // Start path with 1
    for (int i = 0; i <= N; i++) {
        int ne = L[x];
        if (Hash[ne]) {
            flag = 1;
            t = Hash[ne];
            break;
        }
        path[ind + 1] = ne; // Store the next node in path
        ind++;
        Hash[ne] = ind; // Store the index of the node in Hash
        x = ne; // Move to the next node
    }

    if (flag) {
        // Loop detected
        int loop_size = ind - t + 1; // Size of the loop
        if (K < ind) {
            printf("%d\n", path[K]);
        } else {
            K = K - ind; // Reduce K by the length of the path
            K = K % loop_size; // Get the position in the loop
            printf("%d\n", path[t + K]);
        }
    } else {
        printf("%d\n", path[K - 1]);
    }

    return 0;
}
// <END-OF-CODE>
