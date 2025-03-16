#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int first;
	int second;
} Pair;

typedef struct {
	Pair *v;
	int size;
	int capacity;
} Queue;

void queue_init(Queue *q) {
	q->v = NULL;
	q->size = 0;
	q->capacity = 0;
}

void queue_push(Queue *q, Pair v) {
	if (q->size == q->capacity) {
		q->capacity = (q->capacity == 0)? 4 : q->capacity * 2;
		q->v = realloc(q->v, sizeof(Pair) * q->capacity);
	}
	q->v[q->size] = v;
	q->size++;
}

Pair queue_pop(Queue *q) {
	Pair r = q->v[0];
	q->size--;
	for (int i = 0; i < q->size; i++) {
		q->v[i] = q->v[i + 1];
	}
	return r;
}

Pair queue_front(Queue *q) {
	return q->v[0];
}

int queue_empty(Queue *q) {
	return q->size == 0;
}

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	if ((A + B) % 2 == 0) {
		printf("%d\n", (A + B) / 2);
		return 0;
	}
	printf("IMPOSSIBLE\n");
	return 0;
}

