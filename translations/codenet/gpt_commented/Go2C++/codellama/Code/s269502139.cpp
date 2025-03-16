
#include <iostream>
#include <string>
#include <sstream>

// Define a doubly linked list node structure
struct node {
	int32_t key; // The value of the node
	node* prev; // Pointer to the previous node
	node* next; // Pointer to the next node
};

// Method to recursively print the keys of the linked list starting from the current node
void rPrint(node* n, std::stringstream& buf) {
	buf << n->key; // Append the current node's key to the buffer
	if (n->next != nullptr) {
		buf << " "; // Add a space if there is a next node
		rPrint(n->next, buf); // Recursively print the next node
	}
	return;
}

// Method to delete the current node from the linked list
std::pair<node*, node*> Delete(node* n, node* first, node* last) {
	if (n->prev != nullptr && n->next != nullptr) {
		// Node is in the middle; update pointers of adjacent nodes
		n->prev->next = n->next;
		n->next->prev = n->prev;
		return std::make_pair(first, last); // Return unchanged first and last pointers
	}

	if (n->next == nullptr && n->prev == nullptr) {
		// Node is the only node in the list
		return std::make_pair(nullptr, nullptr); // Return nil for both first and last
	}

	if (n->prev == nullptr) {
		// Node is the first node
		first = n->next; // Update first to the next node
		n->next->prev = nullptr; // Set the previous pointer of the new first node to nil
	}

	if (n->next == nullptr) {
		// Node is the last node
		last = n->prev; // Update last to the previous node
		n->prev->next = nullptr; // Set the next pointer of the new last node to nil
	}

	return std::make_pair(first, last); // Return updated first and last pointers
}

// Function to initialize a new node with a given key
node* initNode(int32_t key) {
	node* n = new node();
	n->key = key; // Set the key of the new node
	return n;
}

// Main function to execute the program
int main() {
	std::string line; // Initialize a string to read input from standard input
	node* first = nullptr; // Initialize pointers for the first and last nodes of the list
	node* last = nullptr;
	std::getline(std::cin, line); // Read the first line of input (not used)

	// Loop to process each command from the input
	while (std::getline(std::cin, line)) {
		std::string cmd = line; // Get the current command
		if (cmd == "deleteFirst") {
			// Command to delete the first node
			std::tie(first, last) = Delete(first, first, last);
		} else if (cmd == "deleteLast") {
			// Command to delete the last node
			std::tie(first, last) = Delete(last, first, last);
		} else {
			// Handle commands that involve inserting or deleting specific keys
			std::stringstream ss(cmd); // Split the command into parts
			int32_t k; // Initialize an integer to store the key
			ss >> k;
			if (ss.fail()) {
				std::cerr << "Error: Invalid command" << std::endl;
				return 1;
			}

			switch (cmd[0]) {
			case 'd':
				// Command to delete a node with a specific key
				for (node* a = first; a != nullptr; a = a->next) {
					if (a->key == k) {
						std::tie(first, last) = Delete(a, first, last); // Delete the node and update first and last
						break;
					}
				}
				break;
			case 'i':
				// Command to insert a new node at the beginning of the list
				node* n = initNode(k); // Initialize a new node
				n->next = first; // Set the new node's next pointer to the current first node
				if (first != nullptr) {
					first->prev = n; // Update the previous pointer of the current first node
				}

				first = n; // Update first to the new node
				if (last == nullptr) {
					last = n; // If the list was empty, set last to the new node
				}
				break;
			default:
				std::cerr << "Error: Invalid command" << std::endl;
				return 1;
			}
		}
	}
	std::stringstream buf;
	rPrint(first, buf); // Print the keys of the linked list starting from the first node
	std::cout << buf.str() << std::endl; // Output the result
	return 0;
}

