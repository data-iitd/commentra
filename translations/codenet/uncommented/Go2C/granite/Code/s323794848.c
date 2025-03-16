
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *front, *back;
} Deque;

void initDeque(Deque *deq) {
    deq->front = (char *)malloc(sizeof(char) * 100001);
    deq->back = (char *)malloc(sizeof(char) * 100001);
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

int popBack(Deque *deq, char *c) {
    int len_front = strlen(deq->front);
    int len_back = strlen(deq->back);
    if (len_back > 0) {
        *c = deq->back[len_back - 1];
        deq->back[len_back - 1] = '\0';
        return 1;
    } else if (len_front > 0) {
        *c = deq->front[len_front - 1];
        deq->front[len_front - 1] = '\0';
        return 1;
    } else {
        return 0;
    }
}

int popFront(Deque *deq, char *c) {
    int len_front = strlen(deq->front);
    int len_back = strlen(deq->back);
    if (len_front > 0) {
        *c = deq->front[len_front - 1];
        deq->front[len_front - 1] = '\0';
        return 1;
    } else if (len_back > 0) {
        *c = deq->back[len_back - 1];
        deq->back[len_back - 1] = '\0';
        return 1;
    } else {
        return 0;
    }
}

char get(Deque *deq, int idx) {
    int len_front = strlen(deq->front);
    int len_back = strlen(deq->back);
    int tot = len_front + len_back;
    if (idx < tot) {
        if (idx < len_front) {
            return deq->front[len_front - 1 - idx];
        } else {
            return deq->back[idx - len_front];
        }
    } else {
        return '\0';
    }
}

int main() {
    char S[100001];
    scanf("%s", S);
    int Q;
    scanf("%d", &Q);
    int rev[Q], front[Q], c[Q];
    for (int i = 0; i < Q; i++) {
        scanf("%d", &rev[i]);
        if (rev[i] == 2) {
            scanf("%d %c", &front[i], &c[i]);
        }
    }
    int sum[Q + 1];
    sum[Q] = 0;
    for (int i = Q - 1; i >= 0; i--) {
        sum[i] = sum[i + 1];
        if (rev[i] == 1) {
            sum[i]++;
        }
    }
    Deque deq;
    initDeque(&deq);
    for (int i = 0; i < Q; i++) {
        if (rev[i] == 1) {
            if (sum[i] % 2 == 1) {
                pushBack(&deq, c[i]);
            } else {
                pushFront(&deq, c[i]);
            }
        } else {
            if (sum[i] % 2 == 1) {
                pushFront(&deq, c[i]);
            } else {
                pushBack(&deq, c[i]);
            }
        }
    }
    char ans[100001];
    int ans_len = 0;
    if (sum[0] % 2 == 1) {
        for (int i = strlen(deq.front) - 1; i >= 0; i--) {
            ans[ans_len++] = deq.front[i];
        }
        for (int i = 0; i < strlen(S); i++) {
            ans[ans_len++] = S[i];
        }
        for (int i = 0; i < strlen(deq.back); i++) {
            ans[ans_len++] = deq.back[i];
        }
    } else {
        for (int i = 0; i < strlen(deq.front); i++) {
            ans[ans_len++] = deq.front[i];
        }
        for (int i = strlen(S) - 1; i >= 0; i--) {
            ans[ans_len++] = S[i];
        }
        for (int i = strlen(deq.back) - 1; i >= 0; i--) {
            ans[ans_len++] = deq.back[i];
        }
    }
    ans[ans_len] = '\0';
    printf("%s\n", ans);
    freeDeque(&deq);
    return 0;
}
