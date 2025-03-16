
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct Node {
	int key;
	Node* parent;
	Node* left;
	Node* right;
};

struct Tree {
	Node* root;
};

void insert(Tree* tree, int key) {
	if (tree->root == nullptr) {
		tree->root = new Node{ key, nullptr, nullptr, nullptr };
		return;
	}

	Node* currentNode = tree->root;
	Node* prevNode = nullptr;
	while (currentNode!= nullptr) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right;
		} else {
			currentNode = currentNode->left;
		}
	}

	Node* newNode = new Node{ key, prevNode, nullptr, nullptr };
	if (prevNode->key < key) {
		prevNode->right = newNode;
	} else {
		prevNode->left = newNode;
	}
}

void print(Tree tree) {
	std::vector<int> acc;
	if (tree.root == nullptr) {
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
	} else {
		std::cout << " " << to_string(visitInorder(tree.root, acc)) << std::endl;
		std::cout << " " << to_string(visitPreorder(tree.root, acc)) << std::endl;
	}
}

std::vector<int> visitPreorder(Node* node, std::vector<int>& acc) {
	if (node == nullptr) {
		return acc;
	}
	acc.push_back(node->key);
	if (node->left!= nullptr) {
		acc = visitPreorder(node->left, acc);
	}
	if (node->right!= nullptr) {
		acc = visitPreorder(node->right, acc);
	}
	return acc;
}

std::vector<int> visitInorder(Node* node, std::vector<int>& acc) {
	if (node == nullptr) {
		return acc;
	}
	if (node->left!= nullptr) {
		acc = visitInorder(node->left, acc);
	}
	acc.push_back(node->key);
	if (node->right!= nullptr) {
		acc = visitInorder(node->right, acc);
	}
	return acc;
}

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	Tree tree;
	for (int i = 0; i < n; i++) {
		std::string command;
		std::cin >> command;
		if (command == "insert") {
			int key;
			std::cin >> key;
			insert(&tree, key);
		} else if (command == "print") {
			print(tree);
		} else {
			std::cerr << "unknown command: " << command << std::endl;
			return 1;
		}
	}

	return 0;
}

