
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the `node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
typedef struct node {
	int32_t key;
	struct node *prev;
	struct node *next;
} node;

// Recursive Print Function
// The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
void rPrint(node *n, char *buf) {
	if (n == NULL) {
		return;
	}
	sprintf(buf, "%d ", n->key);
	rPrint(n->next, buf);
}

// Delete Method
// The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
node *Delete(node *n, node *first, node *last) {
	if (n->prev!= NULL && n->next!= NULL) {
		//swap
		n->prev->next = n->next;
		n->next->prev = n->prev;
		return first;
	}

	if (n->next == NULL && n->prev == NULL) {
		return NULL;
	}

	if (n->prev == NULL) {
		first = n->next;
		n->next->prev = NULL;
	}

	if (n->next == NULL) {
		last = n->prev;
		n->prev->next = NULL;
	}

	return first;
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
node *initNode(int32_t key) {
	node *n = (node *)malloc(sizeof(node));
	n->key = key;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main(int argc, char **argv) {
	node *first = NULL;
	node *last = NULL;
	char cmd[100];
	while (scanf("%s", cmd)!= EOF) {
		if (strcmp(cmd, "deleteFirst") == 0) {
			first = Delete(first, first, last);
		} else if (strcmp(cmd, "deleteLast") == 0) {
			first = Delete(last, first, last);
		} else {
			char *xcmd = cmd;
			char *arg = strsep(&xcmd, " ");
			int32_t k = atoi(arg);
			node *n = initNode(k);
			if (strcmp(xcmd, "delete") == 0) {
				for (node *a = first; a!= NULL; a = a->next) {
					if (a->key == k) {
						first = Delete(a, first, last);
						break;
					}
				}
			} else if (strcmp(xcmd, "insert") == 0) {
				n->next = first;
				if (first!= NULL) {
					first->prev = n;
				}
				first = n;
				if (last == NULL) {
					last = n;
				}
			}
		}
	}
	char buf[1000];
	rPrint(first, buf);
	printf("%s", buf);
	return 0;
}

