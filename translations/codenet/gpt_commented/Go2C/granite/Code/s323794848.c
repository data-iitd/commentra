
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *front;
    char *back;
} Deque;

void initDeque(Deque *deq) {
    deq->front = (char *)malloc(sizeof(char) * 100000);
    deq->back = (char *)malloc(sizeof(char) * 100000);
    deq->front[0] = '\0';
    deq->back[0] = '\0';
}

void freeDeque(Deque *deq) {
    free(deq->front);
    free(deq->back);
}

void pushBack(Deque *deq, char c) {
    strcat(deq->back, &c);
}

void pushFront(Deque *deq, char c) {
    strcat(deq->front, &c);
}

void popBack(Deque *deq, char *c) {
    int len = strlen(deq->back);
    if (len > 0) {
        deq->back[len - 1] = '\0';
        *c = deq->back[len - 2];
    }
}

void popFront(Deque *deq, char *c) {
    int len = strlen(deq->front);
    if (len > 0) {
        deq->front[len - 1] = '\0';
        *c = deq->front[len - 2];
    }
}

char get(Deque *deq, int idx) {
    int len = strlen(deq->front) + strlen(deq->back);
    if (idx < len) {
        if (idx < strlen(deq->front)) {
            return deq->front[strlen(deq->front) - 1 - idx];
        } else {
            return deq->back[idx - strlen(deq->front)];
        }
    }
    return '\0';
}

typedef struct {
    int rev;
    int front;
    char c;
} Op;

void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int main() {
    char S[100000];
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
            ops[i].front = f;
        }
    }
    int sum[Q + 1];
    sum[Q] = 0;
    for (int i = Q - 1; i >= 1; i--) {
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1;
        } else {
            sum[i - 1] = sum[i];
        }
    }
    if (sum[0] % 2 == 1) {
        reverse(S);
    }
    Deque deq;
    initDeque(&deq);
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
    freeDeque(&deq);
    return 0;
}

