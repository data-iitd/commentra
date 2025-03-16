#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a deque structure with two slices to represent the front and back.
typedef struct {
	char *front, *back;
} deque;

// Check if the front of the deque is empty.
int isEmptyFront(deque *deq) {
	return deq->front == NULL;
}

// Check if the back of the deque is empty.
int isEmptyBack(deque *deq) {
	return deq->back == NULL;
}

// Push a byte to the back of the deque.
void pushBack(deque *deq, char v) {
	deq->back = realloc(deq->back, (strlen(deq->back) + 2) * sizeof(char));
	deq->back[strlen(deq->back)] = v;
	deq->back[strlen(deq->back) + 1] = '\0';
}

// Push a byte to the front of the deque.
void pushFront(deque *deq, char v) {
	deq->front = realloc(deq->front, (strlen(deq->front) + 2) * sizeof(char));
	deq->front[strlen(deq->front)] = v;
	deq->front[strlen(deq->front) + 1] = '\0';
}

// Pop a byte from the back of the deque, or from the front if the back is empty.
int popBack(deque *deq, char *v) {
	int r = 1;
	if (!isEmptyBack(deq)) {
		*v = deq->back[strlen(deq->back) - 1];
		deq->back[strlen(deq->back) - 1] = '\0';
		deq->back = realloc(deq->back, strlen(deq->back) * sizeof(char));
	} else if (!isEmptyFront(deq)) {
		*v = deq->front[0];
		deq->front[0] = '\0';
		deq->front = realloc(deq->front, strlen(deq->front) * sizeof(char));
	} else {
		r = 0; // Return false if both front and back are empty.
	}
	return r;
}

// Pop a byte from the front of the deque, or from the back if the front is empty.
int popFront(deque *deq, char *v) {
	int r = 1;
	if (!isEmptyFront(deq)) {
		*v = deq->front[strlen(deq->front) - 1];
		deq->front[strlen(deq->front) - 1] = '\0';
		deq->front = realloc(deq->front, strlen(deq->front) * sizeof(char));
	} else if (!isEmptyBack(deq)) {
		*v = deq->back[0];
		deq->back[0] = '\0';
		deq->back = realloc(deq->back, strlen(deq->back) * sizeof(char));
	} else {
		r = 0; // Return false if both front and back are empty.
	}
	return r;
}

// Get a byte at a specific index in the deque.
char get(deque *deq, int idx) {
	int tot = strlen(deq->front) + strlen(deq->back);
	char v = '\0';
	if (idx < tot) {
		if (idx < strlen(deq->front)) {
			v = deq->front[strlen(deq->front) - 1 - idx]; // Access from the front.
		} else {
			v = deq->back[idx - strlen(deq->front)]; // Access from the back.
		}
	}
	return v;
}

// Define an operation structure to hold the operation type and character.
typedef struct {
	int rev, front;
	char c;
} op;

// Reverse a string and return the reversed version.
char *rev(char *s) {
	int i, j;
	char *r = malloc((strlen(s) + 1) * sizeof(char));
	for (i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
		r[j] = s[i];
	}
	r[j] = '\0';
	return r;
}

// Main function to execute the program logic.
int main() {
	char *S;
	scanf("%s", &S); // Read the initial string S.
	int Q;
	scanf("%d", &Q); // Read the number of operations Q.
	op *ops = malloc(Q * sizeof(op)); // Create a slice to hold operations.

	// Read each operation and populate the ops slice.
	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);
		if (q == 1) {
			ops[i].rev = 1; // Mark operation as reverse.
		} else {
			int f;
			scanf("%d %c", &f, &ops[i].c); // Read front/back flag and character.
			if (f == 1) {
				ops[i].front = 1; // Mark operation as front insertion.
			}
		}
	}

	// Prepare a sum array to track the number of reversals.
	int *sum = malloc((Q + 1) * sizeof(int));
	for (int i = Q - 1; i >= 1; i--) {
		if (ops[i].rev) {
			sum[i - 1] = sum[i] + 1; // Increment count if operation is reverse.
		} else {
			sum[i - 1] = sum[i]; // Carry forward the count if not reverse.
		}
	}

	// Reverse the string S if the total number of reversals is odd.
	if (sum[0] % 2 == 1) {
		S = rev(S);
	}

	deque deq; // Initialize a deque to manage character insertions.
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

	// Prepare to write the final result to standard output.
	for (int i = strlen(deq.front) - 1; i >= 0; i--) {
		printf("%c", deq.front[i]); // Print front characters in reverse order.
	}
	printf("%s", S); // Print the original string S.
	for (int i = 0; i < strlen(deq.back); i++) {
		printf("%c", deq.back[i]); // Print back characters in order.
	}
	printf("\n"); // Print a newline at the end.

	return 0;
}

