#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjLists;
    int size;
} Graph;

Graph* createGraph(int size) {
    Graph* graph = malloc(sizeof(Graph));
    graph->size = size;
    graph->adjLists = malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->value = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

long long dfs(Graph* graph, int fro, int to, int f, int K) {
    long long caseNum = f;
    int colorNum = (f == K) ? (K - 1) : (K - 2);
    
    for (Node* u = graph->adjLists[fro]; u != NULL; u = u->next) {
        if (u->value == to) {
            continue;
        }
        long long pat = dfs(graph, u->value, fro, colorNum, K);
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
    
    Graph* graph = createGraph(N);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a - 1, b - 1);
    }
    
    long long ans = dfs(graph, 0, -1, K, K);
    printf("%lld\n", ans);
    
    // Free memory (not shown for brevity)
    // You should free the graph and its nodes here

    return 0;
}

// <END-OF-CODE>
