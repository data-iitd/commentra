
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Define the structure for the adjacency list
typedef struct {
    int to;
    struct node *next;
} node;

// Define the structure for the graph
typedef struct {
    int V;
    node *adj[100001];
} graph;

// Function to create a new node
node *newNode(int to) {
    node *temp = (node *)malloc(sizeof(node));
    temp->to = to;
    temp->next = NULL;
    return temp;
}

// Function to add an edge to the graph
void addEdge(graph *g, int u, int v) {
    node *temp = newNode(v);
    temp->next = g->adj[u];
    g->adj[u] = temp;
}

// Function to perform Depth First Search and calculate distances
void dfs(graph *g, int s, int *dist) {
    bool visited[100001];
    for (int i = 0; i < g->V; i++) visited[i] = false;
    dist[s] = 0;
    visited[s] = true;
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->to = s;
    q->next = NULL;
    struct node *front = q;
    struct node * rear = q;
    while (front!= NULL) {
        int u = front->to;
        struct node *p = g->adj[u];
        while (p!= NULL) {
            if (visited[p->to] == false) {
                dist[p->to] = dist[u] + 1;
                visited[p->to] = true;
                rear->next = newNode(p->to);
                rear = rear->next;
            }
            p = p->next;
        }
        front = front->next;
        free(q);
        q = front;
    }
}

int main() {
    int n, ta, ao;
    scanf("%d %d %d", &n, &ta, &ao);
    graph *g = (graph *)malloc(sizeof(graph));
    g->V = n;
    for (int i = 0; i < n; i++) g->adj[i] = NULL;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u - 1, v - 1);
        addEdge(g, v - 1, u - 1);
    }
    int *dist_ta = (int *)malloc(sizeof(int) * n);
    int *dist_ao = (int *)malloc(sizeof(int) * n);
    dfs(g, ta - 1, dist_ta);
    dfs(g, ao - 1, dist_ao);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dist_ta[i] < dist_ao[i]) ans = max(ans, dist_ao[i]);
    }
    printf("%d\n", ans - 1);
    return 0;
}
