
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the path
typedef struct {
    int *path;
    int ind;
    int count;
    int x;
    int t;
    int flag;
    int *Hash;
} Path;

// Function to initialize the path
void initPath(Path *p) {
    p->path = (int *)malloc(sizeof(int) * 1000000);
    p->path[0] = -1;
    p->ind = 0;
    p->count = 0;
    p->x = 1;
    p->t = -1;
    p->flag = 0;
    p->Hash = (int *)malloc(sizeof(int) * 1000000);
    memset(p->Hash, 0, sizeof(int) * 1000000);
}

// Function to free the path
void freePath(Path *p) {
    free(p->path);
    free(p->Hash);
}

// Function to get the next element in the path
int getNext(Path *p) {
    int ne = p->path[p->x];
    if (p->Hash[ne]) {
        p->flag = 1;
        p->t = p->Hash[ne];
        return -1;
    }
    p->path[p->ind + 1] = ne;
    p->ind += 1;
    p->Hash[ne] = p->ind;
    p->x = ne;
    return ne;
}

// Function to print the K-th element of the path
void printKth(Path *p, int K) {
    if (p->flag) {
        int loop = p->t;
        K = K - p->count;
        K = K % (p->ind - loop);
        printf("%d\n", p->path[loop + K]);
    } else {
        printf("%d\n", p->path[K - 1]);
    }
}

int main() {
    // Read the values of N and K from input
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Read the list L of integers from input
    int L[1000000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }
    
    // Initialize the path
    Path p;
    initPath(&p);
    
    // Main loop to traverse the path
    for (int i = 0; i < N + 1; i++) {
        // Get the next element in the path
        int ne = getNext(&p);
        if (ne == -1) {
            break;
        }
    }
    
    // Print the K-th element of the path
    printKth(&p, K);
    
    // Free the path
    freePath(&p);
    
    return 0;
}

