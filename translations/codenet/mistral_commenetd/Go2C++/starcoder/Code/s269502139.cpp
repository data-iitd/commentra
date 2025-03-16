
#include <bits/stdc++.h>

using namespace std;

// Define a node structure with key, previous and next pointers
struct node {
	int32_t key;
	node *prev, *next;
};

// Recursive function to print the linked list in reverse order
void rPrint(node *n, string &buf) {
	buf += to_string(n->key);
	if (n->next!= NULL) {
		// Recursively call rPrint function for next node
		buf += " ";
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
	return new node{
		key: key,
	};
}

// Main function to read commands from stdin and perform the corresponding actions
int main() {
	// Initialize standard input scanner
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	// Initialize first and last pointers to NULL
	node *first = NULL, *last = NULL;

	// Read the first command from stdin
	string cmd;
	cin >> cmd;

	// Process each command until EOF is reached
	while (cin >> cmd) {
		// Switch statement to perform the corresponding action based on the command
		switch (cmd) {
		case "deleteFirst":
			// Delete the first node from the linked list
			first = Delete(first, first, last);
		case "deleteLast":
			// Delete the last node from the linked list
			first = Delete(last, first, last);
		default:
			// Split the command into parts using space as delimiter
			vector<string> xcmd = split(cmd, " ");
			// Parse the key from the second part of the command
			int32_t k = stoi(xcmd[1]);
			// Switch statement to perform the corresponding action based on the command prefix
			switch (xcmd[0]) {
			case "delete":
				// Search for the node with the given key in the linked list
				node *a = first;
				while (a!= NULL) {
					// If the current node matches the given key, delete it
					if (a->key == k) {
						first = Delete(a, first, last);
						break;
					}
					a = a->next;
				}
			case "insert":
				// Create a new node with the given key
				node *n = initNode(k);
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
		}
	}
	// Print the linked list in reverse order
	string buf = "";
	rPrint(first, buf);
	// Print the reversed linked list on the console
	cout << buf << endl;
	// End of the code
	return 0;
}

