#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007
#define INF 1LL << 60

typedef struct {
    int x, h;
} Mon;

typedef struct {
    Mon *arr;
    int size;
    int capacity;
} MonArray;

void initMonArray(MonArray *arr, int capacity) {
    arr->arr = (Mon *)malloc(capacity * sizeof(Mon));
    arr->size = 0;
    arr->capacity = capacity;
}

void addMon(MonArray *arr, Mon mon) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->arr = (Mon *)realloc(arr->arr, arr->capacity * sizeof(Mon));
    }
    arr->arr[arr->size++] = mon;
}

void freeMonArray(MonArray *arr) {
    free(arr->arr);
}

int compareMon(const void *a, const void *b) {
    Mon *monA = (Mon *)a;
    Mon *monB = (Mon *)b;
    return monA->x - monB->x;
}

int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
}

typedef struct {
    int x, h;
} Node;

typedef struct {
    Node *arr;
    int size;
    int capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->arr = (Node *)malloc(capacity * sizeof(Node));
    q->size = 0;
    q->capacity = capacity;
}

void pushQueue(Queue *q, Node v) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->arr = (Node *)realloc(q->arr, q->capacity * sizeof(Node));
    }
    q->arr[q->size++] = v;
}

Node firstQueue(Queue *q) {
    return q->arr[0];
}

Node popQueue(Queue *q) {
    Node res = q->arr[0];
    for (int i = 1; i < q->size; i++) {
        q->arr[i - 1] = q->arr[i];
    }
    q->size--;
    return res;
}

int isEmptyQueue(Queue *q) {
    return q->size == 0;
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);

    MonArray mons;
    initMonArray(&mons, N);

    for (int i = 0; i < N; i++) {
        Mon mon;
        scanf("%d %d", &mon.x, &mon.h);
        addMon(&mons, mon);
    }

    qsort(mons.arr, mons.size, sizeof(Mon), compareMon);

    Queue q;
    initQueue(&q, N);

    long long ans = 0;
    long long total = 0;

    for (int i = 0; i < mons.size; i++) {
        Mon m = mons.arr[i];
        while (!isEmptyQueue(&q) && firstQueue(&q).x < m.x) {
            total -= firstQueue(&q).h;
            popQueue(&q);
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceilDiv(m.h, A);
            ans += count;
            long long damage = (long long)count * A;
            pushQueue(&q, (Node){m.x + 2 * D, damage});
            total += damage;
        }
    }

    printf("%lld\n", ans);

    freeMonArray(&mons);
    free(q.arr);

    return 0;
}
