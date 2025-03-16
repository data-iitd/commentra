#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head[MAX_NODES];
} Graph;

int count;
bool seen[MAX_NODES];
int path = 0, cycle = 1;
Graph graph;

int dfs(int child, int par) {
    if (seen[child]) return cycle;
    seen[child] = true;
    Node* temp = graph.head[child];
    while (temp != NULL) {
        if (temp->data != par) {
            count++;
            if (dfs(temp->data, child) == cycle) return cycle;
        }
        temp = temp->next;
    }
    return path;
}

int main() {
    int m, n, x, y;
    scanf("%d %d", &m, &n);
    for (int i = 0; i <= m; i++) {
        graph.head[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = y;
        newNode->next = graph.head[x];
        graph.head[x] = newNode;
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = graph.head[y];
        graph.head[y] = newNode;
    }
    int toremove = 0;
    for (int i = 1; i <= m; i++) {
        if (!seen[i]) {
            count = 0;
            if (dfs(i, 0) == cycle) {
                if (count % 2 == 1) toremove++;
            }
        }
    }
    if ((m - toremove) % 2 == 1) toremove++;
    printf("%d\n", toremove);
    return 0;
}
