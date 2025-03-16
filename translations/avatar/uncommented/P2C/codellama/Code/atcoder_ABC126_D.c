#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NODES 100000
#define MAX_EDGES 100000
#define MAX_DISTANCE 100000
typedef struct Node {
    int val;
    bool color;
    struct Node *a[MAX_EDGES];
    int w[MAX_EDGES];
} Node;
int main() {
    int n;
    scanf("%d", &n);
    Node *nodes = (Node *)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        nodes[i].val = i + 1;
        nodes[i].color = false;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        nodes[u - 1].a[i] = &nodes[v - 1];
        nodes[u - 1].w[i] = w;
        nodes[v - 1].a[i] = &nodes[u - 1];
        nodes[v - 1].w[i] = w;
    }
    Node *root = &nodes[0];
    root->color = true;
    bool nodeSet[MAX_NODES];
    for (int i = 0; i < n; i++) {
        nodeSet[i] = false;
    }
    void traverse(Node *node, int distance) {
        if (nodeSet[node->val - 1]) {
            return;
        } else {
            nodeSet[node->val - 1] = true;
        }
        for (int i = 0; i < MAX_EDGES; i++) {
            if (node->a[i] != NULL) {
                Node *adjNode = node->a[i];
                int dis = node->w[i];
                if ((distance + dis) % 2 == 0) {
                    adjNode->color = root->color;
                } else {
                    adjNode->color = !root->color;
                }
                traverse(adjNode, distance + dis);
            }
        }
    }
    traverse(root, 0);
    for (int i = 0; i < n; i++) {
        if (nodes[i].color) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}



