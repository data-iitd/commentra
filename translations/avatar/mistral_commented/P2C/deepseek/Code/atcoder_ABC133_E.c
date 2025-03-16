#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Define a structure for the adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int N;
    Node** adjList;
} Graph;

// Function to create a new graph
Graph* createGraph(int N) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->N = N;
    graph->adjList = (Node**)malloc(N * sizeof(Node*));
    for (int i = 0; i < N; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to recursively calculate the answer using Depth First Search
int dfs(Graph* graph, int fro, int to, int f, int K) {
    // Initialize case number and color number
    int caseNum = (f == K) ? 1 : 0;
    int colorNum = (f == K) ? K - 1 : K - 2;

    // Iterate through the neighbors of the current node
    Node* u = graph->adjList[fro];
    while (u != NULL) {
        // Skip the target node
        if (u->data == to) {
            u = u->next;
            continue;
        }

        // Recursively call dfs on the neighbor and update case number
        int pat = dfs(graph, u->data, fro, colorNum, K);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = (caseNum * pat) % MOD;
        colorNum -= 1;
        u = u->next;
    }

    // Return the final case number
    return caseNum;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // Create the graph
    Graph* graph = createGraph(N);

    // Read edges and add them to the graph
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a - 1, b - 1);
    }

    // Call the dfs function with initial values and print the result
    int ans = dfs(graph, 0, -1, K, K);
    printf("%d\n", ans);

    // Free the allocated memory
    for (int i = 0; i < N; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}
