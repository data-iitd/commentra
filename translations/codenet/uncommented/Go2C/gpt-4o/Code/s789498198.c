#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void readInts(int *A, int *B) {
    scanf("%d %d", A, B);
}

int main() {
    int A, B;
    readInts(&A, &B);

    if ((A + B) % 2 == 0) {
        printf("%d\n", (A + B) / 2);
    } else {
        printf("IMPOSSIBLE\n");
    }

    return 0;
}

/* Utility functions */
int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

void varDump(int value) {
    fprintf(stderr, "%d\n", value);
}

void yes() {
    printf("Yes\n");
}

void no() {
    printf("No\n");
}

// Pair structure
typedef struct {
    int first;
    int second;
} Pair;

// Queue structure
typedef struct {
    Pair *v;
    int size;
    int capacity;
} Queue;

// Initialize queue
void initQueue(Queue *q, int capacity) {
    q->v = (Pair *)malloc(capacity * sizeof(Pair));
    q->size = 0;
    q->capacity = capacity;
}

// Push for queue
void push(Queue *q, Pair v) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->v = (Pair *)realloc(q->v, q->capacity * sizeof(Pair));
    }
    q->v[q->size++] = v;
}

// Pop for queue
Pair pop(Queue *q) {
    Pair r = q->v[0];
    memmove(q->v, q->v + 1, (q->size - 1) * sizeof(Pair));
    q->size--;
    return r;
}

// Front for queue
Pair front(Queue *q) {
    return q->v[0];
}

// Empty return true if empty
int empty(Queue *q) {
    return q->size == 0;
}

// Free queue memory
void freeQueue(Queue *q) {
    free(q->v);
}

/* <END-OF-CODE> */
