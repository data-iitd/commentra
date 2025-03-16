#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 100000

typedef struct Node {
    int val;
    bool color;
    struct Node *a[MAXN];
} Node;

int n;
Node nodes[MAXN];

void traverse(Node *node, int distance) {
    if (node->color) {
        return;
    }
    node->color = true;
    for (int i = 0; i < node->val; i++) {
        Node *adjNode = node->a[i];
        int dis = node->a[i]->val;
        if ((distance + dis) % 2 == 0) {
            adjNode->color = node->color;
        } else {
            adjNode->color =!node->color;
        }
        traverse(adjNode, distance + dis);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        nodes[i].val = i;
        nodes[i].color = false;
        for (int j = 0; j < n; j++) {
            nodes[i].a[j] = NULL;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Node *node1 = &nodes[u - 1];
        Node *node2 = &nodes[v - 1];
        node1->a[node1->val] = node2;
        node2->a[node2->val] = node1;
        node1->val++;
        node2->val++;
    }
    Node *root = &nodes[0];
    root->color = true;
    traverse(root, 0);
    for (int i = 0; i < n; i++) {
        Node *node = &nodes[i];
        if (node->color) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("