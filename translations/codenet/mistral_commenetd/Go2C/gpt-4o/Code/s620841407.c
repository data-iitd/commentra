#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100000

typedef long long T;

typedef struct {
    int NodeCount;
    int **Adjacents;
    int **IndexForAdjacents;
    T *Res;
    T **DP;
    T Identity;
    T (*Operate)(T, T);
    T (*OperateNode)(T, int);
} ReRootingSolver;

T operate(T l, T r) {
    return (l * r) % MOD;
}

T operateNode(T v, int p) {
    return v + 1;
}

ReRootingSolver* NewReRootingSolver(int nodeCount, int edges[][2], int edgeCount, T identity, T (*operate)(T, T), T (*operateNode)(T, int)) {
    ReRootingSolver *s = (ReRootingSolver *)malloc(sizeof(ReRootingSolver));
    s->NodeCount = nodeCount;
    s->Identity = identity;
    s->Operate = operate;
    s->OperateNode = operateNode;

    s->Adjacents = (int **)malloc(nodeCount * sizeof(int *));
    s->IndexForAdjacents = (int **)malloc(nodeCount * sizeof(int *));
    for (int i = 0; i < nodeCount; i++) {
        s->Adjacents[i] = (int *)malloc(nodeCount * sizeof(int));
        s->IndexForAdjacents[i] = (int *)malloc(nodeCount * sizeof(int));
        memset(s->Adjacents[i], -1, nodeCount * sizeof(int));
        memset(s->IndexForAdjacents[i], -1, nodeCount * sizeof(int));
    }

    for (int i = 0; i < edgeCount; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        s->Adjacents[x][y] = y;
        s->Adjacents[y][x] = x;
        s->IndexForAdjacents[x][y] = y;
        s->IndexForAdjacents[y][x] = x;
    }

    s->DP = (T **)malloc(nodeCount * sizeof(T *));
    s->Res = (T *)malloc(nodeCount * sizeof(T));
    for (int i = 0; i < nodeCount; i++) {
        s->DP[i] = (T *)malloc(nodeCount * sizeof(T));
    }

    if (s->NodeCount > 1) {
        // Initialize the solver
        // Call the Initialize function here
    } else {
        s->Res[0] = s->OperateNode(s->Identity, 0);
    }

    return s;
}

void Query(ReRootingSolver *s, int node) {
    printf("%lld\n", s->Res[node]);
}

void Initialize(ReRootingSolver *s) {
    // Implementation of the Initialize function
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int edges[MAX_N][2];

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        edges[i][0]--; // Convert to 0-based index
        edges[i][1]--;
    }

    ReRootingSolver *s = NewReRootingSolver(n, edges, n - 1, 1, operate, operateNode);

    for (int i = 0; i < n; i++) {
        Query(s, i);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(s->Adjacents[i]);
        free(s->IndexForAdjacents[i]);
        free(s->DP[i]);
    }
    free(s->Adjacents);
    free(s->IndexForAdjacents);
    free(s->DP);
    free(s->Res);
    free(s);

    return 0;
}

// <END-OF-CODE>
