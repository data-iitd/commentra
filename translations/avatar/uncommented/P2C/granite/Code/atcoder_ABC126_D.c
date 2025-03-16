
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000
typedef struct Node {
    int val;
    int color;
    struct Node *a[MAX_N];
} Node;
int n;
Node *nodes[MAX_N];
void traverse(Node *node, int distance) {
    if (node->val == 0) {
        return;
    }
    if (node->val!= 0) {
        node->val = 0;
    }
    for (int i = 0; i < node->color; i++) {
        traverse(node->a[i], distance + node->a[i]->color);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        nodes[i]->val = 0;
        nodes[i]->color = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        nodes[u - 1]->a[nodes[u - 1]->color] = nodes[v - 1];
        nodes[u - 1]->color++;
        nodes[v - 1]->a[nodes[v - 1]->color] = nodes[u - 1];
        nodes[v - 1]->color++;
    }
    nodes[0]->color = 1;
    traverse(nodes[0], 0);
    for (int i = 0; i < n; i++) {
        printf("%d\n", nodes[i]->color);
    }
    return 0;
}
