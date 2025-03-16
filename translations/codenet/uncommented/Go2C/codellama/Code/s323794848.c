#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int front, back;
} deque;

int isEmptyFront(deque *deq) {
	return deq->front == 0;
}
int isEmptyBack(deque *deq) {
	return deq->back == 0;
}

void pushBack(deque *deq, char v) {
	deq->back = (deq->back << 8) | v;
}
void pushFront(deque *deq, char v) {
	deq->front = (deq->front << 8) | v;
}
int popBack(deque *deq, char *v) {
	int r = 1;
	if (!isEmptyBack(deq)) {
		*v = deq->back & 0xff;
		deq->back = deq->back >> 8;
	} else if (!isEmptyFront(deq)) {
		*v = deq->front & 0xff;
		deq->front = deq->front >> 8;
	} else {
		r = 0;
	}
	return r;
}
int popFront(deque *deq, char *v) {
	int r = 1;
	if (!isEmptyFront(deq)) {
		*v = deq->front & 0xff;
		deq->front = deq->front >> 8;
	} else if (!isEmptyBack(deq)) {
		*v = deq->back & 0xff;
		deq->back = deq->back >> 8;
	} else {
		r = 0;
	}
	return r;
}

char get(deque *deq, int idx) {
	int tot = deq->front + deq->back;
	char v = 0;
	if (idx < tot) {
		if (idx < deq->front) {
			v = deq->front & 0xff;
		} else {
			v = deq->back & 0xff;
		}
	}
	return v;
}

typedef struct {
	int rev, front;
	char c;
} op;

char *rev(char *s) {
	int i, j;
	char *r = malloc(strlen(s) + 1);
	for (i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
		r[j] = s[i];
	}
	r[j] = 0;
	return r;
}

int main() {
	char *S;
	int Q;
	scanf("%ms %d", &S, &Q);
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
	// printf("S %s Q %d ops %s sum %s\n", S, Q, ops, sum);
	if (sum[0] % 2 == 1) {
		S = rev(S);
	}
	deque deq = {0, 0};
	for (int i = 0; i < Q; i++) {
		if (!ops[i].rev) { // 反転ではない(文字列追加)
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
	for (int i = deq.front - 1; i >= 0; i--) {
		printf("%c", get(&deq, i));
	}
	printf("%s", S);
	for (int i = 0; i < deq.back; i++) {
		printf("%c", get(&deq, i));
	}
	printf("\n");
	return 0;
}

