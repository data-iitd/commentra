#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a doubly linked list node structure
typedef struct node {
	int key; // The value of the node
	struct node *prev; // Pointer to the previous node
	struct node *next; // Pointer to the next node
} node;

// Method to recursively print the keys of the linked list starting from the current node
void rPrint(node *n, char *buf) {
	sprintf(buf, "%d", n->key); // Append the current node's key to the buffer
	if (n->next != NULL) {
		strcat(buf, " "); // Add a space if there is a next node
		rPrint(n->next, buf); // Recursively print the next node
	}
	return;
}

// Method to delete the current node from the linked list
node *Delete(node *n, node **first, node **last) {
	if (n->prev != NULL && n->next != NULL) {
		// Node is in the middle; update pointers of adjacent nodes
		n->prev->next = n->next;
		n->next->prev = n->prev;
		return *first; // Return unchanged first and last pointers
	}

	if (n->next == NULL && n->prev == NULL) {
		// Node is the only node in the list
		*first = NULL; // Return nil for both first and last
		*last = NULL;
		return *first;
	}

	if (n->prev == NULL) {
		// Node is the first node
		*first = n->next; // Update first to the next node
		n->next->prev = NULL; // Set the previous pointer of the new first node to nil
	}

	if (n->next == NULL) {
		// Node is the last node
		*last = n->prev; // Update last to the previous node
		n->prev->next = NULL; // Set the next pointer of the new last node to nil
	}

	return *first; // Return updated first and last pointers
}

// Function to initialize a new node with a given key
node *initNode(int key) {
	node *n = (node *)malloc(sizeof(node)); // Allocate memory for the new node
	n->key = key; // Set the key of the new node
	n->prev = NULL; // Set the previous pointer of the new node to nil
	n->next = NULL; // Set the next pointer of the new node to nil
	return n; // Return the new node
}

// Main function to execute the program
int main() {
	char *cmd; // Declare a pointer to a string to store the current command
	node *first = NULL; // Initialize pointers for the first and last nodes of the list
	node *last = NULL;
	while (1) {
		cmd = (char *)malloc(sizeof(char) * 100); // Allocate memory for the command
		scanf("%s", cmd); // Read the current command
		if (strcmp(cmd, "deleteFirst") == 0) {
			// Command to delete the first node
			first = Delete(first, &first, &last);
		} else if (strcmp(cmd, "deleteLast") == 0) {
			// Command to delete the last node
			last = Delete(last, &first, &last);
		} else {
			// Handle commands that involve inserting or deleting specific keys
			int k = atoi(strtok(cmd, " ")); // Convert the second part to an integer
			if (strcmp(strtok(NULL, " "), "delete") == 0) {
				// Command to delete a node with a specific key
				for (node *a = first; a != NULL; a = a->next) {
					if (a->key == k) {
						first = Delete(a, &first, &last); // Delete the node and update first and last
						break;
					}
				}
			} else if (strcmp(strtok(NULL, " "), "insert") == 0) {
				// Command to insert a new node at the beginning of the list
				node *n = initNode(k); // Initialize a new node
				n->next = first; // Set the new node's next pointer to the current first node
				if (first != NULL) {
					first->prev = n; // Update the previous pointer of the current first node
				}

				first = n; // Update first to the new node
				if (last == NULL) {
					last = n; // If the list was empty, set last to the new node
				}
			}
		}
		free(cmd); // Free the memory allocated for the command
	}
	char buf[1000]; // Declare a buffer to store the result
	rPrint(first, buf); // Print the keys of the linked list starting from the first node
	printf("%s\n", buf); // Output the result
	return 0;
}


