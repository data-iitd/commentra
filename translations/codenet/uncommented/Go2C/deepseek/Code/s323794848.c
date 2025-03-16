#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *front;
    char *back;
    int front_size;
    int back_size;
} Deque;

void deque_init(Deque *deq) {
    deq->front = NULL;
    deq->back = NULL;
    deq->front_size = 0;
    deq->back_size = 0;
}

int deque_is_empty_front(Deque *deq) {
    return deq->front_size == 0;
}

int deque_is_empty_back(Deque *deq) {
    return deq->back_size == 0;
}

void deque_push_back(Deque *deq, char v) {
    deq->back = (char *)realloc(deq->back, deq->back_size + 1);
    deq->back[deq->back_size++] = v;
}

void deque_push_front(Deque *deq, char v) {
    deq->front = (char *)realloc(deq->front, deq->front_size + 1);
    deq->front[deq->front_size++] = v;
}

int deque_pop_back(Deque *deq, char *v) {
    if (deque_is_empty_back(deq)) {
        if (deque_is_empty_front(deq)) {
            return 0;
        } else {
            *v = deq->front[--deq->front_size];
            return 1;
        }
    } else {
        *v = deq->back[--deq->back_size];
        return 1;
    }
}

int deque_pop_front(Deque *deq, char *v) {
    if (deque_is_empty_front(deq)) {
        if (deque_is_empty_back(deq)) {
            return 0;
        } else {
            *v = deq->back[0];
            for (int i = 1; i < deq->back_size; i++) {
                deq->back[i - 1] = deq->back[i];
            }
            deq->back_size--;
            return 1;
        }
    } else {
        *v = deq->front[--deq->front_size];
        return 1;
    }
}

char deque_get(Deque *deq, int idx) {
    int tot = deq->front_size + deq->back_size;
    if (idx < tot) {
        if (idx < deq->front_size) {
            return deq->front[deq->front_size - 1 - idx];
        } else {
            return deq->back[idx - deq->front_size];
        }
    }
    return '\0';
}

typedef struct {
    int rev;
    int front;
    char c;
} Op;

char* rev_str(char *s, int len) {
    char *r = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        r[i] = s[len - 1 - i];
    }
    r[len] = '\0';
    return r;
}

int main() {
    char S[100001];
    int Q;
    scanf("%s", S);
    scanf("%d", &Q);
    Op ops[Q];
    for (int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            ops[i].rev = 1;
        } else {
            int f;
            char c;
            scanf("%d %c", &f, &c);
            ops[i].front = (f == 1) ? 1 : 0;
            ops[i].c = c;
        }
    }
    int sum[Q + 1];
    sum[Q] = 0;
    for (int i = Q - 1; i >= 0; i--) {
        if (ops[i].rev) {
            sum[i] = sum[i + 1] + 1;
        } else {
            sum[i] = sum[i + 1];
        }
    }
    char *S_ptr = S;
    Deque deq;
    deque_init(&deq);
    for (int i = 0; i < Q; i++) {
        if (ops[i].rev == 0) { // 反転ではない(文字列追加)
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
    char result[100001 + 100001];
    int idx = 0;
    for (int i = deq.front_size - 1; i >= 0; i--) {
        result[idx++] = deq.front[i];
    }
    for (int i = 0; i < strlen(S); i++) {
        result[idx++] = S[i];
    }
    for (int i = 0; i < deq.back_size; i++) {
        result[idx++] = deq.back[i];
    }
    result[idx] = '\0';
    if (sum[0] % 2 == 1) {
        char *reversed_S = rev_str(S, strlen(S));
        printf("%s\n", reversed_S);
        free(reversed_S);
    } else {
        printf("%s\n", result);
    }
    return 0;
}
