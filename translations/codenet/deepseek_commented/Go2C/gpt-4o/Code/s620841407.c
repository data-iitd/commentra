#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007
#define MAX_NODES 100000

typedef long long T;

typedef struct {
    int nodeCount;
<<<<<<< HEAD
    int** adjacents;
    int** indexForAdjacents;
    T* res;
    T** dp;
=======
    int adjacents[MAX_NODES][MAX_NODES];
    int indexForAdjacents[MAX_NODES][MAX_NODES];
    T res[MAX_NODES];
    T dp[MAX_NODES][MAX_NODES];
>>>>>>> 98c87cb78a (data updated)
    T identity;
    T (*operate)(T, T);
    T (*operateNode)(T, int);
} ReRootingSolver;

T multiply(T x, T y) {
    return (x * y) % MOD;
}

T increment(T v, int p) {
    return v + 1;
}

<<<<<<< HEAD
ReRootingSolver* newReRootingSolver(int nodeCount, int edges[][2], int edgeCount, T identity, T (*operate)(T, T), T (*operateNode)(T, int)) {
=======
ReRootingSolver* newReRootingSolver(int nodeCount, int edges[][2], T identity, T (*operate)(T, T), T (*operateNode)(T, int)) {
>>>>>>> 98c87cb78a (data updated)
    ReRootingSolver* s = (ReRootingSolver*)malloc(sizeof(ReRootingSolver));
    s->nodeCount = nodeCount;
    s->identity = identity;
    s->operate = operate;
    s->operateNode = operateNode;

<<<<<<< HEAD
    s->adjacents = (int**)malloc(nodeCount * sizeof(int*));
    s->indexForAdjacents = (int**)malloc(nodeCount * sizeof(int*));
    for (int i = 0; i < nodeCount; i++) {
        s->adjacents[i] = (int*)malloc(MAX_NODES * sizeof(int));
        s->indexForAdjacents[i] = (int*)malloc(MAX_NODES * sizeof(int));
        memset(s->indexForAdjacents[i], -1, MAX_NODES * sizeof(int));
    }

    for (int i = 0; i < edgeCount; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        s->adjacents[x][s->indexForAdjacents[x][0]++] = y;
        s->adjacents[y][s->indexForAdjacents[y][0]++] = x;
    }

    s->dp = (T**)malloc(nodeCount * sizeof(T*));
    s->res = (T*)malloc(nodeCount * sizeof(T));
    for (int i = 0; i < nodeCount; i++) {
        s->dp[i] = (T*)malloc(MAX_NODES * sizeof(T));
    }

    if (nodeCount > 1) {
        // Initialize the solver
        // Call the Initialize function here (not implemented in this snippet)
=======
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            s->adjacents[i][j] = -1; // Initialize adjacency list
            s->indexForAdjacents[i][j] = -1; // Initialize index list
        }
    }

    for (int i = 0; i < nodeCount - 1; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        s->adjacents[x][y] = y;
        s->adjacents[y][x] = x;
    }

    memset(s->dp, 0, sizeof(s->dp));
    memset(s->res, 0, sizeof(s->res));

    if (s->nodeCount > 1) {
        // Initialize the solver
        // Call the Initialize function here
>>>>>>> 98c87cb78a (data updated)
    } else {
        s->res[0] = s->operateNode(s->identity, 0);
    }

    return s;
}

<<<<<<< HEAD
void freeReRootingSolver(ReRootingSolver* s) {
    for (int i = 0; i < s->nodeCount; i++) {
        free(s->adjacents[i]);
        free(s->dp[i]);
    }
    free(s->adjacents);
    free(s->indexForAdjacents);
    free(s->dp);
    free(s->res);
    free(s);
=======
T query(ReRootingSolver* s, int node) {
    return s->res[node];
}

void initialize(ReRootingSolver* s) {
    // Implement the initialization logic similar to the Go code
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int edges[MAX_NODES][2];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        edges[i][0]--; // Convert to 0-based index
        edges[i][1]--;
    }

<<<<<<< HEAD
    ReRootingSolver* solver = newReRootingSolver(n, edges, n - 1, 1, multiply, increment);
    
    for (int i = 0; i < n; i++) {
        printf("%lld\n", solver->res[i] - 1);
    }

    freeReRootingSolver(solver);
=======
    ReRootingSolver* solver = newReRootingSolver(n, edges, 1, multiply, increment);
    for (int i = 0; i < n; i++) {
        printf("%lld\n", query(solver, i) - 1);
    }

    free(solver);
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

/* <END-OF-CODE> */
