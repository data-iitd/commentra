
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF_INT64 1000000000000000000LL
#define INF_INT32 1000000000
#define MOD 1000000007

typedef long long ll;

typedef struct {
    int node_count;
    int **adjacents;
    int **index_for_adjacents;
    ll *res;
    ll **dp;
    ll identity;
    ll (*operate)(ll, ll);
    ll (*operate_node)(ll, int);
} ReRootingSolver;

ReRootingSolver *new_ReRootingSolver(int node_count, int **edges, ll identity, ll (*operate)(ll, ll), ll (*operate_node)(ll, int)) {
    ReRootingSolver *s = (ReRootingSolver *)malloc(sizeof(ReRootingSolver));
    s->node_count = node_count;
    s->identity = identity;
    s->operate = operate;
    s->operate_node = operate_node;

    s->adjacents = (int **)malloc(sizeof(int *) * node_count);
    s->index_for_adjacents = (int **)malloc(sizeof(int *) * node_count);
    for (int i = 0; i < node_count; i++) {
        s->adjacents[i] = (int *)malloc(sizeof(int) * 0);
        s->index_for_adjacents[i] = (int *)malloc(sizeof(int) * 0);
    }
    for (int i = 0; i < node_count - 1; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        x--;
        y--;

        int *e = (int *)malloc(sizeof(int) * 2);
        e[0] = x;
        e[1] = y;
        s->index_for_adjacents[e[0]] = (int *)realloc(s->index_for_adjacents[e[0]], sizeof(int) * (s->node_count + 1));
        s->index_for_adjacents[e[0]][s->node_count] = s->node_count;
        s->index_for_adjacents[e[1]] = (int *)realloc(s->index_for_adjacents[e[1]], sizeof(int) * (s->node_count + 1));
        s->index_for_adjacents[e[1]][s->node_count] = s->node_count;
        s->adjacents[e[0]] = (int *)realloc(s->adjacents[e[0]], sizeof(int) * (s->node_count + 1));
        s->adjacents[e[0]][s->node_count] = e[1];
        s->adjacents[e[1]] = (int *)realloc(s->adjacents[e[1]], sizeof(int) * (s->node_count + 1));
        s->adjacents[e[1]][s->node_count] = e[0];
    }

    s->dp = (ll **)malloc(sizeof(ll *) * node_count);
    s->res = (ll *)malloc(sizeof(ll) * node_count);

    for (int i = 0; i < node_count; i++) {
        s->dp[i] = (ll *)malloc(sizeof(ll) * node_count);
    }

    if (s->node_count > 1) {
        s->Initialize();
    } else {
        s->res[0] = s->operate_node(s->identity, 0);
    }

    return s;
}

void Initialize(ReRootingSolver *s) {
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
        for (int i = 0; i < s->node_count; i++) {
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

        ll accum = s->identity;
        int parent_index = -1;
        for (int j = 0; j < s->node_count; j++) {
            if (s->adjacents[node][j] == parent) {
                parent_index = j;
                continue;
            }
            accum = s->operate(accum, s->dp[node][j]);
        }
        s->dp[parent][s->index_for_adjacents[node][parent_index]] = s->operate_node(accum, node);
    }

    // toLeaf
    for (int i = 0; i < s->node_count; i++) {
        int node = order[i];
        ll accum = s->identity;
        ll *accums_from_tail = (ll *)malloc(sizeof(ll) * s->node_count);
        accums_from_tail[s->node_count - 1] = s->identity;
        for (int j = s->node_count - 1; j >= 1; j--) {
            accums_from_tail[j - 1] = s->operate(s->dp[node][j], accums_from_tail[j]);
        }
        for (int j = 0; j < s->node_count; j++) {
            s->dp[s->adjacents[node][j]][s->index_for_adjacents[node][j]] = s->operate_node(s->operate(accum, accums_from_tail[j]), node);
            accum = s->operate(accum, s->dp[node][j]);
        }
        s->res[node] = s->operate_node(accum, node);
    }
}

ll Query(ReRootingSolver *s, int node) {
    return s->res[node];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int **edges = (int **)malloc(sizeof(int *) * (n - 1));
    for (int i = 0; i < n - 1; i++) {
        edges[i] = (int *)malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        edges[i][0]--;
        edges[i][1]--;
    }

    ll (*f)(ll, ll) = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f = (ll (*)(ll, ll))malloc(sizeof(ll (*)(ll, ll)));
    *f =