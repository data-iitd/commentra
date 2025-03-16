
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct node {
	int32_t key;
	node* prev;
	node* next;
};

void rPrint(node* n, stringstream& buf) {
	buf << n->key;
	if (n->next != NULL) {
		buf << " ";
		rPrint(n->next, buf);
	}
	return;
}

node* Delete(node* n, node* first, node* last) {
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

node* initNode(int32_t key) {
	node* n = new node();
	n->key = key;
	return n;
}

int main() {
	string cmd;
	node* first = NULL;
	node* last = NULL;
	while (getline(cin, cmd)) {
		stringstream ss(cmd);
		string xcmd;
		ss >> xcmd;
		int32_t k;
		ss >> k;
		switch (xcmd[0]) {
		case 'd':
			if (xcmd == "deleteFirst") {
				first = Delete(first, first, last);
			}
			else {
				for (node* a = first; a != NULL; a = a->next) {
					if (a->key == k) {
						first = Delete(a, first, last);
						break;
					}
				}
			}
			break;
		case 'i':
			node* n = initNode(k);
			n->next = first;
			if (first != NULL) {
				first->prev = n;
			}

			first = n;
			if (last == NULL) {
				last = n;
			}
			break;
		}
	}
	stringstream buf;
	rPrint(first, buf);
	cout << buf.str() << endl;
	return 0;
}

