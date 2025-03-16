#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct Node {
    int color;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

void enqueue(Queue* q, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->color = -1;
    newNode->next = NULL;
    if (q->tail != NULL) {
        q->tail->next = newNode;
    }
    q->tail = newNode;
    if (q->head == NULL) {
        q->head = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->head == NULL) {
        return -1;
    }
    int v = q->head->color;
    Node* temp = q->head;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return v;
}

bool bfs(int v, int N, Node* G[], int E[][2], int* node2color) {
    bool visited[MAX_N] = { false };
    Queue q = { NULL, NULL };
    int K = -1;
    enqueue(&q, v);
    visited[v] = true;
    node2color[v] = 0;
    while (q.head != NULL) {
        int qv = dequeue(&q);
        int color = 0;
        Node* current = G[qv]->next;
        while (current != NULL) {
            int nex = current->color;
            if (!visited[nex]) {
                visited[nex] = true;
                color += 1;
                if (color == node2color[qv]) {
                    color += 1;
                }
                node2color[nex] = color;
                E[min(qv, nex)][max(qv, nex)] = color;
                enqueue(&q, nex);
            }
            current = current->next;
        }
        K = (K > color) ? K : color;
    }
    return K;
}

int main() {
    int N;
    scanf("%d", &N);
    Node* G[MAX_N] = { NULL };
    int E[MAX_N][2] = { 0 };
    int node2color[MAX_N];
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a -= 1;
        b -= 1;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->color = b;
        newNode->next = G[a]->next;
        G[a]->next = newNode;
        newNode = (Node*)malloc(sizeof(Node));
        newNode->color = a;
        newNode->next = G[b]->next;
        G[b]->next = newNode;
    }
    int K = bfs(0, N, G, E, node2color);
    printf("%d\n", K);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (E[i][j] != 0) {
                printf("%d\n", E[i][j]);
            }
        }
    }
    return 0;
}
