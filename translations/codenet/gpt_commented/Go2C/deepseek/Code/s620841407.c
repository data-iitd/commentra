#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 (int64_t)1 << 60
#define INF_BIT60 1 << 60
#define INF_INT32 (int32_t)1 << 30
#define INF_BIT30 1 << 30
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef int32_t int32;
typedef int64_t int64;

typedef struct {
    int nodeCount;
    int **adjacents;
    int **indexForAdjacents;
    int *res;
    int64_t **dp;
    int64_t identity;
    int64_t (*operate)(int64_t, int64_t);
    int64_t (*operateNode)(int64_t, int);
} ReRootingSolver;

ReRootingSolver* newReRootingSolver(int nodeCount, int edges[][2], int edgeCount, int64_t identity, int64_t (*operate)(int64_t, int64_t), int64_t (*operateNode)(int64_t, int));
void initialize(ReRootingSolver *s);
int64_t query(ReRootingSolver *s, int node);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int edges[n-1][2];
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        edges[i][0]--;
        edges[i][1]--;
    }

    int64_t (*operate)(int64_t, int64_t) = [](int64_t l, int64_t r) { return l * r % m; };
    int64_t (*operateNode)(int64_t, int) = [](int64_t v, int p) { return v + 1; };
    ReRootingSolver *s = newReRootingSolver(n, edges, n-1, 1, operate, operateNode);

    for (int i = 0; i < n; i++) {
        printf("%lld\n", query(s, i) - 1);
    }

    return 0;
}

ReRootingSolver* newReRootingSolver(int nodeCount, int edges[][2], int edgeCount, int64_t identity, int64_t (*operate)(int64_t, int64_t), int64_t (*operateNode)(int64_t, int)) {
    ReRootingSolver *s = (ReRootingSolver *)malloc(sizeof(ReRootingSolver));
    s->nodeCount = nodeCount;
    s->identity = identity;
    s->operate = operate;
    s->operateNode = operateNode;

    s->adjacents = (int **)malloc(nodeCount * sizeof(int *));
    s->indexForAdjacents = (int **)malloc(nodeCount * sizeof(int *));
    for (int i = 0; i < nodeCount; i++) {
        s->adjacents[i] = (int *)malloc(nodeCount * sizeof(int));
        s->indexForAdjacents[i] = (int *)malloc(nodeCount * sizeof(int));
    }

    for (int i = 0; i < edgeCount; i++) {
        int x = edges[i][0], y = edges[i][1];
        s->indexForAdjacents[x][s->adjacents[y]++] = i;
        s->indexForAdjacents[y][s->adjacents[x]++] = i;
        s->adjacents[x][s->adjacents[x]++] = y;
        s->adjacents[y][s->adjacents[y]++] = x;
    }

    s->dp = (int64_t **)malloc(nodeCount * sizeof(int64_t *));
    s->res = (int *)malloc(nodeCount * sizeof(int));
    for (int i = 0; i < nodeCount; i++) {
        s->dp[i] = (int64_t *)malloc(s->adjacents[i] * sizeof(int64_t));
    }

    if (nodeCount > 1) {
        initialize(s);
    } else {
        s->res[0] = s->operateNode(s->identity, 0);
    }

    return s;
}

void initialize(ReRootingSolver *s) {
    int parents[s->nodeCount], order[s->nodeCount];
    int index = 0;
    int stack[s->nodeCount];
    stack[0] = 0;
    parents[0] = -1;
    while (index < s->nodeCount) {
        int node = stack[index];
        order[index] = node;
        index++;
        for (int i = 0; i < s->adjacents[node]; i++) {
            int adjacent = s->adjacents[node][i];
            if (adjacent == parents[node]) continue;
            stack[index] = adjacent;
            parents[adjacent] = node;
        }
    }

    for (int i = s->nodeCount - 1; i >= 1; i--) {
        int node = order[i];
        int parent = parents[node];
        int64_t accum = s->identity;
        int parentIndex = -1;
        for (int j = 0; j < s->adjacents[node]; j++) {
            if (s->adjacents[node][j] == parent) {
                parentIndex = j;
                continue;
            }
            accum = s->operate(accum, s->dp[node][j]);
        }
        s->dp[parent][s->indexForAdjacents[node][parentIndex]] = s->operateNode(accum, node);
    }

    for (int i = 0; i < s->nodeCount; i++) {
        int64_t accum = s->identity;
        int64_t accumsFromTail[s->adjacents[order[i]]];
        accumsFromTail[s->adjacents[order[i]] - 1] = s->identity;
        for (int j = s->adjacents[order[i]] - 1; j >= 1; j--) {
            accumsFromTail[j - 1] = s->operate(s->dp[order[i]][j], accumsFromTail[j]);
        }
        for (int j = 0; j < s->adjacents[order[i]]; j++) {
            s->dp[s->adjacents[order[i]][j]][s->indexForAdjacents[order[i]][j]] = s->operateNode(s->operate(accum, accumsFromTail[j]), order[i]);
            accum = s->operate(accum, s->dp[order[i]][j]);
        }
        s->res[order[i]] = s->operateNode(accum, order[i]);
    }
}

int64_t query(ReRootingSolver *s, int node) {
    return s->res[node];
}
