
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int front;
    char c;
    int rev;
} op;

typedef struct {
    char *front;
    char *back;
} deque;

int isEmptyFront(deque *deq) {
    return strlen(deq->front) == 0;
}

int isEmptyBack(deque *deq) {
    return strlen(deq->back) == 0;
}

void pushBack(deque *deq, char c) {
    deq->back = (char *)realloc(deq->back, strlen(deq->back) + 2);
    deq->back[strlen(deq->back)] = c;
    deq->back[strlen(deq->back) + 1] = '\0';
}

void pushFront(deque *deq, char c) {
    deq->front = (char *)realloc(deq->front, strlen(deq->front) + 2);
    memmove(deq->front + 1, deq->front, strlen(deq->front));
    deq->front[0] = c;
    deq->front[strlen(deq->front) + 1] = '\0';
}

int popBack(deque *deq, char *c) {
    if (!isEmptyBack(deq)) {
        *c = deq->back[strlen(deq->back) - 1];
        deq->back[strlen(deq->back) - 1] = '\0';
        deq->back = (char *)realloc(deq->back, strlen(deq->back));
        return 1;
    } else if (!isEmptyFront(deq)) {
        *c = deq->front[strlen(deq->front) - 1];
        deq->front[strlen(deq->front) - 1] = '\0';
        deq->front = (char *)realloc(deq->front, strlen(deq->front));
        return 1;
    } else {
        return 0;
    }
}

int popFront(deque *deq, char *c) {
    if (!isEmptyFront(deq)) {
        *c = deq->front[0];
        deq->front[0] = '\0';
        deq->front = (char *)realloc(deq->front, strlen(deq->front));
        return 1;
    } else if (!isEmptyBack(deq)) {
        *c = deq->back[strlen(deq->back) - 1];
        deq->back[strlen(deq->back) - 1] = '\0';
        deq->back = (char *)realloc(deq->back, strlen(deq->back));
        return 1;
    } else {
        return 0;
    }
}

char get(deque *deq, int idx) {
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

char *rev(char *s) {
    int len = strlen(s);
    char *r = (char *)malloc(len + 1);
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--) {
        r[j] = s[i];
        j++;
    }
    r[j] = '\0';
    return r;
}

int main() {
    char S[100001];
    scanf("%s", S);
    int Q;
    scanf("%d", &Q);
    op ops[Q];
    int sum[Q + 1];
    sum[0] = 0;
    for (int i = Q - 1; i >= 0; i--) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            ops[i].rev = 1;
        } else {
            int f;
            scanf("%d %c", &f, &ops[i].c);
            ops[i].front = f == 1;
        }
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1;
        } else {
            sum[i - 1] = sum[i];
        }
    }
    if (sum[0] % 2 == 1) {
        strcpy(S, rev(S));
    }
    deque deq;
    deq.front = (char *)malloc(1);
    deq.front[0] = '\0';
    deq.back = (char *)malloc(1);
    deq.back[0] = '\0';
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) {
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    pushFront(&deq, ops[i].c);
                } else {
                    pushBack(&deq, ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    pushBack(&deq, ops[i].c);
                } else {
                    pushFront(&deq, ops[i].c);
                }
            }
        }
    }
    char c;
    for (int i = strlen(deq.front) - 1; i >= 0; i--) {
        printf("%c", deq.front[i]);
    }
    for (int i = 0; i < strlen(S); i++) {
        printf("%c", S[i]);
    }
    for (int i = 0; i < strlen(deq.back); i++) {
        printf("%c", deq.back[i]);
    }
    printf("\n");
    return 0;
}

