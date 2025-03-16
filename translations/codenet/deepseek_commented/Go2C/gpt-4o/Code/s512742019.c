#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD (1000000007)
#define INF (1LL << 60)

typedef struct {
    int x, h;
} Mon;

typedef struct {
    Mon *arr;
    int size;
    int capacity;
} Mons;

typedef struct {
    int x, h;
} Node;

typedef struct {
    Node *arr;
    int size;
    int capacity;
} Queue;

Mons createMons(int capacity) {
    Mons mons;
    mons.arr = (Mon *)malloc(capacity * sizeof(Mon));
    mons.size = 0;
    mons.capacity = capacity;
    return mons;
}

void pushMons(Mons *mons, Mon m) {
    if (mons->size == mons->capacity) {
        mons->capacity *= 2;
        mons->arr = (Mon *)realloc(mons->arr, mons->capacity * sizeof(Mon));
    }
    mons->arr[mons->size++] = m;
}

int compareMon(const void *a, const void *b) {
    return ((Mon *)a)->x - ((Mon *)b)->x;
}

Queue createQueue(int capacity) {
<<<<<<< HEAD
    Queue q;
    q.arr = (Node *)malloc(capacity * sizeof(Node));
    q.size = 0;
    q.capacity = capacity;
    return q;
}

void pushQueue(Queue *q, Node n) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->arr = (Node *)realloc(q->arr, q->capacity * sizeof(Node));
    }
    q->arr[q->size++] = n;
}

Node firstQueue(Queue *q) {
    return q->arr[0];
}

Node popQueue(Queue *q) {
    Node res = q->arr[0];
    memmove(q->arr, q->arr + 1, (q->size - 1) * sizeof(Node));
    q->size--;
    return res;
}

int isEmptyQueue(Queue *q) {
    return q->size == 0;
=======
    Queue queue;
    queue.arr = (Node *)malloc(capacity * sizeof(Node));
    queue.size = 0;
    queue.capacity = capacity;
    return queue;
}

void pushQueue(Queue *queue, Node n) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->arr = (Node *)realloc(queue->arr, queue->capacity * sizeof(Node));
    }
    queue->arr[queue->size++] = n;
}

Node firstQueue(Queue *queue) {
    return queue->arr[0];
}

Node popQueue(Queue *queue) {
    Node res = queue->arr[0];
    memmove(queue->arr, queue->arr + 1, (queue->size - 1) * sizeof(Node));
    queue->size--;
    return res;
}

int isEmptyQueue(Queue *queue) {
    return queue->size == 0;
>>>>>>> 98c87cb78a (data updated)
}

int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);
    
    Mons M = createMons(N);
    for (int i = 0; i < N; i++) {
        Mon m;
        scanf("%d %d", &m.x, &m.h);
        pushMons(&M, m);
    }
    
    qsort(M.arr, M.size, sizeof(Mon), compareMon);
    
    Queue q = createQueue(N);
    int ans = 0;
    long long total = 0;
    
    for (int i = 0; i < M.size; i++) {
        Mon m = M.arr[i];
<<<<<<< HEAD
        
        while (!isEmptyQueue(&q) && firstQueue(&q).x < m.x) {
            total -= popQueue(&q).h;
        }
        
=======
        while (!isEmptyQueue(&q) && firstQueue(&q).x < m.x) {
            total -= popQueue(&q).h;
        }
>>>>>>> 98c87cb78a (data updated)
        if (total < m.h) {
            m.h -= total;
            int count = ceilDiv(m.h, A);
            ans += count;
            long long damage = (long long)count * A;
            pushQueue(&q, (Node){m.x + 2 * D, damage});
            total += damage;
        }
    }
    
    printf("%d\n", ans);
    
    free(M.arr);
    free(q.arr);
    
    return 0;
}

// <END-OF-CODE>
