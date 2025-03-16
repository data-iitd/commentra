#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node** adjList;
    int size;
} Graph;

int dfs(Graph* graph, int fro, int to, int K, int* visited) {
    int caseNum = K;
    int colorNum = K - 1;
    if (fro != to) {
        colorNum = K - 2;
    }

    visited[fro] = 1;

    Node* temp = graph->adjList[fro];
    while (temp != NULL) {
        int u = temp->vertex;
        if (u == to || visited[u]) {
            temp = temp->next;
            continue;
        }

        int pat = dfs(graph, u, fro, K, visited);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;
        colorNum--;
        temp = temp->next;
    }

    visited[fro] = 0;
    return caseNum;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Graph graph;
    graph.size = N;
    graph.adjList = (Node**)malloc(N * sizeof(Node*));
    for (int i = 0; i < N; i++) {
        graph.adjList[i] = NULL;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = b;
        newNode->next = graph.adjList[a];
        graph.adjList[a] = newNode;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = a;
        newNode->next = graph.adjList[b];
        graph.adjList[b] = newNode;
    }

    int* visited = (int*)calloc(N, sizeof(int));
    int ans = dfs(&graph, 0, -1, K, visited);
    printf("%d\n", ans);

    for (int i = 0; i < N; i++) {
        Node* temp = graph.adjList[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph.adjList);
    free(visited);

    return 0;
}
