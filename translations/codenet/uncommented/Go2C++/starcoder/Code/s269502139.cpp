#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
	int key;
	node *prev;
	node *next;
};

void rPrint(node *n, string &buf) {
	buf += to_string(n->key);
	if (n->next!= NULL) {
		buf += " ";
		rPrint(n->next, buf);
	}
}

void deleteNode(node *n, node *first, node *last) {
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
	string cmd;
	cin >> cmd;
	node *first = NULL;
	node *last = NULL;
	while (cin >> cmd) {
		if (cmd == "deleteFirst") {
			deleteNode(first, first, last);
		} else if (cmd == "deleteLast") {
			deleteNode(last, first, last);
		} else {
			vector<string> xcmd = split(cmd, " ");
			int k = atoi(xcmd[1].c_str());
			node *n = new node();
			n->key = k;
			n->next = first;
			if (first!= NULL) {
				first->prev = n;
			}

			first = n;
			if (last == NULL) {
				last = n;
			}

			if (xcmd[0] == "delete") {
				for (node *a = first; a!= NULL; a = a->next) {
					if (a->key == k) {
						deleteNode(a, first, last);
						break;
					}
				}
			}
		}
	}
	string buf;
	rPrint(first, buf);
	cout << buf << endl;
	return 0;
}

