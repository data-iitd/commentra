#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define INF 1LL << 60

typedef struct {
    int x, h;
} Mon;

typedef struct {
    Mon *data;
    int size, capacity;
} MonSlice;

void initMonSlice(MonSlice *slice, int capacity) {
    slice->data = (Mon *)malloc(capacity * sizeof(Mon));
    slice->size = 0;
    slice->capacity = capacity;
}

void appendMonSlice(MonSlice *slice, Mon mon) {
    if (slice->size >= slice->capacity) {
        slice->capacity *= 2;
        slice->data = (Mon *)realloc(slice->data, slice->capacity * sizeof(Mon));
    }
    slice->data[slice->size++] = mon;
}

void freeMonSlice(MonSlice *slice) {
    free(slice->data);
    slice->data = NULL;
    slice->size = 0;
    slice->capacity = 0;
}

typedef struct {
    int x, h;
} Node;

typedef struct {
    Node *data;
    int size, capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->data = (Node *)malloc(capacity * sizeof(Node));
    q->size = 0;
    q->capacity = capacity;
}

void pushQueue(Queue *q, Node v) {
    if (q->size >= q->capacity) {
        q->capacity *= 2;
        q->data = (Node *)realloc(q->data, q->capacity * sizeof(Node));
    }
    q->data[q->size++] = v;
}

Node firstQueue(Queue *q) {
    return q->data[0];
}

Node popQueue(Queue *q) {
    Node res = q->data[0];
    for (int i = 0; i < q->size - 1; i++) {
        q->data[i] = q->data[i + 1];
    }
    q->size--;
    return res;
}

int isEmptyQueue(Queue *q) {
    return q->size == 0;
}

void freeQueue(Queue *q) {
    free(q->data);
    q->data = NULL;
    q->size = 0;
    q->capacity = 0;
}

int compareMon(const void *a, const void *b) {
    Mon *monA = (Mon *)a;
    Mon *monB = (Mon *)b;
    return monA->x - monB->x;
}

int compareNode(const void *a, const void *b) {
    Node *nodeA = (Node *)a;
    Node *nodeB = (Node *)b;
    return nodeA->x - nodeB->x;
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);

    MonSlice mons;
    initMonSlice(&mons, N);

    for (int i = 0; i < N; i++) {
        Mon mon;
        scanf("%d %d", &mon.x, &mon.h);
        appendMonSlice(&mons, mon);
    }

    qsort(mons.data, mons.size, sizeof(Mon), compareMon);

    Queue q;
    initQueue(&q, N);

    long long ans = 0;
    long long total = 0;

    for (int i = 0; i < N; i++) {
        Mon m = mons.data[i];

        while (!isEmptyQueue(&q) && firstQueue(&q).x < m.x) {
            total -= popQueue(&q).h;
        }

        if (total < m.h) {
            long long damage = m.h - total;
            ans += damage;
            pushQueue(&q, (Node){m.x + 2 * D, damage});
            total += damage;
        }
    }

    printf("%lld\n", ans);

    freeMonSlice(&mons);
    freeQueue(&q);

    return 0;
}
