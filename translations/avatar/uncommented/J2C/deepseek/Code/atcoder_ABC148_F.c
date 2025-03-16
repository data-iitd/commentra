#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

void addEdge(List* array, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = array[src].head;
    array[src].head = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = array[dest].head;
    array[dest].head = newNode;
}

void dfs(int u, int* d, List* array, int N) {
    for (Node* node = array[u].head; node != NULL; node = node->next) {
        int nu = node->data;
        if (d[nu] == INT_MAX) {
            d[nu] = d[u] + 1;
            dfs(nu, d, array, N);
        }
    }
}

int main() {
    int N, u, v, q;
    scanf("%d %d %d", &N, &u, &v);
    u--; v--;

    List* edges = (List*)malloc(N * sizeof(List));
    for (int i = 0; i < N; i++) {
        edges[i].head = NULL;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        addEdge(edges, a, b);
    }

    int* d = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
    }
    d[u] = 0;
    dfs(u, d, edges, N);

    int* e = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        e[i] = INT_MAX;
    }
    e[v] = 0;
    dfs(v, e, edges, N);

    q = -1;
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
    free(edges);
    free(d);
    free(e);

    return 0;
}
