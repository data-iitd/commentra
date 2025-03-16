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
} Mons;

typedef struct {
    int x, h;
} Node;

typedef struct {
    Node *arr;
    int size;
    int capacity;
} Queue;

// Function to initialize a new queue
Queue* createQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Node *)malloc(capacity * sizeof(Node));
    q->size = 0;
    q->capacity = capacity;
    return q;
}

// Function to push a new Node to the priority queue
void push(Queue *q, Node v) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->arr = (Node *)realloc(q->arr, q->capacity * sizeof(Node));
    }
    q->arr[q->size++] = v;
}

// Function to get the first Node in the priority queue
Node first(Queue *q) {
    return q->arr[0];
}

// Function to pop and return the first Node from the priority queue
Node pop(Queue *q) {
    Node res = q->arr[0];
    for (int i = 1; i < q->size; i++) {
        q->arr[i - 1] = q->arr[i];
    }
    q->size--;
    return res;
}

// Function to check if the priority queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Function to compare two Mon structures for sorting
int compareMon(const void *a, const void *b) {
    return ((Mon *)a)->x - ((Mon *)b)->x;
}

// Main function
int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);

    Mon *M = (Mon *)malloc(N * sizeof(Mon));

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &M[i].x, &M[i].h);
    }

    // Sort the M array based on x-coordinates
    qsort(M, N, sizeof(Mon), compareMon);

    Queue *q = createQueue(10);
    int ans = 0;
    int total = 0;

    for (int i = 0; i < N; i++) {
        Mon m = M[i];

        while (!isEmpty(q) && first(q).x < m.x) {
            total -= pop(q).h;
        }

        if (total < m.h) {
            int damage = m.h - total;
            ans += damage;
            push(q, (Node){m.x + 2 * D, damage});
            total += damage;
        }
    }

    printf("%d\n", ans);

    // Free allocated memory
    free(M);
    free(q->arr);
    free(q);
    
    return 0;
}

// <END-OF-CODE>
