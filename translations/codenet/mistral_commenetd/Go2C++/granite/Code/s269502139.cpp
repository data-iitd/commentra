

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Define a node structure with key, previous and next pointers
struct Node {
	int32_t key;
	Node* prev;
	Node* next;
};

// Recursive function to print the linked list in reverse order
void rPrint(Node* n, std::stringstream& buf) {
	buf << n->key;
	if (n->next!= nullptr) {
		// Recursively call rPrint function for next node
		buf << " ";
		rPrint(n->next, buf);
	}
}

// Function to delete a node from the linked list
void deleteNode(Node* n, Node*& first, Node*& last) {
	// Base case: if node is the first and last node
	if (n->prev == nullptr && n->next == nullptr) {
		first = nullptr;
		last = nullptr;
		return;
	}

	// Base case: if node is the first node
	if (n->prev == nullptr) {
		first = n->next;
		n->next->prev = nullptr;
		return;
	}

	// Base case: if node is the last node
	if (n->next == nullptr) {
		last = n->prev;
		n->prev->next = nullptr;
		return;
	}

	// General case: swap the pointers of previous and next nodes
	n->prev->next = n->next;
	n->next->prev = n->prev;
}

// Initialize a new node with given key
Node* initNode(int32_t key) {
	return new Node{
		key: key,
	};
}

int main() {
	// Initialize first and last pointers to nullptr
	Node* first = nullptr;
	Node* last = nullptr;

	// Read the first command from stdin
	std::string cmd;
	std::cin >> cmd;

	// Process each command until EOF is reached
	while (std::cin >> cmd) {
		// Switch statement to perform the corresponding action based on the command
		if (cmd == "deleteFirst") {
			// Delete the first node from the linked list
			deleteNode(first, first, last);
		} else if (cmd == "deleteLast") {
			// Delete the last node from the linked list
			deleteNode(last, first, last);
		} else {
			// Split the command into parts using space as delimiter
			std::vector<std::string> xcmd;
			std::stringstream ss(cmd);
			std::string token;
			while (std::getline(ss, token,'')) {
				xcmd.push_back(token);
			}

			// Parse the key from the second part of the command
			int32_t k = std::stoi(xcmd[1]);

			// Switch statement to perform the corresponding action based on the command prefix
			if (xcmd[0] == "delete") {
				// Search for the node with the given key in the linked list
				for (Node* a = first; a!= nullptr; a = a->next) {
					// If the current node matches the given key, delete it
					if (a->key == k) {
						deleteNode(a, first, last);
						break;
					}
				}
			} else if (xcmd[0] == "insert") {
				// Create a new node with the given key
				Node* n = initNode(k);
				// Insert the new node at the beginning of the linked list
				n->next = first;
				if (first!= nullptr) {
					first->prev = n;
				}

				// Update the first and last pointers
				first = n;
				if (last == nullptr) {
					last = n;
				}
			}
		}
	}

	// Print the linked list in reverse order
	std::stringstream buf;
	rPrint(first, buf);
	// Print the reversed linked list on the console
	std::cout << buf.str() << std::endl;
	// End of the code
	

