#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Q 100000

typedef struct {
    int rev;
    char c;
    int front;
} op;

typedef struct {
    char *front;
    char *back;
    int front_len;
    int back_len;
} deque;

int is_empty_front(deque *deq) {
    return deq->front_len == 0;
}

int is_empty_back(deque *deq) {
    return deq->back_len == 0;
}

void push_back(deque *deq, char v) {
    deq->back = (char *)realloc(deq->back, deq->back_len + 1);
    deq->back[deq->back_len] = v;
    deq->back_len++;
}

void push_front(deque *deq, char v) {
    deq->front = (char *)realloc(deq->front, deq->front_len + 1);
    deq->front[deq->front_len] = v;
    deq->front_len++;
}

int pop_back(deque *deq, char *v) {
    int r = 1;
    if (!is_empty_back(deq)) {
        *v = deq->back[deq->back_len - 1];
        deq->back_len--;
        deq->back = (char *)realloc(deq->back, deq->back_len);
    } else if (!is_empty_front(deq)) {
        *v = deq->front[deq->front_len - 1];
        deq->front_len--;
        deq->front = (char *)realloc(deq->front, deq->front_len);
    } else {
        r = 0;
    }
    return r;
}

int pop_front(deque *deq, char *v) {
    int r = 1;
    if (!is_empty_front(deq)) {
        *v = deq->front[deq->front_len - 1];
        deq->front_len--;
        deq->front = (char *)realloc(deq->front, deq->front_len);
    } else if (!is_empty_back(deq)) {
        *v = deq->back[0];
        deq->back_len--;
        deq->back = (char *)realloc(deq->back, deq->back_len);
        for (int i = 0; i < deq->back_len; i++) {
            deq->back[i] = deq->back[i + 1];
        }
    } else {
        r = 0;
    }
    return r;
}

char get(deque *deq, int idx) {
    int tot = deq->front_len + deq->back_len;
    char v = 0;
    if (idx < tot) {
        if (idx < deq->front_len) {
            v = deq->front[deq->front_len - 1 - idx];
        } else {
            v = deq->back[idx - deq->front_len];
        }
    }
    return v;
}

char *rev(char *s) {
    int len = strlen(s);
    char *r = (char *)malloc(len + 1);
    int i = len - 1, j = 0;
    while (i >= 0) {
        r[j] = s[i];
        j++;
        i--;
    }
    r[j] = '\0';
    return r;
}

int main() {
    char S[MAX_Q + 1];
    scanf("%s", S);
    int Q;
    scanf("%d", &Q);
    op ops[MAX_Q];
    for (int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            ops[i].rev = 1;
        } else {
            int f;
            char c;
            scanf("%d %c", &f, &c);
            ops[i].c = c;
            ops[i].front = f;
        }
    }
    int sum[Q + 1];
    sum[0] = 0;
    for (int i = Q - 1; i >= 0; i--) {
        if (ops[i].rev) {
            sum[i] = sum[i + 1] + 1;
        } else {
            sum[i] = sum[i + 1];
        }
    }
    if (sum[0] % 2 == 1) {
        S = rev(S);
    }
    deque deq = {NULL, NULL, 0, 0};
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) {
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    push_front(&deq, ops[i].c);
                } else {
                    push_back(&deq, ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    push_back(&deq, ops[i].c);
                } else {
                    push_front(&deq, ops[i].c);
                }
            }
        }
    }
    char result[MAX_Q + 1];
    int idx = 0;
    for (int i = deq.front_len - 1; i >= 0; i--) {
        result[idx++] = deq.front[i];
    }
    for (int i = 0; i < strlen(S); i++) {
        result[idx++] = S[i];
    }
    for (int i = 0; i < deq.back_len; i++) {
        result[idx++] = deq.back[i];
    }
    result[idx] = '\0';
    printf("%s\n", result);
    return 0;
}

