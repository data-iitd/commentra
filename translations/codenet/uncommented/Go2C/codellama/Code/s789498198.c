
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    Pair *v;
    int size;
    int capacity;
} Queue;

void Queue_init(Queue *q) {
    q->v = NULL;
    q->size = 0;
    q->capacity = 0;
}

void Queue_push(Queue *q, Pair v) {
    if (q->size == q->capacity) {
        q->capacity = q->capacity * 2 + 1;
        q->v = realloc(q->v, q->capacity * sizeof(Pair));
    }
    q->v[q->size++] = v;
}

Pair Queue_pop(Queue *q) {
    Pair r = q->v[0];
    for (int i = 0; i < q->size - 1; i++) {
        q->v[i] = q->v[i + 1];
    }
    q->size--;
    return r;
}

Pair Queue_front(Queue *q) {
    return q->v[0];
}

int Queue_empty(Queue *q) {
    return q->size == 0;
}

int digits(int x) {
    return (int)log10(x) + 1;
}

int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

void varDump(void *value) {
    printf("%#v\n", value);
}

void yes() {
    printf("Yes\n");
}

void no() {
    printf("No\n");
}

