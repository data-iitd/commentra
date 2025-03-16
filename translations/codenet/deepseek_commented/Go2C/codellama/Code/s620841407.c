
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 100000

typedef int T;

typedef struct {
    int node_count;
    int *adjacents[MAX_N];
    int *index_for_adjacents[MAX_N];
    T *res;
    T *dp[MAX_N];
    T identity;
    T (*operate)(T, T);
    T (*operate_node)(T, int);
} ReRootingSolver;

ReRootingSolver *new_ReRootingSolver(int node_count, int **edges, int edge_count, T identity, T (*operate)(T, T), T (*operate_node)(T, int)) {
    ReRootingSolver *s = (ReRootingSolver *)malloc(sizeof(ReRootingSolver));
    s->node_count = node_count;
    s->identity = identity;
    s->operate = operate;
    s->operate_node = operate_node;

    for (int i = 0; i < node_count; i++) {
        s->adjacents[i] = (int *)malloc(sizeof(int) * edge_count);
        s->index_for_adjacents[i] = (int *)malloc(sizeof(int) * edge_count);
    }

    for (int i = 0; i < edge_count; i++) {
        int *e = edges[i];
        s->index_for_adjacents[e[0]][s->adjacents[e[0]][s->index_for_adjacents[e[0]][0]]] = i;
        s->index_for_adjacents[e[1]][s->adjacents[e[1]][s->index_for_adjacents[e[1]][0]]] = i;
        s->adjacents[e[0]][s->index_for_adjacents[e[0]][0]] = e[1];
        s->adjacents[e[1]][s->index_for_adjacents[e[1]][0]] = e[0];
    }

    for (int i = 0; i < node_count; i++) {
        s->dp[i] = (T *)malloc(sizeof(T) * edge_count);
    }

    s->res = (T *)malloc(sizeof(T) * node_count);

    if (node_count > 1) {
        s->initialize();
    } else {
        s->res[0] = s->operate_node(s->identity, 0);
    }

    return s;
}

void initialize(ReRootingSolver *s) {
    int *parents = (int *)malloc(sizeof(int) * s->node_count);
    int *order = (int *)malloc(sizeof(int) * s->node_count);

    // InitOrderedTree initializes the tree in a way that is useful for traversal
    int index = 0;
    int *stack = (int *)malloc(sizeof(int) * s->node_count);
    stack[0] = 0;
    parents[0] = -1;
    while (index < s->node_count) {
        int node = stack[index];
        stack[index] = -1;
        order[index] = node;
        index++;
        for (int i = 0; i < s->adjacents[node][0]; i++) {
            int adjacent = s->adjacents[node][i];
            if (adjacent == parents[node]) {
                continue;
            }
            stack[index] = adjacent;
            parents[adjacent] = node;
        }
    }

    // fromLeaf computes values starting from the leaves
    for (int i = s->node_count - 1; i >= 1; i--) {
        int node = order[i];
        int parent = parents[node];

        T accum = s->identity;
        int parent_index = -1;
        for (int j = 0; j < s->adjacents[node][0]; j++) {
            if (s->adjacents[node][j] == parent) {
                parent_index = j;
                continue;
            }
            accum = s->operate(accum, s->dp[node][j]);
        }
        s->dp[parent][s->index_for_adjacents[node][parent_index]] = s->operate_node(accum, node);
    }

    // toLeaf computes values propagating from leaves to the root
    for (int i = 0; i < s->node_count; i++) {
        int node = order[i];
        T accum = s->identity;
        T *accums_from_tail = (T *)malloc(sizeof(T) * s->adjacents[node][0]);
        accums_from_tail[s->adjacents[node][0] - 1] = s->identity;
        for (int j = s->adjacents[node][0] - 1; j >= 1; j--) {
            accums_from_tail[j - 1] = s->operate(s->dp[node][j], accums_from_tail[j]);
        }
        for (int j = 0; j < s->adjacents[node][0]; j++) {
            s->dp[s->adjacents[node][j]][s->index_for_adjacents[node][j]] = s->operate_node(s->operate(accum, accums_from_tail[j]), node);
            accum = s->operate(accum, s->dp[node][j]);
        }
        s->res[node] = s->operate_node(accum, node);
    }
}

T query(ReRootingSolver *s, int node) {
    return s->res[node];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **edges = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        edges[i] = (int *)malloc(sizeof(int) * 2);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;

        int *e = edges[i];
        e[0] = x;
        e[1] = y;
    }

    ReRootingSolver *s = new_ReRootingSolver(n, edges, m, 1, (T (*)(T, T))(&multiply), (T (*)(T, int))(&add));
    for (int i = 0; i < n; i++) {
        printf("%d\n", query(s, i) - 1);
    }

    return 0;
}

