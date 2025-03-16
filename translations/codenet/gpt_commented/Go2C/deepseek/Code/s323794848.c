#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    char front[MAX_SIZE];
    char back[MAX_SIZE];
    int front_size;
    int back_size;
} Deque;

void init(Deque *deq) {
    deq->front_size = 0;
    deq->back_size = 0;
}

int isEmptyFront(Deque *deq) {
    return deq->front_size == 0;
}

int isEmptyBack(Deque *deq) {
    return deq->back_size == 0;
}

void pushFront(Deque *deq, char c) {
    if (deq->front_size < MAX_SIZE) {
        for (int i = deq->front_size; i > 0; i--) {
            deq->front[i] = deq->front[i - 1];
        }
        deq->front[0] = c;
        deq->front_size++;
    }
}

void pushBack(Deque *deq, char c) {
    if (deq->back_size < MAX_SIZE) {
        deq->back[deq->back_size] = c;
        deq->back_size++;
    }
}

int popFront(Deque *deq, char *c) {
    if (!isEmptyFront(deq)) {
        *c = deq->front[0];
        for (int i = 0; i < deq->front_size - 1; i++) {
            deq->front[i] = deq->front[i + 1];
        }
        deq->front_size--;
        return 1;
    } else if (!isEmptyBack(deq)) {
        *c = deq->back[0];
        for (int i = 0; i < deq->back_size - 1; i++) {
            deq->back[i] = deq->back[i + 1];
        }
        deq->back_size--;
        return 1;
    } else {
        return 0;
    }
}

int popBack(Deque *deq, char *c) {
    if (!isEmptyBack(deq)) {
        *c = deq->back[deq->back_size - 1];
        deq->back_size--;
        return 1;
    } else if (!isEmptyFront(deq)) {
        *c = deq->front[deq->front_size - 1];
        for (int i = deq->front_size - 1; i > 0; i--) {
            deq->front[i] = deq->front[i - 1];
        }
        deq->front_size--;
        return 1;
    } else {
        return 0;
    }
}

char get(Deque *deq, int idx) {
    int tot = deq->front_size + deq->back_size;
    char v = 0;
    if (idx < tot) {
        if (idx < deq->front_size) {
            v = deq->front[deq->front_size - 1 - idx];
        } else {
            v = deq->back[idx - deq->front_size];
        }
    }
    return v;
}

typedef struct {
    int rev;
    int front;
    char c;
} Op;

char* rev(char* s) {
    int len = strlen(s);
    char* r = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        r[i] = s[len - 1 - i];
    }
    r[len] = '\0';
    return r;
}

int main() {
    char S[MAX_SIZE + 1];
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
            scanf("%d %c", &f, &ops[i].c);
            ops[i].front = f == 1;
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
        S = rev(S);
    }

    Deque deq;
    init(&deq);

    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) {
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

    char result[MAX_SIZE + 1];
    int idx = 0;

    while (!isEmptyFront(&deq)) {
        char c;
        if (popFront(&deq, &c)) {
            result[idx++] = c;
        }
    }
    strcat(result, S);
    while (!isEmptyBack(&deq)) {
        char c;
        if (popBack(&deq, &c)) {
            result[idx++] = c;
        }
    }
    result[idx] = '\0';

    printf("%s\n", result);

    return 0;
}
