
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
    int v;
    struct Edge *next;
} Edge;

typedef struct {
    int v;
    Edge *first;
} Vertex;

typedef struct {
    Vertex *V;
    int n;
    int m;
} Graph;

typedef struct {
    int *d;
    int *q;
    int front, rear;
} Queue;

typedef struct {
    int *color;
    int *parent;
    int *child_num;
} Status;

typedef struct {
    int *d;
    int size;
} Seq;

Graph *createGraph(int n, int m) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = (Vertex *)malloc(sizeof(Vertex) * (n + 1));
    g->n = n;
    g->m = m;
    for (int i = 0; i <= n; i++) {
        g->V[i].v = i;
        g->V[i].first = NULL;
    }
    return g;
}

void addEdge(Graph *g, int a, int b) {
    Edge *e = (Edge *)malloc(sizeof(Edge));
    e->v = b;
    e->next = g->V[a].first;
    g->V[a].first = e;
}

Queue *createQueue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->d = (int *)malloc(sizeof(int) * (n + 1));
    q->q = (int *)malloc(sizeof(int) * (n + 1));
    q->front = 0;
    q->rear = -1;
    return q;
}

void enQueue(Queue *q, int v) {
    q->rear = (q->rear + 1) % (q->n + 1);
    q->d[q->rear] = v;
}

int deQueue(Queue *q) {
    int v = q->d[q->front];
    q->front = (q->front + 1) % (q->n + 1);
    return v;
}

bool isEmpty(Queue *q) {
    return q->front == q->rear + 1;
}

Status *createStatus(int n) {
    Status *s = (Status *)malloc(sizeof(Status));
    s->color = (int *)malloc(sizeof(int) * (n + 1));
    s->parent = (int *)malloc(sizeof(int) * (n + 1));
    s->child_num = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        s->color[i] = 0;
        s->parent[i] = 0;
        s->child_num[i] = 0;
    }
    return s;
}

Seq *createSeq(int n) {
    Seq *s = (Seq *)malloc(sizeof(Seq));
    s->d = (int *)malloc(sizeof(int) * (n + 1));
    s->size = 0;
    return s;
}

void enSeq(Seq *s, int v) {
    s->d[s->size++] = v;
}

int deSeq(Seq *s) {
    return s->d[--s->size];
}

bool isEmptySeq(Seq *s) {
    return s->size == 0;
}

void topologicalSort(Graph *g, Seq *s) {
    Queue *q = createQueue(g->n);
    Status *st = createStatus(g->n);
    for (int i = 1; i <= g->n; i++) {
        if (st->child_num[i] == 0) {
            enQueue(q, i);
        }
    }
    while (!isEmpty(q)) {
        int v = deQueue(q);
        enSeq(s, v);
        st->color[v] = 1;
        Edge *e = g->V[v].first;
        while (e!= NULL) {
            int u = e->v;
            if (st->color[u] == 0) {
                st->parent[u] = v;
                st->child_num[v]++;
                enQueue(q, u);
            }
            e = e->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = createGraph(n, m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(g, a, b);
        addEdge(g, b, a);
    }
    Seq *s = createSeq(n);
    topologicalSort(g, s);
    if (isEmptySeq(s)) {
        printf("Second\n");
    } else {
        printf("First\n");
    }
    return 0;
}
