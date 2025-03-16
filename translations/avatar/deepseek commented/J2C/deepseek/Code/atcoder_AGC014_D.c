#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* g[MAX_NODES];

int maxMatching(int v, int p) {
    int a = 0;
    int o = 0;
    Node* temp = g[v];
    while (temp != NULL) {
        int w = temp->value;
        if (w == p) {
            temp = temp->next;
            continue;
        }
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
        temp = temp->next;
    }
    return 2 * a + (o % 2 == 0 ? 0 : 1) + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        g[i] = NULL;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = b;
        newNode->next = g[a];
        g[a] = newNode;
        newNode = (Node*)malloc(sizeof(Node));
        newNode->value = a;
        newNode->next = g[b];
        g[b] = newNode;
    }
    int m = maxMatching(0, -1) / 2;
    printf("%s\n", (2 * m == n) ? "Second" : "First");
    return 0;
}
