
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
		tree->root = new Node{key, nullptr, nullptr, nullptr};
		return;
	}

	Node* currentNode = tree->root;
	Node* prevNode = nullptr;
	while (currentNode != nullptr) {
		prevNode = currentNode;
		if (currentNode->key < key) {
			currentNode = currentNode->right;
		} else {
			currentNode = currentNode->left;
		}
	}

	Node* newNode = new Node{key, prevNode, nullptr, nullptr};
	if (prevNode->key < key) {
		prevNode->right = newNode;
	} else {
		prevNode->left = newNode;
	}
}

void print(Tree* tree) {
	vector<int> acc;
	if (tree->root == nullptr) {
		cout << endl;
		cout << endl;
	} else {
		cout << " " << join(visitInorder(tree->root, acc), " ") << endl;
		cout << " " << join(visitPreorder(tree->root, acc), " ") << endl;
	}
}

vector<int> visitPreorder(Node* node, vector<int> acc) {
	if (node == nullptr) {
		return acc;
	}
	acc.push_back(node->key);
	if (node->left != nullptr) {
		acc = visitPreorder(node->left, acc);
	}
	if (node->right != nullptr) {
		acc = visitPreorder(node->right, acc);
	}
	return acc;
}

vector<int> visitInorder(Node* node, vector<int> acc) {
	if (node == nullptr) {
		return acc;
	}
	if (node->left != nullptr) {
		acc = visitInorder(node->left, acc);
	}
	acc.push_back(node->key);
	if (node->right != nullptr) {
		acc = visitInorder(node->right, acc);
	}
	return acc;
}

string join(vector<int> is, string delim) {
	string s;
	for (int i = 0; i < is.size(); i++) {
		s += to_string(is[i]);
		if (i != is.size() - 1) {
			s += delim;
		}
	}
	return s;
}

int main() {
	int n;
	cin >> n;

	Tree* tree = new Tree{nullptr};
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "insert") {
			int key;
			cin >> key;
			insert(tree, key);
		} else if (command == "print") {
			print(tree);
		} else {
			cerr << "unknown command: " << command << endl;
		}
	}
}

