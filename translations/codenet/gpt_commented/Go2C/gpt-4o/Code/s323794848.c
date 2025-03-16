#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a deque structure with two arrays to represent the front and back.
typedef struct {
    unsigned char *front;
    unsigned char *back;
    int front_size;
    int back_size;
} deque;

// Check if the front of the deque is empty.
int isEmptyFront(deque *deq) {
    return deq->front_size == 0;
}

// Check if the back of the deque is empty.
int isEmptyBack(deque *deq) {
    return deq->back_size == 0;
}

// Push a byte to the back of the deque.
void pushBack(deque *deq, unsigned char v) {
    deq->back = realloc(deq->back, (deq->back_size + 1) * sizeof(unsigned char));
    deq->back[deq->back_size++] = v;
}

// Push a byte to the front of the deque.
void pushFront(deque *deq, unsigned char v) {
    deq->front = realloc(deq->front, (deq->front_size + 1) * sizeof(unsigned char));
    deq->front[deq->front_size++] = v;
}

// Pop a byte from the back of the deque, or from the front if the back is empty.
int popBack(deque *deq, unsigned char *v) {
    if (!isEmptyBack(deq)) {
        *v = deq->back[--deq->back_size];
        deq->back = realloc(deq->back, deq->back_size * sizeof(unsigned char));
        return 1;
    } else if (!isEmptyFront(deq)) {
        *v = deq->front[0];
        memmove(deq->front, deq->front + 1, --deq->front_size);
        deq->front = realloc(deq->front, deq->front_size * sizeof(unsigned char));
        return 1;
    }
    return 0; // Return false if both front and back are empty.
}

// Pop a byte from the front of the deque, or from the back if the front is empty.
int popFront(deque *deq, unsigned char *v) {
    if (!isEmptyFront(deq)) {
        *v = deq->front[--deq->front_size];
        deq->front = realloc(deq->front, deq->front_size * sizeof(unsigned char));
        return 1;
    } else if (!isEmptyBack(deq)) {
        *v = deq->back[0];
        memmove(deq->back, deq->back + 1, --deq->back_size);
        deq->back = realloc(deq->back, deq->back_size * sizeof(unsigned char));
        return 1;
    }
    return 0; // Return false if both front and back are empty.
}

// Get a byte at a specific index in the deque.
unsigned char get(deque *deq, int idx) {
    int tot = deq->front_size + deq->back_size;
    if (idx < tot) {
        if (idx < deq->front_size) {
            return deq->front[deq->front_size - 1 - idx]; // Access from the front.
        } else {
            return deq->back[idx - deq->front_size]; // Access from the back.
        }
    }
    return 0; // Return 0 if index is out of bounds.
}

// Define an operation structure to hold the operation type and character.
typedef struct {
    int rev, front;
    unsigned char c;
} op;

// Reverse a string and return the reversed version.
void rev(char *s, char *r) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        r[i] = s[len - 1 - i];
    }
    r[len] = '\0'; // Null-terminate the reversed string.
}

// Main function to execute the program logic.
int main() {
    char S[100001]; // Assuming the maximum length of S is 100000.
    scanf("%s", S); // Read the initial string S.
    int Q;
    scanf("%d", &Q); // Read the number of operations Q.
    op *ops = malloc(Q * sizeof(op)); // Create an array to hold operations.

    // Read each operation and populate the ops array.
    for (int i = 0; i < Q; i++) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            ops[i].rev = 1; // Mark operation as reverse.
        } else {
            int f;
            scanf("%d %c", &f, &ops[i].c); // Read front/back flag and character.
            ops[i].front = (f == 1); // Mark operation as front insertion.
        }
    }

    // Prepare a sum array to track the number of reversals.
    int *sum = malloc((Q + 1) * sizeof(int));
    sum[Q] = 0; // Initialize the last element.
    for (int i = Q - 1; i >= 1; i--) {
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1; // Increment count if operation is reverse.
        } else {
            sum[i - 1] = sum[i]; // Carry forward the count if not reverse.
        }
    }

    // Reverse the string S if the total number of reversals is odd.
    char reversedS[100001];
    if (sum[0] % 2 == 1) {
        rev(S, reversedS);
        strcpy(S, reversedS);
    }

    deque deq = {NULL, NULL, 0, 0}; // Initialize a deque to manage character insertions.
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) { // Process only non-reverse operations.
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    pushBack(&deq, ops[i].c); // Push to back if the reversal count is odd.
                } else {
                    pushFront(&deq, ops[i].c); // Push to front if the reversal count is even.
                }
            } else {
                if (sum[i] % 2 == 1) {
                    pushFront(&deq, ops[i].c); // Push to front if the reversal count is odd.
                } else {
                    pushBack(&deq, ops[i].c); // Push to back if the reversal count is even.
                }
            }
        }
    }

    // Output the characters in the correct order.
    for (int i = deq.front_size - 1; i >= 0; i--) {
        printf("%c", deq.front[i]); // Print front characters in reverse order.
    }
    printf("%s", S); // Print the original string S.
    for (int i = 0; i < deq.back_size; i++) {
        printf("%c", deq.back[i]); // Print back characters in order.
    }
    printf("\n"); // Print a newline at the end.

    // Free allocated memory.
    free(deq.front);
    free(deq.back);
    free(ops);
    free(sum);

    return 0;
}

// <END-OF-CODE>
