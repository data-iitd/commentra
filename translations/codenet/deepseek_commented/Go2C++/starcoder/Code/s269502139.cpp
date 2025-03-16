
#include <iostream>
#include <string>
#include <vector>

// Define the `node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
struct node {
	int32_t key;
	node *prev;
	node *next;
};

// Recursive Print Function
// The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
void rPrint(node *n, std::string &buf) {
	buf += std::to_string(n->key);
	if (n->next!= nullptr) {
		buf += " ";
		rPrint(n->next, buf);
	}
	return;
}

// Delete Method
// The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
node *Delete(node *n, node *first, node *last) {
	if (n->prev!= nullptr && n->next!= nullptr) {
		//swap
		n->prev->next = n->next;
		n->next->prev = n->prev;
		return first, last;
	}

	if (n->next == nullptr && n->prev == nullptr) {
		return nullptr, nullptr;
	}

	if (n->prev == nullptr) {
		first = n->next;
		n->next->prev = nullptr;
	}

	if (n->next == nullptr) {
		last = n->prev;
		n->prev->next = nullptr;
	}

	return first, last;
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
node *initNode(int32_t key) {
	return new node{
		key: key,
	};
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main() {
	std::string cmd;
	std::cin >> cmd;
	node *first = nullptr;
	node *last = nullptr;
	while (std::cin >> cmd) {
		if (cmd == "deleteFirst") {
			first, last = Delete(first, first, last);
		} else if (cmd == "deleteLast") {
			first, last = Delete(last, first, last);
		} else {
			std::vector<std::string> xcmd = split(cmd, " ");
			int32_t k = std::stoi(xcmd[1]);
			node *n = initNode(k);
			if (xcmd[0] == "delete") {
				for (node *a = first; a!= nullptr; a = a->next) {
					if (a->key == k) {
						first, last = Delete(a, first, last);
						break;
					}
				}
			} else if (xcmd[0] == "insert") {
				n->next = first;
				if (first!= nullptr) {
					first->prev = n;
				}

				first = n;
				if (last == nullptr) {
					last = n;
				}
			}
		}
	}
	std::string buf;
	rPrint(first, buf);
	std::cout << buf << std::endl;
	return 0;
}

// Split Function
// The `split` function splits a string into a vector of strings.
std::vector<std::string> split(std::string str, std::string delim) {
	std::vector<std::string> res;
	size_t pos = 0;
	while (true) {
		size_t found = str.find(delim, pos);
		if (found == std::string::npos) {
			res.push_back(str.substr(pos));
			break;
		}
		res.push_back(str.substr(pos, found - pos));
		pos = found + 1;
	}
	return res;
}

