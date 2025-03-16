#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a doubly linked list node structure
struct node {
	int32_t key; // The value of the node
	node *prev;   // Pointer to the previous node
	node *next;   // Pointer to the next node
};

// Method to recursively print the keys of the linked list starting from the current node
void rPrint(node *n, string &buf) {
	buf += to_string(n->key); // Append the current node's key to the buffer
	if (n->next!= NULL) {
		buf += " "; // Add a space if there is a next node
		rPrint(n->next, buf); // Recursively print the next node
	}
	return;
}

// Method to delete the current node from the linked list
void deleteNode(node *n, node *&first, node *&last) {
	if (n->prev!= NULL && n->next!= NULL) {
		// Node is in the middle; update pointers of adjacent nodes
		n->prev->next = n->next;
		n->next->prev = n->prev;
		return;
	}

	if (n->next == NULL && n->prev == NULL) {
		// Node is the only node in the list
		first = last = NULL; // Update first and last pointers
		return;
	}

	if (n->prev == NULL) {
		// Node is the first node
		first = n->next; // Update first to the next node
		n->next->prev = NULL; // Set the previous pointer of the new first node to NULL
	}

	if (n->next == NULL) {
		// Node is the last node
		last = n->prev; // Update last to the previous node
		n->prev->next = NULL; // Set the next pointer of the new last node to NULL
	}

	return;
}

// Function to initialize a new node with a given key
node *initNode(int32_t key) {
	node *n = new node;
	n->key = key; // Set the key of the new node
	n->prev = n->next = NULL; // Initialize the previous and next pointers of the new node to NULL
	return n;
}

// Main function to execute the program
int main() {
	string cmd;
	cin >> cmd; // Read the first line of input (not used)

	// Loop to process each command from the input
	while (cin >> cmd) {
		if (cmd == "deleteFirst") {
			// Command to delete the first node
			deleteNode(first, first, last);
		} else if (cmd == "deleteLast") {
			// Command to delete the last node
			deleteNode(last, first, last);
		} else {
			// Handle commands that involve inserting or deleting specific keys
			vector<string> xcmd = split(cmd, " "); // Split the command into parts
			int32_t k = stoi(xcmd[1]); // Convert the second part to an integer
			node *n = initNode(k); // Initialize a new node
			if (xcmd[0] == "delete") {
				// Command to delete a node with a specific key
				for (node *a = first; a!= NULL; a = a->next) {
					if (a->key == k) {
						deleteNode(a, first, last); // Delete the node and update first and last
						break;
					}
				}
			} else if (xcmd[0] == "insert") {
				// Command to insert a new node at the beginning of the list
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
	string buf = "";
	rPrint(first, buf); // Print the keys of the linked list starting from the first node
	cout << buf << endl; // Output the result
	return 0;
}

