#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deque structure to simulate a double-ended queue
typedef struct {
    unsigned char *front;
    unsigned char *back;
    int front_size;
    int back_size;
} deque;

// Check if the front of the deque is empty
int isEmptyFront(deque *deq) {
    return deq->front_size == 0;
}

// Check if the back of the deque is empty
int isEmptyBack(deque *deq) {
    return deq->back_size == 0;
}

// Push a byte to the back of the deque
void pushBack(deque *deq, unsigned char v) {
    deq->back = realloc(deq->back, (deq->back_size + 1) * sizeof(unsigned char));
    deq->back[deq->back_size++] = v;
}

// Push a byte to the front of the deque
void pushFront(deque *deq, unsigned char v) {
    deq->front = realloc(deq->front, (deq->front_size + 1) * sizeof(unsigned char));
    deq->front[deq->front_size++] = v;
}

// Pop a byte from the back of the deque
int popBack(deque *deq, unsigned char *v) {
    if (!isEmptyBack(deq)) {
        *v = deq->back[--deq->back_size];
        return 1;
    } else if (!isEmptyFront(deq)) {
        *v = deq->front[0];
        memmove(deq->front, deq->front + 1, --deq->front_size);
        return 1;
    }
    return 0;
}

// Pop a byte from the front of the deque
int popFront(deque *deq, unsigned char *v) {
    if (!isEmptyFront(deq)) {
        *v = deq->front[--deq->front_size];
        return 1;
    } else if (!isEmptyBack(deq)) {
        *v = deq->back[0];
        memmove(deq->back, deq->back + 1, --deq->back_size);
        return 1;
    }
    return 0;
}

// Get the byte at a specific index in the deque
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

// Operation struct to store each operation's details
typedef struct {
    int rev;
    int front;
    unsigned char c;
} op;

// Reverse a string
void rev(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        unsigned char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int main() {
    char S[100001];
    scanf("%s", S);
    int Q;
    scanf("%d", &Q);
    op *ops = malloc(Q * sizeof(op));
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
    
    int *sum = malloc((Q + 1) * sizeof(int));
    sum[Q] = 0;
    for (int i = Q - 1; i >= 1; i--) {
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1;
        } else {
            sum[i - 1] = sum[i];
        }
    }
    
    if (sum[0] % 2 == 1) {
        rev(S);
    }
    
    deque deq = {NULL, NULL, 0, 0};
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
    
    for (int i = deq.front_size - 1; i >= 0; i--) {
        printf("%c", deq.front[i]);
    }
    printf("%s", S);
    for (int i = 0; i < deq.back_size; i++) {
        printf("%c", deq.back[i]);
    }
    printf("\n");
    
    free(ops);
    free(deq.front);
    free(deq.back);
    free(sum);
    
    return 0;
}

// <END-OF-CODE>
