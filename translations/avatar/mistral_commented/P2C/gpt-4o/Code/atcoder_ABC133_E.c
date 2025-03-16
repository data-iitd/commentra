#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent the graph
typedef struct Graph {
    Node** adjLists;
    int numVertices;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Recursive DFS function to calculate the answer
long long dfs(Graph* graph, int fro, int to, int f, int K) {
    long long caseNum = (f == K) ? 1 : 0;
    int colorNum = (f == K) ? K - 1 : K - 2;

    Node* temp = graph->adjLists[fro];
    while (temp) {
        int u = temp->vertex;
        if (u == to) {
            temp = temp->next;
            continue;
        }

        long long pat = dfs(graph, u, fro, colorNum, K);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;
        colorNum--;
        temp = temp->next;
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
    // Free the graph and its nodes here

    return 0;
}

// <END-OF-CODE>
