#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deque structure to simulate a double-ended queue
typedef struct {
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
	char *newBack = (char *) malloc(sizeof(char) * (strlen(deq->back) + 2));
	newBack[0] = v;
	strcpy(newBack + 1, deq->back);
	free(deq->back);
	deq->back = newBack;
}

// Push a byte to the front of the deque
void pushFront(deque *deq, char v) {
	char *newFront = (char *) malloc(sizeof(char) * (strlen(deq->front) + 2));
	strcpy(newFront + 1, deq->front);
	newFront[0] = v;
	free(deq->front);
	deq->front = newFront;
}

// Pop a byte from the back of the deque
int popBack(deque *deq, char *v) {
	int r = 1;
	if (deq->back == NULL) {
		if (deq->front == NULL) {
			r = 0;
		} else {
			*v = deq->front[0];
			deq->front = deq->front + 1;
		}
	} else {
		*v = deq->back[strlen(deq->back) - 1];
		deq->back = deq->back[0 : strlen(deq->back) - 1];
	}
	return r;
}

// Pop a byte from the front of the deque
int popFront(deque *deq, char *v) {
	int r = 1;
	if (deq->front == NULL) {
		if (deq->back == NULL) {
			r = 0;
		} else {
			*v = deq->back[0];
			deq->back = deq->back + 1;
		}
	} else {
		*v = deq->front[strlen(deq->front) - 1];
		deq->front = deq->front[0 : strlen(deq->front) - 1];
	}
	return r;
}

// Get the byte at a specific index in the deque
char get(deque *deq, int idx) {
	int tot = strlen(deq->front) + strlen(deq->back);
	char v = 0;
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
typedef struct {
	int rev, front;
	char c;
} op;

// Reverse a string
char *rev(char *s) {
	char *r = (char *) malloc(sizeof(char) * strlen(s));
	int i, j;
	for (i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
		r[j] = s[i];
	}
	return r;
}

int main() {
	char *S;
	scanf("%s", &S);
	int Q;
	scanf("%d", &Q);
	op *ops = (op *) malloc(sizeof(op) * Q);
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
	int *sum = (int *) malloc(sizeof(int) * (Q + 1));
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
	deq.front = deq.back = NULL;
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
	printf("%s", deq.front);
	for (int i = 0; i < strlen(S); i++) {
		printf("%c", S[i]);
	}
	printf("%s", deq.back);
	printf("\n");
	return 0;
}

