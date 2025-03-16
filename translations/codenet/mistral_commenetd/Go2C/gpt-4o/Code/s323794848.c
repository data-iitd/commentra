#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a deque (double ended queue) type
typedef struct {
    unsigned char *front; // Front slice to store the elements
    unsigned char *back;  // Back slice to store the elements
    int frontSize;        // Size of the front slice
    int backSize;         // Size of the back slice
} deque;

// Function to create a new deque
deque* createDeque() {
    deque *deq = (deque *)malloc(sizeof(deque));
    deq->front = NULL;
    deq->back = NULL;
    deq->frontSize = 0;
    deq->backSize = 0;
    return deq;
}

// Function to check if deque is empty at the front
bool isEmptyFront(deque *deq) {
    return deq->frontSize == 0;
}

// Function to check if deque is empty at the back
bool isEmptyBack(deque *deq) {
    return deq->backSize == 0;
}

// Function to add an element at the back of the deque
void pushBack(deque *deq, unsigned char v) {
    deq->back = (unsigned char *)realloc(deq->back, (deq->backSize + 1) * sizeof(unsigned char));
    deq->back[deq->backSize++] = v;
}

// Function to add an element at the front of the deque
void pushFront(deque *deq, unsigned char v) {
    deq->front = (unsigned char *)realloc(deq->front, (deq->frontSize + 1) * sizeof(unsigned char));
    deq->front[deq->frontSize++] = v;
}

// Function to remove an element from the back of the deque and return it
bool popBack(deque *deq, unsigned char *v) {
    if (!isEmptyBack(deq)) {
        *v = deq->back[--deq->backSize];
        return true;
    } else if (!isEmptyFront(deq)) {
        *v = deq->front[0];
        memmove(deq->front, deq->front + 1, --deq->frontSize);
        return true;
    }
    return false;
}

// Function to remove an element from the front of the deque and return it
bool popFront(deque *deq, unsigned char *v) {
    if (!isEmptyFront(deq)) {
        *v = deq->front[--deq->frontSize];
        return true;
    } else if (!isEmptyBack(deq)) {
        *v = deq->back[0];
        memmove(deq->back, deq->back + 1, --deq->backSize);
        return true;
    }
    return false;
}

// Function to get an element from the deque by its index
unsigned char get(deque *deq, int idx) {
    int tot = deq->frontSize + deq->backSize;
    if (idx < tot) {
        if (idx < deq->frontSize) {
            return deq->front[deq->frontSize - 1 - idx];
        } else {
            return deq->back[idx - deq->frontSize];
        }
    }
    return 0; // Return 0 if index is invalid
}

// Function to reverse a given string
void rev(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

// Structure to hold operations
typedef struct {
    bool rev;
    bool front;
    unsigned char c;
} op;

int main() {
    // Read the input string S from the standard input
    char S[100001];
    scanf("%s", S);
    
    // Read the number of operations Q from the standard input
    int Q;
    scanf("%d", &Q);
    
    // Initialize an array of operations ops with the given size
    op *ops = (op *)malloc(Q * sizeof(op));
    
    // Read the operations one by one and store them in the ops array
    for (int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            ops[i].rev = true;
        } else {
            int f;
            scanf("%d %c", &f, &ops[i].c);
            ops[i].front = (f == 1);
        }
    }
    
    // Initialize an array of sums sum with the given size
    int *sum = (int *)malloc((Q + 1) * sizeof(int));
    sum[Q] = 0;
    
    // Iterate through the remaining operations and calculate their sums
    for (int i = Q - 1; i >= 0; i--) {
        if (ops[i].rev) {
            sum[i] = sum[i + 1] + 1;
        } else {
            sum[i] = sum[i + 1];
        }
    }
    
    // If the sum of the first operation is odd, reverse the input string
    if (sum[0] % 2 == 1) {
        rev(S);
    }
    
    // Initialize an empty deque deq
    deque *deq = createDeque();
    
    // Iterate through the operations and process them based on their type
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) {
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    pushFront(deq, ops[i].c);
                } else {
                    pushBack(deq, ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    pushBack(deq, ops[i].c);
                } else {
                    pushFront(deq, ops[i].c);
                }
            }
        }
    }
    
    // Write the result to the standard output
    for (int i = deq->frontSize - 1; i >= 0; i--) {
        printf("%c", deq->front[i]);
    }
    
    printf("%s", S);
    
    for (int i = 0; i < deq->backSize; i++) {
        printf("%c", deq->back[i]);
    }
    
    printf("\n");
    
    // Free allocated memory
    free(deq->front);
    free(deq->back);
    free(deq);
    free(ops);
    free(sum);
    
    return 0;
}

// <END-OF-CODE>
