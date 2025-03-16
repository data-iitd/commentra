
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a deque (double ended queue) type
typedef struct {
	char *front, *back; // Front and back pointers to store the elements
} deque;

// Function to check if deque is empty at the front
int isEmptyFront(deque *deq) {
	// Return true if the length of front pointer is zero
	return deq->front == NULL;
}

// Function to check if deque is empty at the back
int isEmptyBack(deque *deq) {
	// Return true if the length of back pointer is zero
	return deq->back == NULL;
}

// Function to add an element at the back of the deque
void pushBack(deque *deq, char v) {
	// Allocate memory for the new element
	char *new = (char *)malloc(sizeof(char));
	// Store the given character in the new element
	*new = v;
	// If the deque is empty at the back, set the back pointer to the new element
	if (isEmptyBack(deq)) {
		deq->back = new;
	} else {
		// Else, set the next pointer of the last element to the new element
		deq->back->next = new;
	}
	// Set the back pointer to the new element
	deq->back = new;
}

// Function to add an element at the front of the deque
void pushFront(deque *deq, char v) {
	// Allocate memory for the new element
	char *new = (char *)malloc(sizeof(char));
	// Store the given character in the new element
	*new = v;
	// If the deque is empty at the front, set the front pointer to the new element
	if (isEmptyFront(deq)) {
		deq->front = new;
	} else {
		// Else, set the next pointer of the new element to the front pointer
		new->next = deq->front;
	}
	// Set the front pointer to the new element
	deq->front = new;
}

// Function to remove an element from the back of the deque and return it
int popBack(deque *deq, char *v) {
	// If the deque is not empty at the back, pop the last element and return true
	int r = 1;
	if (!isEmptyBack(deq)) {
		*v = deq->back->data;
		deq->back = deq->back->next;
	} else if (!isEmptyFront(deq)) { // If the deque is empty at the back but not at the front
		*v = deq->front->data;       // Pop the first element
		deq->front = deq->front->next; // Update the front pointer
	} else {                       // If the deque is empty at both front and back
		r = 0;                      // Return false
	}
	return r;
}

// Function to remove an element from the front of the deque and return it
int popFront(deque *deq, char *v) {
	// If the deque is not empty at the front, pop the first element and return true
	int r = 1;
	if (!isEmptyFront(deq)) {
		*v = deq->front->data;
		deq->front = deq->front->next;
	} else if (!isEmptyBack(deq)) { // If the deque is empty at the front but not at the back
		*v = deq->back->data;       // Pop the last element
		deq->back = deq->back->next; // Update the back pointer
	} else {                       // If the deque is empty at both front and back
		r = 0;                      // Return false
	}
	return r;
}

// Function to get an element from the deque by its index
char get(deque *deq, int idx) {
	// Calculate the total length of the deque
	int tot = 0;
	char *p = deq->front;
	while (p != NULL) {
		tot++;
		p = p->next;
	}
	p = deq->back;
	while (p != NULL) {
		tot++;
		p = p->next;
	}
	// If the index is valid, return the corresponding element
	char v = 0;
	if (idx < tot) {
		if (idx < tot/2) {
			p = deq->front;
			while (p != NULL && idx > 0) {
				idx--;
				p = p->next;
			}
			v = p->data;
		} else {
			p = deq->back;
			while (p != NULL && idx > 0) {
				idx--;
				p = p->next;
			}
			v = p->data;
		}
	}
	return v;
}

// Function to reverse a given string
char *rev(char *s) {
	// Create a new string with the length of the given string
	char *r = (char *)malloc(sizeof(char)*strlen(s));
	// Initialize the indices i and j
	int i = strlen(s)-1, j = 0;
	// Iterate through the string from the end to the beginning
	while (i >= 0) {
		// Store the character at index i in the reverse string
		r[j] = s[i];
		// Increment j
		j++;
		// Decrement i
		i--;
	}
	// Return the reversed string
	return r;
}

// Main function to read input and process it
int main() {
	// Read the input string S from the standard input
	char *S = (char *)malloc(sizeof(char)*1000001);
	scanf("%s", S);
	// Read the number of operations Q from the standard input
	int Q;
	scanf("%d", &Q);
	// Initialize an array of operations ops with the given size
	struct op {
		int rev;
		int front;
		char c;
	} *ops = (struct op *)malloc(sizeof(struct op)*Q);
	// Read the operations one by one and store them in the ops array
	for (int i = 0; i < Q; i++) {
		// Read the type of operation (reverse or not)
		int q;
		scanf("%d", &q);
		// If the operation is to reverse the string, set the rev field to true
		if (q == 1) {
			ops[i].rev = 1;
		} else {
			// Else, read the front flag and the character c from the standard input
			int f;
			scanf("%d %c", &f, &ops[i].c);
			// Set the front field based on the front flag
			if (f == 1) {
				ops[i].front = 1;
			}
		}
	}
	// Initialize an array of sums sum with the given size
	int *sum = (int *)malloc(sizeof(int)*(Q+1));
	// Initialize the sum of the first operation
	sum[0] = 0;
	// Iterate through the remaining operations and calculate their sums
	for (int i = Q - 1; i >= 0; i--) {
		// If the current operation is not to reverse the string
		if (!ops[i].rev) {
			// If the operation is to add a character at the front, process it accordingly
			if (ops[i].front) {
				// If the previous sum is odd, push the character to the front of the deque
				if (sum[i]%2 == 1) {
					pushFront(&deq, ops[i].c);
				} else {
					pushBack(&deq, ops[i].c);
				}
			} else { // Else, process the operation to add a character at the end
				// If the previous sum is odd, push the character to the end of the deque
				if (sum[i]%2 == 1) {
					pushBack(&deq, ops[i].c);
				} else {
					pushFront(&deq, ops[i].c);
				}
			}
		}
		// If the sum of the current operation is odd, increment the previous sum
		sum[i-1] = sum[i] + (sum[i]%2);
	}
	// If the sum of the first operation is odd, reverse the input string
	if (sum[0]%2 == 1) {
		S = rev(S);
	}
	// Initialize an empty deque deq
	deque deq;
	deq.front = NULL;
	deq.back = NULL;
	// Iterate through the operations and process them based on their type
	for (int i = 0; i < Q; i++) {
		// If the current operation is not to reverse the string
		if (!ops[i].rev) {
			// If the operation is to add a character at the front, process it accordingly
			if (ops[i].front) {
				// If the previous sum is odd, push the character to the front of the deque
				if (sum[i]%2 == 1) {
					pushFront(&deq, ops[i].c);
				} else {
					pushBack(&deq, ops[i].c);
				}
			} else { // Else, process the operation to add a character at the end
				// If the previous sum is odd, push the character to the end of the deque
				if (sum[i]%2 == 1) {
					pushBack(&deq, ops[i].c);
				} else {
					pushFront(&deq, ops[i].c);
				}
			}
		}
	}
	// Write the result to the standard output
	for (int i = len(deq.front) - 1; i >= 0; i--) {
		printf("%c", deq.front[i]);
	}
	// Write the input string to the standard output
	printf("%s", S);
	// Write the characters in the deque to the standard output
	for (int i = 0; i < len(deq.back); i++) {
		printf("%c", deq.back[i]);
	}
	// Flush the buffer and exit
	printf("\n");
	return 0;
}

