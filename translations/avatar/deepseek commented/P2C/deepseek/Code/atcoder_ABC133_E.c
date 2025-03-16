#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef struct Node {
    int colorNum;
    int caseNum;
    struct Node** neighbors;
    int neighborCount;
} Node;

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->colorNum = 0;
    node->caseNum = 0;
    node->neighbors = NULL;
    node->neighborCount = 0;
    return node;
}

void addEdge(Node* graph[], int a, int b) {
    graph[a]->neighbors = (Node**)realloc(graph[a]->neighbors, (graph[a]->neighborCount + 1) * sizeof(Node*));
    graph[a]->neighbors[graph[a]->neighborCount++] = graph[b];
    graph[b]->neighbors = (Node**)realloc(graph[b]->neighbors, (graph[b]->neighborCount + 1) * sizeof(Node*));
    graph[b]->neighbors[graph[b]->neighborCount++] = graph[a];
}

int dfs(Node* node, Node* parent, int K) {
    int caseNum = K;
    int colorNum = K - 1;
    for (int i = 0; i < node->neighborCount; i++) {
        if (node->neighbors[i] == parent) continue;
        int pat = dfs(node->neighbors[i], node, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;
        colorNum--;
    }
    return caseNum;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Node* graph[N];
    for (int i = 0; i < N; i++) {
        graph[i] = createNode();
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a - 1, b - 1);
    }

    int ans = dfs(graph[0], NULL, K);
    printf("%d\n", ans);

    for (int i = 0; i < N; i++) {
        free(graph[i]);
    }

    return 0;
}
