
#include <iostream>
#include <string>
#include <sstream>

// Define a node structure with key, previous and next pointers
struct node {
	int32_t key;
	node* prev;
	node* next;
};

// Recursive function to print the linked list in reverse order
void rPrint(node* n, std::stringstream& buf) {
	buf << n->key;
	if (n->next != nullptr) {
		// Recursively call rPrint function for next node
		buf << " ";
		rPrint(n->next, buf);
	}
	// Return from the function
	return;
}

// Function to delete a node from the linked list
void Delete(node* n, node*& first, node*& last) {
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
	// Return the first and last nodes after deletion
	return;
}

// Initialize a new node with given key
node* initNode(int32_t key) {
	node* n = new node;
	n->key = key;
	return n;
}

// Main function to read commands from stdin and perform the corresponding actions
int main() {
	// Initialize first and last pointers to nullptr
	node* first = nullptr;
	node* last = nullptr;

	// Read the first command from stdin
	std::string cmd;
	std::getline(std::cin, cmd);

	// Process each command until EOF is reached
	while (std::cin) {
		// Switch statement to perform the corresponding action based on the command
		switch (cmd[0]) {
		case 'd':
			// Delete the first node from the linked list
			Delete(first, first, last);
			break;
		case 'i':
			// Split the command into parts using space as delimiter
			std::stringstream ss(cmd);
			std::string cmd2;
			ss >> cmd2;
			int32_t k;
			ss >> k;

			// Switch statement to perform the corresponding action based on the command prefix
			switch (cmd2[0]) {
			case 'd':
				// Search for the node with the given key in the linked list
				for (node* a = first; a != nullptr; a = a->next) {
					// If the current node matches the given key, delete it
					if (a->key == k) {
						Delete(a, first, last);
						break;
					}
				}
				break;
			case 'i':
				// Create a new node with the given key
				node* n = initNode(k);
				// Insert the new node at the beginning of the linked list
				n->next = first;
				if (first != nullptr) {
					first->prev = n;
				}

				// Update the first and last pointers
				first = n;
				if (last == nullptr) {
					last = n;
				}
				break;
			}
			break;
		}

		// Read the next command from stdin
		std::getline(std::cin, cmd);
	}
	// Print the linked list in reverse order
	std::stringstream buf;
	rPrint(first, buf);
	// Print the reversed linked list on the console
	std::cout << buf.str() << std::endl;
	// End of the code
	

