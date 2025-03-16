
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node **array;
    int size;
} graph;

graph *createGraph(int size) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->size = size;
    g->array = (node **)malloc(size * sizeof(node *));
    for (int i = 0; i < size; i++) {
        g->array[i] = NULL;
    }
    return g;
}

void addEdge(graph *g, int u, int v) {
    node *n1 = (node *)malloc(sizeof(node));
    n1->data = v;
    n1->next = NULL;

    node *n2 = (node *)malloc(sizeof(node));
    n2->data = u;
    n2->next = NULL;

    if (g->array[u] == NULL) {
        g->array[u] = n1;
    } else {
        node *temp = g->array[u];
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = n1;
    }

    if (g->array[v] == NULL) {
        g->array[v] = n2;
    } else {
        node *temp = g->array[v];
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = n2;
    }
}

bool *visited;
int count;
bool cycle;

void dfs(graph *g, int u, int parent) {
    visited[u] = true;
    count++;
    node *temp = g->array[u];
    while (temp!= NULL) {
        if (!visited[temp->data]) {
            dfs(g, temp->data, u);
        } else if (temp->data!= parent) {
            cycle = true;
        }
        temp = temp->next;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    graph *g = createGraph(m);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(g, x, y);
        addEdge(g, y, x);
    }

    int toremove = 0;
    visited = (bool *)malloc(m * sizeof(bool));
    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            count = 0;
            cycle = false;
            dfs(g, i, -1);
            if (cycle) {
                if (count % 2 == 1) {
                    toremove++;
                }
            }
        }
    }

    if ((m - toremove) % 2 == 1) {
        toremove++;
    }

    printf("%d\n", toremove);

    return 0;
}
