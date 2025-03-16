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

void initMons(Mons *mons, int capacity) {
    mons->arr = (Mon *)malloc(capacity * sizeof(Mon));
    mons->size = 0;
    mons->capacity = capacity;
}

void addMon(Mons *mons, Mon mon) {
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

typedef struct {
    Mon *arr;
    int size;
} Queue;

void initQueue(Queue *queue, int capacity) {
    queue->arr = (Mon *)malloc(capacity * sizeof(Mon));
    queue->size = 0;
}

void pushQueue(Queue *queue, Mon mon) {
    queue->arr[queue->size++] = mon;
}

Mon popQueue(Queue *queue) {
    Mon res = queue->arr[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->size--;
    return res;
}

int isEmptyQueue(Queue *queue) {
    return queue->size == 0;
}

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);

    Mons mons;
    initMons(&mons, N);

    for (int i = 0; i < N; i++) {
        int x, h;
        scanf("%d %d", &x, &h);
        addMon(&mons, (Mon){x, h});
    }

    qsort(mons.arr, mons.size, sizeof(Mon), compareMon);

    Queue queue;
    initQueue(&queue, N);

    long long ans = 0;
    long long total = 0;

    for (int i = 0; i < mons.size; i++) {
        Mon m = mons.arr[i];
        while (!isEmptyQueue(&queue) && queue.arr[0].x < m.x) {
            total -= queue.arr[0].h;
            popQueue(&queue);
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceil(m.h, A);
            ans += count;
            long long damage = count * A;
            pushQueue(&queue, (Mon){m.x + 2 * D, damage});
            total += damage;
        }
    }

    printf("%lld\n", ans);

    free(mons.arr);
    free(queue.arr);

    return 0;
}
