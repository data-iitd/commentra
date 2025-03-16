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
    int adjacents[MAX_NODES][MAX_NODES];
    int indexForAdjacents[MAX_NODES][MAX_NODES];
    T res[MAX_NODES];
    T dp[MAX_NODES][MAX_NODES];
=======
    int** adjacents;
    int* indexForAdjacents;
    T* res;
    T** dp;
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

ReRootingSolver* newReRootingSolver(int nodeCount, int edges[][2], T identity, T (*operate)(T, T), T (*operateNode)(T, int)) {
    ReRootingSolver* s = (ReRootingSolver*)malloc(sizeof(ReRootingSolver));
    s->nodeCount = nodeCount;
    s->identity = identity;
    s->operate = operate;
    s->operateNode = operateNode;

<<<<<<< HEAD
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            s->adjacents[i][j] = -1; // Initialize adjacency list
            s->indexForAdjacents[i][j] = -1; // Initialize index mapping
        }
=======
    s->adjacents = (int**)malloc(nodeCount * sizeof(int*));
    s->indexForAdjacents = (int*)malloc(nodeCount * sizeof(int));
    s->dp = (T**)malloc(nodeCount * sizeof(T*));
    s->res = (T*)malloc(nodeCount * sizeof(T));

    for (int i = 0; i < nodeCount; i++) {
        s->adjacents[i] = (int*)malloc(MAX_NODES * sizeof(int));
        s->indexForAdjacents[i] = 0;
        s->dp[i] = (T*)malloc(MAX_NODES * sizeof(T));
>>>>>>> 98c87cb78a (data updated)
    }

    for (int i = 0; i < nodeCount - 1; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
<<<<<<< HEAD
        s->adjacents[x][y] = y;
        s->adjacents[y][x] = x;
    }

    memset(s->dp, 0, sizeof(s->dp));
    memset(s->res, 0, sizeof(s->res));

    if (nodeCount > 1) {
        // Initialize the solver
        // Call the Initialize function here
=======
        s->adjacents[x][s->indexForAdjacents[x]++] = y;
        s->adjacents[y][s->indexForAdjacents[y]++] = x;
    }

    if (nodeCount > 1) {
        // Initialize the solver
        // (Implementation of Initialize function goes here)
>>>>>>> 98c87cb78a (data updated)
    } else {
        s->res[0] = s->operateNode(s->identity, 0);
    }

    return s;
}

<<<<<<< HEAD
void initialize(ReRootingSolver* s) {
    int parents[MAX_NODES], order[MAX_NODES];
    int index = 0;
    int stack[MAX_NODES], stackSize = 0;

    stack[stackSize++] = 0; // Start from the root node
    parents[0] = -1; // Root has no parent

    while (stackSize > 0) {
        int node = stack[--stackSize];
        order[index++] = node; // Record the order of nodes
        for (int i = 0; i < MAX_NODES; i++) {
            if (s->adjacents[node][i] != -1) {
                int adjacent = s->adjacents[node][i];
                if (adjacent == parents[node]) continue; // Skip the parent node
                stack[stackSize++] = adjacent; // Add child to the stack
                parents[adjacent] = node; // Set parent
            }
        }
    }

    // Process nodes from leaves to root
    for (int i = index - 1; i >= 1; i--) {
        int node = order[i];
        int parent = parents[node];
        T accum = s->identity;
        int parentIndex = -1;

        for (int j = 0; j < MAX_NODES; j++) {
            if (s->adjacents[node][j] == parent) {
                parentIndex = j; // Find index of parent
                continue;
            }
            accum = s->operate(accum, s->dp[node][j]); // Accumulate results from children
        }
        s->dp[parent][s->indexForAdjacents[node][parentIndex]] = s->operateNode(accum, node); // Update DP for parent
    }

    // Process nodes from root to leaves
    for (int i = 0; i < index; i++) {
        int node = order[i];
        T accum = s->identity;
        T accumsFromTail[MAX_NODES];
        accumsFromTail[MAX_NODES - 1] = s->identity; // Initialize tail accumulator

        for (int j = MAX_NODES - 1; j >= 1; j--) {
            accumsFromTail[j - 1] = s->operate(s->dp[node][j], accumsFromTail[j]); // Accumulate results from tail
        }

        for (int j = 0; j < MAX_NODES; j++) {
            s->dp[s->adjacents[node][j]][s->indexForAdjacents[node][j]] = s->operateNode(s->operate(accum, accumsFromTail[j]), node);
            accum = s->operate(accum, s->dp[node][j]); // Update accumulator
        }
        s->res[node] = s->operateNode(accum, node); // Store result for the node
    }
}

T query(ReRootingSolver* s, int node) {
    return s->res[node]; // Return the result for the queried node
=======
T query(ReRootingSolver* s, int node) {
    return s->res[node];
}

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
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
<<<<<<< HEAD
    int edges[n - 1][2];
=======
    int edges[n-1][2];
>>>>>>> 98c87cb78a (data updated)

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        edges[i][0]--; // Convert to zero-based index
        edges[i][1]--;
    }

<<<<<<< HEAD
    ReRootingSolver* solver = newReRootingSolver(n, edges, 1, multiply, increment);
    for (int i = 0; i < n; i++) {
        printf("%lld\n", query(solver, i) - 1); // Output the result for each node
    }

    free(solver); // Free allocated memory
=======
    ReRootingSolver* s = newReRootingSolver(n, edges, 1, multiply, increment);
    for (int i = 0; i < n; i++) {
        printf("%lld\n", query(s, i) - 1); // Output the result for each node
    }

    freeReRootingSolver(s);
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

/* <END-OF-CODE> */
