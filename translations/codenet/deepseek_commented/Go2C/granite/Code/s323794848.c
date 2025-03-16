
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *front;
    char *back;
} Deque;

void deque_init(Deque *deq) {
    deq->front = (char *)malloc(sizeof(char));
    deq->back = (char *)malloc(sizeof(char));
    deq->front[0] = '\0';
    deq->back[0] = '\0';
}

void deque_push_front(Deque *deq, char c) {
    deq->front = (char *)realloc(deq->front, strlen(deq->front) + 2);
    deq->front[0] = c;
    deq->front[1] = '\0';
}

void deque_push_back(Deque *deq, char c) {
    deq->back = (char *)realloc(deq->back, strlen(deq->back) + 2);
    deq->back[strlen(deq->back)] = c;
    deq->back[strlen(deq->back) + 1] = '\0';
}

void deque_pop_front(Deque *deq, char *c) {
    if (strlen(deq->front) > 1) {
        deq->front = (char *)realloc(deq->front, strlen(deq->front) - 1);
    } else {
        *c = deq->back[strlen(deq->back) - 1];
        deq->back = (char *)realloc(deq->back, strlen(deq->back) - 1);
    }
}

void deque_pop_back(Deque *deq, char *c) {
    if (strlen(deq->back) > 1) {
        deq->back = (char *)realloc(deq->back, strlen(deq->back) - 1);
    } else {
        *c = deq->front[strlen(deq->front) - 1];
        deq->front = (char *)realloc(deq->front, strlen(deq->front) - 1);
    }
}

char deque_get(Deque *deq, int idx) {
    int tot = strlen(deq->front) + strlen(deq->back);
    char c = '\0';
    if (idx < tot) {
        if (idx < strlen(deq->front)) {
            c = deq->front[strlen(deq->front) - 1 - idx];
        } else {
            c = deq->back[idx - strlen(deq->front)];
        }
    }
    return c;
}

int main() {
    char S[100001];
    scanf("%s", S);
    int Q;
    scanf("%d", &Q);
    int rev[100001];
    int front[100001];
    char c[100001];
    for (int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            rev[i] = 1;
        } else {
            scanf("%d %c", &front[i], &c[i]);
        }
    }
    int sum = 0;
    for (int i = Q - 1; i >= 1; i--) {
        if (rev[i] == 1) {
            sum++;
        } else {
            if (front[i] == 1) {
                if (sum % 2 == 1) {
                    deque_push_back(&deq, c[i]);
                } else {
                    deque_push_front(&deq, c[i]);
                }
            } else {
                if (sum % 2 == 1) {
                    deque_push_front(&deq, c[i]);
                } else {
                    deque_push_back(&deq, c[i]);
                }
            }
        }
    }
    if (sum % 2 == 1) {
        for (int i = 0; i < strlen(S); i++) {
            S[i] = tolower(S[i]);
        }
    }
    for (int i = 0; i < Q; i++) {
        if (rev[i] == 0) {
            if (front[i] == 1) {
                if (sum % 2 == 1) {
                    deque_push_back(&deq, c[i]);
                } else {
                    deque_push_front(&deq, c[i]);
                }
            } else {
                if (sum % 2 == 1) {
                    deque_push_front(&deq, c[i]);
                } else {
                    deque_push_back(&deq, c[i]);
                }
            }
        }
    }
    char ans[100001];
    int ans_idx = 0;
    for (int i = strlen(deq.front) - 1; i >= 0; i--) {
        ans[ans_idx++] = deq.front[i];
    }
    for (int i = 0; i < strlen(S); i++) {
        ans[ans_idx++] = S[i];
    }
    for (int i = 0; i < strlen(deq.back); i++) {
        ans[ans_idx++] = deq.back[i];
    }
    ans[ans_idx] = '\0';
    printf("%s\n", ans);
    return 0;
}
