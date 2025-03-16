#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct Node {
    int *edges;
    int edgeCount;
} Node;

Node graph[MAX_NODES];
int visited[MAX_NODES];
bool odd[MAX_NODES];
char print[10000]; // Assuming a maximum size for the output
int printIndex = 0;

void dfs(int crt, int parent) {
    visited[crt] = 1;
    for (int i = 0; i < graph[crt].edgeCount; i++) {
        int child = graph[crt].edges[i];
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            printIndex += sprintf(print + printIndex, "%d %d\n", crt + 1, child + 1);
            odd[crt] = !odd[crt];
        } else {
            dfs(child, crt);
            if (odd[child]) {
                printIndex += sprintf(print + printIndex, "%d %d\n", child + 1, crt + 1);
                odd[child] = !odd[child];
            } else {
                printIndex += sprintf(print + printIndex, "%d %d\n", crt + 1, child + 1);
                odd[crt] = !odd[crt];
            }
        }
    }
    visited[crt] = 2;
}

int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);

    for (int i = 0; i < numNode; i++) {
        graph[i].edges = (int *)malloc(MAX_NODES * sizeof(int));
        graph[i].edgeCount = 0;
    }

    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--; // Convert to 0-based index
        graph[a].edges[graph[a].edgeCount++] = b;
        graph[b].edges[graph[b].edgeCount++] = a;
    }

    if (numEdge % 2 != 0) {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < numNode; i++) {
        visited[i] = 0;
        odd[i] = false;
    }

    dfs(0, -1);
    printf("%s", print);

    for (int i = 0; i < numNode; i++) {
        free(graph[i].edges);
    }

    return 0;
}

// <END-OF-CODE>
