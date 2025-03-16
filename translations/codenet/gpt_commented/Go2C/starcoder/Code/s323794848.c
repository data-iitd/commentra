

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
	char *newBack = (char *)malloc(sizeof(char) * (strlen(deq->back) + 2));
	newBack[0] = v;
	strcpy(newBack + 1, deq->back);
	free(deq->back);
	deq->back = newBack;
}

// Push a byte to the front of the deque.
void pushFront(deque *deq, char v) {
	char *newFront = (char *)malloc(sizeof(char) * (strlen(deq->front) + 2));
	strcpy(newFront + 1, deq->front);
	newFront[0] = v;
	free(deq->front);
	deq->front = newFront;
}

// Pop a byte from the back of the deque, or from the front if the back is empty.
int popBack(deque *deq, char *v) {
	int r = 1;
	if (deq->back == NULL) {
		if (deq->front == NULL) {
			r = 0; // Return false if both front and back are empty.
		} else {
			*v = deq->front[0];
			deq->front = deq->front + 1;
		}
	} else {
		*v = deq->back[strlen(deq->back) - 1];
		deq->back = deq->back[:strlen(deq->back) - 1];
	}
	return r;
}

// Pop a byte from the front of the deque, or from the back if the front is empty.
int popFront(deque *deq, char *v) {
	int r = 1;
	if (deq->front == NULL) {
		if (deq->back == NULL) {
			r = 0; // Return false if both front and back are empty.
		} else {
			*v = deq->back[0];
			deq->back = deq->back + 1;
		}
	} else {
		*v = deq->front[strlen(deq->front) - 1];
		deq->front = deq->front[:strlen(deq->front) - 1];
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
	char *r = (char *)malloc(sizeof(char) * strlen(s));
	int i, j;
	for (i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
		r[j] = s[i];
	}
	return r;
}

// Main function to execute the program logic.
int main(void) {
	char *S;
	scanf("%s", &S); // Read the initial string S.
	int Q;
	scanf("%d", &Q); // Read the number of operations Q.
	op *ops = (op *)malloc(sizeof(op) * Q); // Create a slice to hold operations.

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
	int *sum = (int *)malloc(sizeof(int) * (Q + 1));
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
	FILE *wtr = stdout;
	// Output the characters in the correct order.
	for (int i = strlen(deq.front) - 1; i >= 0; i--) {
		fprintf(wtr, "%c", deq.front[i]); // Print front characters in reverse order.
	}
	for (int i = 0; i < strlen(S); i++) {
		fprintf(wtr, "%c", S[i]); // Print the original string S.
	}
	for (int i = 0; i < strlen(deq.back); i++) {
		fprintf(wtr, "%c", deq.back[i]); // Print back characters in order.
	}
	fprintf(wtr, "\n"); // Print a newline at the end.
	return 0;
}

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
	char *newBack = (char *)malloc(sizeof(char) * (strlen(deq->back) + 2));
	newBack[0] = v;
	strcpy(newBack + 1, deq->back);
	free(deq->back);
	deq->back = newBack;
}

// Push a byte to the front of the deque.
void pushFront(deque *deq, char v) {
	char *newFront = (char *)malloc(sizeof(char) * (strlen(deq->front) + 2));
	strcpy(newFront + 1, deq->front);
	newFront[0] = v;
	free(deq->front);
	deq->front = newFront;
}

// Pop a byte from the back of the deque, or from the front if the back is empty.
int popBack(deque *deq, char *v) {
	int r = 1;
	if (deq->back == NULL) {
		if (deq->front == NULL) {
			r = 0; // Return false if both front and back are empty.
		} else {
			*v = deq->front[0];
			deq->front = deq->front + 1;
		}
	} else {
		*v = deq->back[strlen(deq->back) - 1];
		deq->back = deq->back[:strlen(deq->back) - 1];
	}
	return r;
}

// Pop a byte from the front of the deque, or from the back if the front is empty.
int popFront(deque *deq, char *v) {
	int r = 1;
	if (deq->front == NULL) {
		if (deq->back == NULL) {
			r = 0; // Return false if both front and back are empty.
		} else {
			*v = deq->back[0];
			deq->back = deq->back + 1;
		}
	} else {
		*v = deq->front[strlen(deq->front) - 1];
		deq->front = deq->front[:strlen(deq->front) - 1];
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
	char *r = (char *)malloc(sizeof(char) * strlen(s));
	int i, j;
	for (i = strlen(s) - 1, j = 0; i >= 0; i--, j++) {
		r[j] = s[i];
	}
	return r;
}

// Main function to execute the program logic.
int main(void) {
	char *S;
	scanf("%s", &S); // Read the initial string S.
	int Q;
	scanf("%d", &Q); // Read the number of operations Q.
	op *ops = (op *)malloc(sizeof(op) * Q); // Create a slice to hold operations.

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
	int *sum = (int *)malloc(sizeof(int) * (Q + 1));
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
	FILE *wtr = stdout;
	// Output the characters in the correct order.
	for (int i = strlen(deq.front) - 1; i >= 0; i--) {
		fprintf(wtr, "%c", deq.front[i]); // Print front characters in reverse order.
	}
	for (int i = 0; i < strlen(S); i++) {
		fprintf(wtr, "%c", S[i]); // Print the original string S.
	}
	for (int i = 0; i < strlen(deq.back); i++) {
		fprintf(wtr, "%c", deq.back[i]); // Print back characters in order.
	}
	fprintf(wtr, "\n"); // Print a newline at the end.
	return 0;
}

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
	char *newBack = (char *)malloc(sizeof(char) * (strlen(deq->back) + 2));
	newBack[0] = v;
	strcpy(newBack + 1, deq->back);
	free(deq->back)