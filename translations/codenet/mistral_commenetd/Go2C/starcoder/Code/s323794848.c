
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a deque (double ended queue) type
typedef struct {
	char *front, *back; // Front and back pointers to store the elements
} deque;

// Function to check if deque is empty at the front
int isEmptyFront(deque *deq) {
	// Return true if the front pointer is NULL
	return deq->front == NULL;
}

// Function to check if deque is empty at the back
int isEmptyBack(deque *deq) {
	// Return true if the back pointer is NULL
	return deq->back == NULL;
}

// Function to add an element at the back of the deque
void pushBack(deque *deq, char v) {
	// Allocate memory for a new node
	char *node = (char *)malloc(sizeof(char));
	// Set the value of the node to the given value
	*node = v;
	// If the deque is empty at the back, set the back pointer to the new node
	if (isEmptyBack(deq)) {
		deq->back = node;
	} else { // Else, set the next pointer of the last node to the new node
		deq->back->next = node;
	}
	// Set the back pointer of the deque to the new node
	deq->back = node;
}

// Function to add an element at the front of the deque
void pushFront(deque *deq, char v) {
	// Allocate memory for a new node
	char *node = (char *)malloc(sizeof(char));
	// Set the value of the node to the given value
	*node = v;
	// If the deque is empty at the front, set the front pointer to the new node
	if (isEmptyFront(deq)) {
		deq->front = node;
	} else { // Else, set the previous pointer of the first node to the new node
		deq->front->prev = node;
	}
	// Set the front pointer of the deque to the new node
	deq->front = node;
}

// Function to remove an element from the back of the deque and return it
int popBack(deque *deq, char *v) {
	// If the deque is not empty at the back, remove the last node and return true
	int r = 1;
	if (!isEmptyBack(deq)) {
		// Set the value of the given pointer to the value of the last node
		*v = deq->back->value;
		// If the deque has only one node, set the front and back pointers to NULL
		if (deq->front == deq->back) {
			deq->front = deq->back = NULL;
		} else { // Else, set the back pointer to the previous node
			deq->back = deq->back->prev;
		}
		// Free the last node
		free(deq->back->next);
		deq->back->next = NULL;
	} else if (!isEmptyFront(deq)) { // If the deque is empty at the back but not at the front
		// Set the value of the given pointer to the value of the first node
		*v = deq->front->value;
		// Set the front pointer to the next node
		deq->front = deq->front->next;
		// Free the first node
		free(deq->front->prev);
		deq->front->prev = NULL;
	} else { // If the deque is empty at both front and back
		r = 0; // Return false
	}
	return r;
}

// Function to remove an element from the front of the deque and return it
int popFront(deque *deq, char *v) {
	// If the deque is not empty at the front, remove the first node and return true
	int r = 1;
	if (!isEmptyFront(deq)) {
		// Set the value of the given pointer to the value of the first node
		*v = deq->front->value;
		// If the deque has only one node, set the front and back pointers to NULL
		if (deq->front == deq->back) {
			deq->front = deq->back = NULL;
		} else { // Else, set the front pointer to the next node
			deq->front = deq->front->next;
		}
		// Free the first node
		free(deq->front->prev);
		deq->front->prev = NULL;
	} else if (!isEmptyBack(deq)) { // If the deque is empty at the front but not at the back
		// Set the value of the given pointer to the value of the last node
		*v = deq->back->value;
		// Set the back pointer to the previous node
		deq->back = deq->back->prev;
		// Free the last node
		free(deq->back->next);
		deq->back->next = NULL;
	} else { // If the deque is empty at both front and back
		r = 0; // Return false
	}
	return r;
}

// Function to get an element from the deque by its index
char get(deque *deq, int idx) {
	// Calculate the total length of the deque
	int tot = 0;
	if (!isEmptyFront(deq)) {
		tot += deq->front->length;
	}
	if (!isEmptyBack(deq)) {
		tot += deq->back->length;
	}
	// If the index is valid, return the corresponding element
	char v = '\0';
	if (idx < tot) {
		// Initialize the current node to the front node
		char *node = deq->front;
		// Iterate through the deque from the front to the back
		for (int i = 0; i < idx; i++) {
			// If the current node is not the last node, set the current node to the next node
			if (node->next!= NULL) {
				node = node->next;
			}
		}
		// Set the value of the given pointer to the value of the current node
		v = node->value;
	}
	return v;
}

// Function to reverse a given string
char *rev(char *s) {
	// Calculate the length of the given string
	int len = strlen(s);
	// Allocate memory for a new string
	char *r = (char *)malloc(sizeof(char) * len);
	// Initialize the indices i and j
	int i = len - 1, j = 0;
	// Iterate through the string from the end to the beginning
	for (i; i >= 0; i--) {
		// Store the character at index i in the reverse string
		r[j] = s[i];
		// Increment j
		j++;
	}
	// Return the reversed string
	return r;
}

// Main function to read input and process it
int main() {
	// Read the input string S from the standard input
	char *S = (char *)malloc(sizeof(char));
	scanf("%s", S);
	// Read the number of operations Q from the standard input
	int Q;
	scanf("%d", &Q);
	// Initialize an array of operations ops with the given size
	op *ops = (op *)malloc(sizeof(op) * Q);
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
	int *sum = (int *)malloc(sizeof(int) * (Q + 1));
	// Initialize the sum of the first operation
	sum[0] = 0;
	// Iterate through the remaining operations and calculate their sums
	for (int i = Q - 1; i >= 0; i--) {
		// If the current operation is to reverse the string, increment the previous sum
		if (ops[i].rev) {
			sum[i - 1] = sum[i] + 1;
		} else {
			// Else, set the previous sum to the current sum
			sum[i - 1] = sum[i];
		}
	}
	// If the sum of the first operation is odd, reverse the input string
	if (sum[0] % 2 == 1) {
		S = rev(S);
	}
	// Initialize an empty deque deq
	deque deq;
	// Set the front and back pointers of the deque to NULL
	deq.front = deq.back = NULL;
	// Iterate through the operations and process them based on their type
	for (int i = 0; i < Q; i++) {
		// If the current operation is not to reverse the string
		if (!ops[i].rev) {
			// If the operation is to add a character at the front, process it accordingly
			if (ops[i].front) {
				// If the previous sum is odd, push the character to the front of the deque
				if (sum[i] % 2 == 1) {
					pushFront(&deq, ops[i].c);
				} else {
					pushBack(&deq, ops[i].c);
				}
			} else { // Else, process the operation to add a character at the end
				// If the previous sum is odd, push the character to the end of the deque
				if (sum[i] % 2 == 1) {
					pushBack(&deq, ops[i].c);
				} else {
					pushFront(&deq, ops[i].c);
				}
			}
		}
	}
	// Write the result to the standard output
	printf("%s", deq.front);
	// Write the input string to the standard output
	printf("%s", S);
	// Write the characters in the deque to the standard output
	printf("%s", deq.back);
	// Exit
	return 0;
}

