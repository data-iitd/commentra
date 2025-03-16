
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000007

typedef long long ll;

typedef struct {
    int *adjacents;
    int *index_for_adjacents;
    int node_count;
    int *res;
    int **dp;
    int identity;
    int (*operate)(int, int);
    int (*operate_node)(int, int);
} ReRootingSolver;

ReRootingSolver *new_re_rooting_solver(int node_count, int *edges, int edge_count, int identity, int (*operate)(int, int), int (*operate_node)(int, int)) {
    ReRootingSolver *s = (ReRootingSolver *)malloc(sizeof(ReRootingSolver));
    s->node_count = node_count;
    s->identity = identity;
    s->operate = operate;
    s->operate_node = operate_node;

    s->adjacents = (int *)malloc(sizeof(int) * node_count);
    s->index_for_adjacents = (int *)malloc(sizeof(int) * node_count);
    for (int i = 0; i < node_count; i++) {
        s->adjacents[i] = (int *)malloc(sizeof(int) * edge_count);
        s->index_for_adjacents[i] = (int *)malloc(sizeof(int) * edge_count);
    }
    for (int i = 0; i < edge_count; i++) {
        int x = edges[i * 2];
        int y = edges[i * 2 + 1];
        x--;
        y--;

        s->index_for_adjacents[x][s->adjacents[x][s->index_for_adjacents[x][0]]] = s->adjacents[y][s->index_for_adjacents[y][0]];
        s->index_for_adjacents[x][s->adjacents[x][s->index_for_adjacents[x][0]]] = s->adjacents[y][s->index_for_adjacents[y][0]];
        s->adjacents[x][s->index_for_adjacents[x][0]] = y;
        s->adjacents[y][s->index_for_adjacents[y][0]] = x;
    }

    s->dp = (int **)malloc(sizeof(int *) * node_count);
    s->res = (int *)malloc(sizeof(int) * node_count);
    for (int i = 0; i < node_count; i++) {
        s->dp[i] = (int *)malloc(sizeof(int) * edge_count);
    }

    if (node_count > 1) {
        s->initialize(s);
    } else {
        s->res[0] = s->operate_node(s->identity, 0);
    }

    return s;
}

void initialize(ReRootingSolver *s) {
    int *parents = (int *)malloc(sizeof(int) * s->node_count);
    int *order = (int *)malloc(sizeof(int) * s->node_count);

    // InitOrderedTree
    int index = 0;
    int *stack = (int *)malloc(sizeof(int) * s->node_count);
    stack[0] = 0;
    parents[0] = -1;
    while (index < s->node_count) {
        int node = stack[index];
        index++;
        order[index - 1] = node;
        for (int i = 0; i < s->adjacents[node][0]; i++) {
            int adjacent = s->adjacents[node][i];
            if (adjacent == parents[node]) {
                continue;
            }
            stack[index] = adjacent;
            parents[adjacent] = node;
        }
    }

    // fromLeaf
    for (int i = s->node_count - 1; i >= 1; i--) {
        int node = order[i];
        int parent = parents[node];

        int accum = s->identity;
        int parent_index = -1;
        for (int j = 0; j < s->adjacents[node][0]; j++) {
            if (s->adjacents[node][j] == parent) {
                parent_index = j;
                continue;
            }
            accum = s->operate(accum, s->dp[node][j]);
        }
        s->dp[parent][s->index_for_adjacents[node][parent_index]] = s->operate_node(accum, node);
        accum = s->operate(accum, s->dp[node][j]);
        s->dp[node][j] = accum;
    }

    // toLeaf
    for (int i = 0; i < s->node_count; i++) {
        int node = order[i];
        int accum = s->identity;
        int *accums_from_tail = (int *)malloc(sizeof(int) * s->adjacents[node][0]);
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

int query(ReRootingSolver *s, int node) {
    return s->res[node];
}

int operate(int l, int r) {
    return (l * r) % INF;
}

int operate_node(int v, int p) {
    return v + 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *edges = (int *)malloc(sizeof(int) * n * 2);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &edges[i]);
    }

    ReRootingSolver *s = new_re_rooting_solver(n, edges, n - 1, 1, operate, operate_node);

    // Query the product of subtrees for all nodes and print the result
    for (int i = 0; i < n; i++) {
        printf("%d\n", s->query(s, i) - 1);
    }

    return 0;
}

