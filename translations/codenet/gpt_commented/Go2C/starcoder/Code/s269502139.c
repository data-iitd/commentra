

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a doubly linked list node structure
typedef struct node {
	int32_t key; // The value of the node
	struct node *prev; // Pointer to the previous node
	struct node *next; // Pointer to the next node
} node;

// Method to recursively print the keys of the linked list starting from the current node
void rPrint(node *n, char *buf) {
	sprintf(buf, "%d", n->key); // Append the current node's key to the buffer
	if (n->next!= NULL) {
		strcat(buf, " "); // Add a space if there is a next node
		rPrint(n->next, buf); // Recursively print the next node
	}
	return;
}

// Method to delete the current node from the linked list
node *Delete(node *n, node *first, node *last) {
	if (n->prev!= NULL && n->next!= NULL) {
		// Node is in the middle; update pointers of adjacent nodes
		n->prev->next = n->next;
		n->next->prev = n->prev;
		return first; // Return unchanged first pointer
	}

	if (n->next == NULL && n->prev == NULL) {
		// Node is the only node in the list
		return NULL; // Return nil for first
	}

	if (n->prev == NULL) {
		// Node is the first node
		first = n->next; // Update first to the next node
		n->next->prev = NULL; // Set the previous pointer of the new first node to nil
	}

	if (n->next == NULL) {
		// Node is the last node
		last = n->prev; // Update last to the previous node
		n->prev->next = NULL; // Set the next pointer of the new last node to nil
	}

	return first; // Return updated first pointer
}

// Function to initialize a new node with a given key
node *initNode(int32_t key) {
	node *n = (node *)malloc(sizeof(node)); // Allocate memory for the new node
	n->key = key; // Set the key of the new node
	n->prev = NULL; // Set the previous pointer of the new node to nil
	n->next = NULL; // Set the next pointer of the new node to nil
	return n; // Return the new node
}

// Main function to execute the program
int main(void) {
	char cmd[100]; // Buffer to hold the current command
	node *first = NULL; // Pointer to the first node of the list
	node *last = NULL; // Pointer to the last node of the list

	// Loop to process each command from the input
	while (scanf("%s", cmd) == 1) {
		if (strcmp(cmd, "deleteFirst") == 0) {
			// Command to delete the first node
			first = Delete(first, first, last);
		} else if (strcmp(cmd, "deleteLast") == 0) {
			// Command to delete the last node
			first = Delete(last, first, last);
		} else {
			// Handle commands that involve inserting or deleting specific keys
			char *xcmd = strdup(cmd); // Make a copy of the command
			char *key = strtok(xcmd, " "); // Get the first part of the command
			int32_t k32 = atoi(key); // Convert the first part to an integer
			free(xcmd); // Free the copy of the command

			if (strcmp(key, "delete") == 0) {
				// Command to delete a node with a specific key
				node *a = first;
				while (a!= NULL) {
					if (a->key == k32) {
						first = Delete(a, first, last); // Delete the node and update first
						break;
					}
					a = a->next;
				}
			} else if (strcmp(key, "insert") == 0) {
				// Command to insert a new node at the beginning of the list
				node *n = initNode(k32); // Initialize a new node
				n->next = first; // Set the new node's next pointer to the current first node
				if (first!= NULL) {
					first->prev = n; // Update the previous pointer of the current first node
				}

				first = n; // Update first to the new node
				if (last == NULL) {
					last = n; // If the list was empty, set last to the new node
				}
			}
		}
	}

	char buf[100]; // Buffer to hold the keys of the linked list
	rPrint(first, buf); // Print the keys of the linked list starting from the first node
	printf("%s\n", buf); // Output the result
	return 0;
}

