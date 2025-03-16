
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, h;
} Mon;

typedef struct {
    int x, h;
} Node;

typedef struct {
    Node *arr;
    int size;
} Queue;

Queue *newQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Node *)malloc(sizeof(Node) * 100000);
    q->size = 0;
    return q;
}

void push(Queue *q, Node v) {
    q->arr[q->size] = v;
    q->size++;
}

Node first(Queue *q) {
    return q->arr[0];
}

Node pop(Queue *q) {
    Node res = q->arr[0];
    for (int i = 0; i < q->size - 1; i++) {
        q->arr[i] = q->arr[i + 1];
    }
    q->size--;
    return res;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int max(int a, int b) {
    return a > b? a : b;
}

int main() {
    int N, D, A;
    scanf("%d %d %d", &N, &D, &A);
    Mon *M = (Mon *)malloc(sizeof(Mon) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &M[i].x, &M[i].h);
    }

    Queue *q = newQueue();
    int ans = 0, total = 0;
    for (int i = 0; i < N; i++) {
        Mon m = M[i];
        while (!isEmpty(q) && first(q).x < m.x) {
            total -= first(q).h;
            pop(q);
        }
        if (total < m.h) {
            m.h -= total;
            int count = (m.h + A - 1) / A;
            ans += count;
            int damage = count * A;
            push(q, (Node){m.x + 2 * D, damage});
            total += damage;
        }
    }

    printf("%d\n", ans);

    return 0;
}
