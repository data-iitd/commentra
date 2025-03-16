
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deque structure to simulate a double-ended queue
typedef struct deque {
	char *front, *back;
} deque;

// Check if the front of the deque is empty
int isEmptyFront(deque *deq) {
	return deq->front == NULL;
}

// Check if the back of the deque is empty
int isEmptyBack(deque *deq) {
	return deq->back == NULL;
}

// Push a byte to the back of the deque
void pushBack(deque *deq, char v) {
	deq->back = realloc(deq->back, sizeof(char) * (strlen(deq->back) + 2));
	deq->back[strlen(deq->back)] = v;
	deq->back[strlen(deq->back) + 1] = '\0';
}

// Push a byte to the front of the deque
void pushFront(deque *deq, char v) {
	deq->front = realloc(deq->front, sizeof(char) * (strlen(deq->front) + 2));
	deq->front[strlen(deq->front)] = v;
	deq->front[strlen(deq->front) + 1] = '\0';
}

// Pop a byte from the back of the deque
int popBack(deque *deq, char *v) {
	int r = 1;
	if (!isEmptyBack(deq)) {
		*v = deq->back[strlen(deq->back) - 1];
		deq->back = realloc(deq->back, sizeof(char) * (strlen(deq->back) - 1));
	} else if (!isEmptyFront(deq)) {
		*v = deq->front[0];
		deq->front = realloc(deq->front, sizeof(char) * (strlen(deq->front) - 1));
	} else {
		r = 0;
	}
	return r;
}

// Pop a byte from the front of the deque
int popFront(deque *deq, char *v) {
	int r = 1;
	if (!isEmptyFront(deq)) {
		*v = deq->front[strlen(deq->front) - 1];
		deq->front = realloc(deq->front, sizeof(char) * (strlen(deq->front) - 1));
	} else if (!isEmptyBack(deq)) {
		*v = deq->back[0];
		deq->back = realloc(deq->back, sizeof(char) * (strlen(deq->back) - 1));
	} else {
		r = 0;
	}
	return r;
}

// Get the byte at a specific index in the deque
char get(deque *deq, int idx) {
	int tot = strlen(deq->front) + strlen(deq->back);
	char v = '\0';
	if (idx < tot) {
		if (idx < strlen(deq->front)) {
			v = deq->front[strlen(deq->front) - 1 - idx];
		} else {
			v = deq->back[idx - strlen(deq->front)];
		}
	}
	return v;
}

// Operation struct to store each operation's details
typedef struct op {
	int rev, front;
	char c;
} op;

// Reverse a string
char *rev(char *s) {
	int i, j;
	char *r = malloc(sizeof(char) * (strlen(s) + 1));
	for (i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
		r[j] = s[i];
	}
	r[j] = '\0';
	return r;
}

int main() {
	char *S;
	scanf("%ms", &S);
	int Q;
	scanf("%d", &Q);
	op *ops = malloc(sizeof(op) * Q);
	int *sum = malloc(sizeof(int) * (Q + 1));
	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);
		if (q == 1) {
			ops[i].rev = 1;
		} else {
			int f;
			scanf("%d %c", &f, &ops[i].c);
			if (f == 1) {
				ops[i].front = 1;
			}
		}
	}
	for (int i = Q - 1; i >= 1; i--) {
		if (ops[i].rev) {
			sum[i - 1] = sum[i] + 1;
		} else {
			sum[i - 1] = sum[i];
		}
	}
	if (sum[0] % 2 == 1) {
		S = rev(S);
	}
	deque deq;
	deq.front = NULL;
	deq.back = NULL;
	for (int i = 0; i < Q; i++) {
		if (!ops[i].rev) { // Not a reversal operation (string append)
			if (ops[i].front) {
				if (sum[i] % 2 == 1) {
					pushBack(&deq, ops[i].c);
				} else {
					pushFront(&deq, ops[i].c);
				}
			} else {
				if (sum[i] % 2 == 1) {
					pushFront(&deq, ops[i].c);
				} else {
					pushBack(&deq, ops[i].c);
				}
			}
		}
	}
	char *wtr = malloc(sizeof(char) * (strlen(deq.front) + strlen(S) + strlen(deq.back) + 1));
	int j = 0;
	for (int i = strlen(deq.front) - 1; i >= 0; i--) {
		wtr[j++] = deq.front[i];
	}
	for (int i = 0; i < strlen(S); i++) {
		wtr[j++] = S[i];
	}
	for (int i = 0; i < strlen(deq.back); i++) {
		wtr[j++] = deq.back[i];
	}
	wtr[j] = '\0';
	printf("%s\n", wtr);
	free(S);
	free(ops);
	free(sum);
	free(deq.front);
	free(deq.back);
	free(wtr);
	return 0;
}

