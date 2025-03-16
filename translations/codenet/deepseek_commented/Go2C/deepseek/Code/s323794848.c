#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *front;
    char *back;
    int front_len;
    int back_len;
} Deque;

void initDeque(Deque *deq) {
    deq->front = (char *)malloc(1);
    deq->back = (char *)malloc(1);
    deq->front[0] = '\0';
    deq->back[0] = '\0';
    deq->front_len = 0;
    deq->back_len = 0;
}

int isEmptyFront(Deque *deq) {
    return deq->front_len == 0;
}

int isEmptyBack(Deque *deq) {
    return deq->back_len == 0;
}

void pushBack(Deque *deq, char v) {
    deq->back = (char *)realloc(deq->back, deq->back_len + 2);
    deq->back[deq->back_len] = v;
    deq->back[deq->back_len + 1] = '\0';
    deq->back_len++;
}

void pushFront(Deque *deq, char v) {
    deq->front = (char *)realloc(deq->front, deq->front_len + 2);
    memmove(deq->front + 1, deq->front, deq->front_len + 1);
    deq->front[0] = v;
    deq->front_len++;
}

int popBack(Deque *deq, char *v) {
    int r = 1;
    if (!isEmptyBack(deq)) {
        *v = deq->back[deq->back_len - 1];
        deq->back_len--;
        deq->back = (char *)realloc(deq->back, deq->back_len + 1);
        deq->back[deq->back_len] = '\0';
    } else if (!isEmptyFront(deq)) {
        *v = deq->front[0];
        memmove(deq->front, deq->front + 1, deq->front_len);
        deq->front_len--;
        deq->front = (char *)realloc(deq->front, deq->front_len + 1);
    } else {
        r = 0;
    }
    return r;
}

int popFront(Deque *deq, char *v) {
    int r = 1;
    if (!isEmptyFront(deq)) {
        *v = deq->front[deq->front_len - 1];
        deq->front_len--;
        deq->front = (char *)realloc(deq->front, deq->front_len + 1);
    } else if (!isEmptyBack(deq)) {
        *v = deq->back[0];
        memmove(deq->back, deq->back + 1, deq->back_len);
        deq->back_len--;
        deq->back = (char *)realloc(deq->back, deq->back_len + 1);
    } else {
        r = 0;
    }
    return r;
}

char get(Deque *deq, int idx) {
    int tot = deq->front_len + deq->back_len;
    char v = '\0';
    if (idx < tot) {
        if (idx < deq->front_len) {
            v = deq->front[deq->front_len - 1 - idx];
        } else {
            v = deq->back[idx - deq->front_len];
        }
    }
    return v;
}

typedef struct {
    int rev;
    int front;
    char c;
} Op;

char* revStr(char *s) {
    int len = strlen(s);
    char *r = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        r[i] = s[len - 1 - i];
    }
    r[len] = '\0';
    return r;
}

int main() {
    char S[100001];
    scanf("%s", S);
    int Q;
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
            ops[i].front = f == 1;
            ops[i].c = c;
            ops[i].rev = 0;
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
    if (sum[0] % 2 == 1) {
        S = revStr(S);
    }
    Deque deq;
    initDeque(&deq);
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
    char result[100002];
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
