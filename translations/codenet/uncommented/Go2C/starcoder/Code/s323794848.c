#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *front, *back;
} deque;

void deque_init(deque *deq) {
	deq->front = deq->back = NULL;
}

void deque_push_back(deque *deq, char c) {
	char *p = (char *)malloc(2);
	p[0] = c;
	p[1] = '\0';
	if (deq->back == NULL) {
		deq->front = deq->back = p;
	} else {
		deq->back[1] = p;
		deq->back = p;
	}
}

void deque_push_front(deque *deq, char c) {
	char *p = (char *)malloc(2);
	p[0] = c;
	p[1] = '\0';
	if (deq->front == NULL) {
		deq->front = deq->back = p;
	} else {
		p[1] = deq->front;
		deq->front = p;
	}
}

void deque_pop_back(deque *deq, char *c) {
	if (deq->back == NULL) {
		*c = '\0';
	} else {
		*c = deq->back[0];
		char *p = deq->back[1];
		free(deq->back);
		deq->back = p;
		if (deq->back == NULL) {
			deq->front = NULL;
		}
	}
}

void deque_pop_front(deque *deq, char *c) {
	if (deq->front == NULL) {
		*c = '\0';
	} else {
		*c = deq->front[0];
		char *p = deq->front[1];
		free(deq->front);
		deq->front = p;
		if (deq->front == NULL) {
			deq->back = NULL;
		}
	}
}

int main() {
	char S[100000];
	scanf("%s", S);
	int Q;
	scanf("%d", &Q);
	deque deq;
	deque_init(&deq);
	op ops[Q];
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
	int sum[Q+1];
	for (int i = Q - 1; i >= 1; i--) {
		if (ops[i].rev) {
			sum[i-1] = sum[i] + 1;
		} else {
			sum[i-1] = sum[i];
		}
	}
	if (sum[0] % 2 == 1) {
		for (int i = 0; i < strlen(S); i++) {
			S[i] = S[i] == '0'? '1' : '0';
		}
	}
	for (int i = 0; i < Q; i++) {
		if (!ops[i].rev) { // 反転ではない(文字列追加)
			if (ops[i].front) {
				if (sum[i] % 2 == 1) {
					deque_push_back(&deq, ops[i].c);
				} else {
					deque_push_front(&deq, ops[i].c);
				}
			} else {
				if (sum[i] % 2 == 1) {
					deque_push_front(&deq, ops[i].c);
				} else {
					deque_push_back(&deq, ops[i].c);
				}
			}
		}
	}
	for (int i = strlen(deq.front) - 1; i >= 0; i--) {
		putchar(deq.front[i]);
	}
	for (int i = 0; i < strlen(S); i++) {
		putchar(S[i]);
	}
	for (int i = 0; i < strlen(deq.back); i++) {
		putchar(deq.back[i]);
	}
	putchar('\n');
	return 0;
}

