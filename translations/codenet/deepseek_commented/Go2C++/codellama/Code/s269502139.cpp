
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Define the `node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
struct node {
	int32_t key;
	node* prev;
	node* next;
};

// Recursive Print Function
// The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
void rPrint(node* n, stringstream& buf) {
	buf << n->key << " ";
	if (n->next != NULL) {
		rPrint(n->next, buf);
	}
	return;
}

// Delete Method
// The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
void Delete(node* n, node*& first, node*& last) {
	if (n->prev != NULL && n->next != NULL) {
		//swap
		n->prev->next = n->next;
		n->next->prev = n->prev;
		return;
	}

	if (n->next == NULL && n->prev == NULL) {
		first = NULL;
		last = NULL;
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

	return;
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
node* initNode(int32_t key) {
	node* n = new node;
	n->key = key;
	return n;
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main() {
	string cmd;
	node* first = NULL;
	node* last = NULL;
	while (getline(cin, cmd)) {
		switch (cmd[0]) {
		case 'd':
			if (cmd == "deleteFirst") {
				Delete(first, first, last);
			}
			else if (cmd == "deleteLast") {
				Delete(last, first, last);
			}
			else {
				int32_t k = stoi(cmd.substr(6));
				for (node* a = first; a != NULL; a = a->next) {
					if (a->key == k) {
						Delete(a, first, last);
						break;
					}
				}
			}
			break;
		case 'i':
			int32_t k = stoi(cmd.substr(6));
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

