#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *front;
    unsigned char *back;
    int front_size;
    int back_size;
} deque;

void init_deque(deque *deq) {
    deq->front = NULL;
    deq->back = NULL;
    deq->front_size = 0;
    deq->back_size = 0;
}

int is_empty_front(deque *deq) {
    return deq->front_size == 0;
}

int is_empty_back(deque *deq) {
    return deq->back_size == 0;
}

void push_back(deque *deq, unsigned char v) {
    deq->back = realloc(deq->back, (deq->back_size + 1) * sizeof(unsigned char));
    deq->back[deq->back_size++] = v;
}

void push_front(deque *deq, unsigned char v) {
    deq->front = realloc(deq->front, (deq->front_size + 1) * sizeof(unsigned char));
    deq->front[deq->front_size++] = v;
}

int pop_back(deque *deq, unsigned char *v) {
    if (!is_empty_back(deq)) {
        *v = deq->back[--deq->back_size];
        deq->back = realloc(deq->back, deq->back_size * sizeof(unsigned char));
        return 1;
    } else if (!is_empty_front(deq)) {
        *v = deq->front[0];
        memmove(deq->front, deq->front + 1, --deq->front_size);
        deq->front = realloc(deq->front, deq->front_size * sizeof(unsigned char));
        return 1;
    }
    return 0;
}

int pop_front(deque *deq, unsigned char *v) {
    if (!is_empty_front(deq)) {
        *v = deq->front[--deq->front_size];
        deq->front = realloc(deq->front, deq->front_size * sizeof(unsigned char));
        return 1;
    } else if (!is_empty_back(deq)) {
        *v = deq->back[0];
        memmove(deq->back, deq->back + 1, --deq->back_size);
        deq->back = realloc(deq->back, deq->back_size * sizeof(unsigned char));
        return 1;
    }
    return 0;
}

unsigned char get(deque *deq, int idx) {
    int tot = deq->front_size + deq->back_size;
    if (idx < tot) {
        if (idx < deq->front_size) {
            return deq->front[deq->front_size - 1 - idx];
        } else {
            return deq->back[idx - deq->front_size];
        }
    }
    return 0; // Return 0 if index is out of bounds
}

void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int main() {
    char S[100001];
    scanf("%s", S);
    int Q;
    scanf("%d", &Q);
    
    struct {
        int rev;
        int front;
        unsigned char c;
    } ops[Q];

    for (int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            ops[i].rev = 1;
        } else {
            int f;
            scanf("%d %c", &f, &ops[i].c);
            ops[i].front = (f == 1);
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
        reverse(S);
    }

    deque deq;
    init_deque(&deq);
    
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) {
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    push_back(&deq, ops[i].c);
                } else {
                    push_front(&deq, ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    push_front(&deq, ops[i].c);
                } else {
                    push_back(&deq, ops[i].c);
                }
            }
        }
    }

    for (int i = deq.front_size - 1; i >= 0; i--) {
        printf("%c", deq.front[i]);
    }
    printf("%s", S);
    for (int i = 0; i < deq.back_size; i++) {
        printf("%c", deq.back[i]);
    }
    printf("\n");

    free(deq.front);
    free(deq.back);
    return 0;
}

// <END-OF-CODE>
