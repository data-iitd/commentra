#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100000

typedef struct Node {
    int index;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

void dfs(int u, int* d, List* edges, int N) {
    for (Node* node = edges[u].head; node != NULL; node = node->next) {
        if (d[node->index] == INT_MAX) {
            d[node->index] = d[u] + 1;
            dfs(node->index, d, edges, N);
        }
    }
}

int main() {
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);
    u--; v--; // Convert to zero-based index

    List edges[N];
    for (int i = 0; i < N; i++) {
        edges[i].head = NULL;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--; // Convert to zero-based index

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->index = b;
        newNode->next = edges[a].head;
        edges[a].head = newNode;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->index = a;
        newNode->next = edges[b].head;
        edges[b].head = newNode;
    }

    int d[N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u] = 0;
    dfs(u, d, edges, N);

    int e[N];
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v] = 0;
    dfs(v, e, edges, N);

    int q = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < e[i]) {
            if (e[i] > q) {
                q = e[i];
            }
        }
    }

    if (q <= 0) {
        printf("0\n");
    } else {
        printf("%d\n", q - 1);
    }

    for (int i = 0; i < N; i++) {
        Node* node = edges[i].head;
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    return 0;
}
