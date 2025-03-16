#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int key;
	struct node *prev;
	struct node *next;
} node;

void rPrint(node *n, char *buf) {
	if (n == NULL) {
		return;
	}
	sprintf(buf, "%d ", n->key);
	rPrint(n->next, buf);
}

void delete(node *n, node *first, node *last) {
	if (n->prev!= NULL && n->next!= NULL) {
		//swap
		n->prev->next = n->next;
		n->next->prev = n->prev;
		return;
	}

	if (n->next == NULL && n->prev == NULL) {
		return;
	}

	if (n->prev == NULL) {
		first = n->next;
		n->next->prev = NULL;
	}

	if (n->next == NULL) {
		last = n->prev;
		n->prev->next = NULL;
	}
}

int main() {
	node *first = NULL;
	node *last = NULL;
	char cmd[100];
	while (scanf("%s", cmd)!= EOF) {
		if (strcmp(cmd, "deleteFirst") == 0) {
			delete(first, first, last);
		} else if (strcmp(cmd, "deleteLast") == 0) {
			delete(last, first, last);
		} else {
			char *xcmd = strchr(cmd,'');
			int k = atoi(xcmd + 1);
			node *n = (node *) malloc(sizeof(node));
			n->key = k;
			n->next = first;
			if (first!= NULL) {
				first->prev = n;
			}

			first = n;
			if (last == NULL) {
				last = n;
			}

			if (strcmp(cmd, "delete") == 0) {
				for (node *a = first; a!= NULL; a = a->next) {
					if (a->key == k) {
						delete(a, first, last);
						break;
					}
				}
			} else if (strcmp(cmd, "insert") == 0) {
				;
			}
		}
	}
	char buf[10000];
	rPrint(first, buf);
	printf("%s", buf);
	return 0;
}

