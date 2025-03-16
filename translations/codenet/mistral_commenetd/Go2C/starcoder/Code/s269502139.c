
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure with key, previous and next pointers
typedef struct node {
	int32_t key;
	struct node *prev;
	struct node *next;
} node;

// Recursive function to print the linked list in reverse order
void rPrint(node *n, char *buf) {
	// Append the key to the buffer
	strcat(buf, " ");
	strcat(buf, (char *) &n->key);
	// Recursively call rPrint function for next node
	if (n->next!= NULL) {
		rPrint(n->next, buf);
	}
	// Return from the function
	return;
}

// Function to delete a node from the linked list
node *Delete(node *n, node *first, node *last) {
	// Base case: if node is the first and last node
	if (n->prev == NULL && n->next == NULL) {
		return NULL;
	}

	// Base case: if node is the first node
	if (n->prev == NULL) {
		first = n->next;
		n->next->prev = NULL;
		return first;
	}

	// Base case: if node is the last node
	if (n->next == NULL) {
		last = n->prev;
		n->prev->next = NULL;
		return first;
	}

	// General case: swap the pointers of previous and next nodes
	n->prev->next = n->next;
	n->next->prev = n->prev;
	// Return the first and last nodes after deletion
	return first;
}

// Initialize a new node with given key
node *initNode(int32_t key) {
	node *n = (node *) malloc(sizeof(node));
	n->key = key;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

// Main function to read commands from stdin and perform the corresponding actions
int main() {
	// Initialize standard input scanner
	char cmd[100];
	scanf("%s", cmd);

	// Initialize first and last pointers to NULL
	node *first = NULL;
	node *last = NULL;

	// Process each command until EOF is reached
	while (strcmp(cmd, "EOF")!= 0) {
		// Switch statement to perform the corresponding action based on the command
		if (strcmp(cmd, "deleteFirst") == 0) {
			// Delete the first node from the linked list
			first = Delete(first, first, last);
		} else if (strcmp(cmd, "deleteLast") == 0) {
			// Delete the last node from the linked list
			first = Delete(last, first, last);
		} else {
			// Split the command into parts using space as delimiter
			char *xcmd = strdup(cmd);
			char *token = strtok(xcmd, " ");
			// Parse the key from the second part of the command
			int32_t k = atoi(token);
			// Convert the key to int32 type
			int32_t k32 = (int32_t) k;
			// Switch statement to perform the corresponding action based on the command prefix
			if (strcmp(token, "delete") == 0) {
				// Search for the node with the given key in the linked list
				node *a = first;
				while (a!= NULL) {
					// If the current node matches the given key, delete it
					if (a->key == k32) {
						first = Delete(a, first, last);
						break;
					}
					a = a->next;
				}
			} else if (strcmp(token, "insert") == 0) {
				// Create a new node with the given key
				node *n = initNode(k32);
				// Insert the new node at the beginning of the linked list
				n->next = first;
				if (first!= NULL) {
					first->prev = n;
				}

				// Update the first and last pointers
				first = n;
				if (last == NULL) {
					last = n;
				}
			}
			free(xcmd);
		}
		scanf("%s", cmd);
	}
	// Print the linked list in reverse order
	char buf[10000];
	strcpy(buf, "");
	rPrint(first, buf);
	// Print the reversed linked list on the console
	printf("%s", buf);
	// End of the code
	return 0;
}

