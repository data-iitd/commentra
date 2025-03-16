
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int key;
	struct node *prev;
	struct node *next;
} node;

void rPrint(node *n, char *buf) {
	sprintf(buf, "%d", n->key);
	if (n->next != NULL) {
		strcat(buf, " ");
		rPrint(n->next, buf);
	}
	return;
}

node *initNode(int key) {
	node *n = (node *)malloc(sizeof(node));
	n->key = key;
	return n;
}

node *delete(node *n, node *first, node *last) {
	if (n->prev != NULL && n->next != NULL) {
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

int main() {
	char cmd[100];
	node *first = NULL;
	node *last = NULL;
	while (scanf("%s", cmd) != EOF) {
		if (strcmp(cmd, "deleteFirst") == 0) {
			first = delete(first, first, last);
		} else if (strcmp(cmd, "deleteLast") == 0) {
			last = delete(last, first, last);
		} else {
			int key;
			sscanf(cmd, "%s %d", cmd, &key);
			node *n = initNode(key);
			n->next = first;
			if (first != NULL) {
				first->prev = n;
			}

			first = n;
			if (last == NULL) {
				last = n;
			}
		}
	}
	char buf[1000];
	rPrint(first, buf);
	printf("%s\n", buf);
	return 0;
}

