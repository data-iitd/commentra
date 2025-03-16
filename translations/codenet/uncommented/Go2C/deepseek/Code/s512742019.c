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
} Mons;

typedef struct {
    Mon *arr;
    int size;
    int capacity;
} Queue;

typedef struct {
    int x, h;
} Node;

Mons createMons(int capacity) {
    Mons mons;
    mons.arr = (Mon *)malloc(capacity * sizeof(Mon));
    mons.size = 0;
    mons.capacity = capacity;
    return mons;
}

void pushMons(Mons *mons, Mon mon) {
    if (mons->size == mons->capacity) {
        mons->capacity *= 2;
        mons->arr = (Mon *)realloc(mons->arr, mons->capacity * sizeof(Mon));
    }
    mons->arr[mons->size++] = mon;
}

int compareMon(const void *a, const void *b) {
    Mon *monA = (Mon *)a;
    Mon *monB = (Mon *)b;
    return monA->x - monB->x;
}

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

Queue createQueue(int capacity) {
    Queue queue;
    queue.arr = (Node *)malloc(capacity * sizeof(Node));
    queue.size = 0;
    queue.capacity = capacity;
    return queue;
}

void pushQueue(Queue *queue, Node node) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->arr = (Node *)realloc(queue->arr, queue->capacity * sizeof(Node));
    }
    queue->arr[queue->size++] = node;
}

Node firstQueue(Queue *queue) {
    return queue->arr[0];
}

Node popQueue(Queue *queue) {
    Node res = queue->arr[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->size--;
    return res;
}

int isEmptyQueue(Queue *queue) {
    return queue->size == 0;
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);
    Mons mons = createMons(N);
    for (int i = 0; i < N; i++) {
        Mon mon;
        scanf("%d %d", &mon.x, &mon.h);
        pushMons(&mons, mon);
    }
    qsort(mons.arr, mons.size, sizeof(Mon), compareMon);
    Queue queue = createQueue(N);
    long long ans = 0;
    long long total = 0;
    for (int i = 0; i < mons.size; i++) {
        Mon m = mons.arr[i];
        while (!isEmptyQueue(&queue) && firstQueue(&queue).x < m.x) {
            total -= popQueue(&queue).h;
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceil(m.h, A);
            ans += count;
            long long damage = count * A;
            pushQueue(&queue, (Node){m.x + 2 * D, damage});
            total += damage;
        }
    }
    printf("%lld\n", ans);
    free(mons.arr);
    free(queue.arr);
    return 0;
}
