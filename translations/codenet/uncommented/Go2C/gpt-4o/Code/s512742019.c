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

void initMons(Mons *mons, int capacity) {
    mons->arr = (Mon *)malloc(capacity * sizeof(Mon));
    mons->size = 0;
    mons->capacity = capacity;
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

void popQueue(Queue *q) {
    for (int i = 1; i < q->size; i++) {
        q->arr[i - 1] = q->arr[i];
    }
    q->size--;
}

int isEmptyQueue(Queue *q) {
    return q->size == 0;
}

int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);
    
    Mons M;
    initMons(&M, N);
    
    for (int i = 0; i < N; i++) {
        Mon m;
        scanf("%d %d", &m.x, &m.h);
        pushMons(&M, m);
    }
    
    qsort(M.arr, M.size, sizeof(Mon), compareMon);
    
    Queue q;
    initQueue(&q, N);
    
    int ans = 0;
    long long total = 0;
    
    for (int i = 0; i < M.size; i++) {
        Mon m = M.arr[i];
        
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
    
    printf("%d\n", ans);
    
    free(M.arr);
    free(q.arr);
    
    return 0;
}

// <END-OF-CODE>
