#include <iostream>
#include <string>
#include <vector>

using namespace std;

class node {
public:
	int key;
	node *parent;
	node *left;
	node *right;
};

class tree {
public:
	node *root;
	tree() {
		root = NULL;
	}
	void insert(int key) {
		if (root == NULL) {
			root = new node();
			root->key = key;
			return;
		}

		node *currentNode, *prevNode;
		currentNode = root;
		while (currentNode!= NULL) {
			prevNode = currentNode;
			if (currentNode->key < key) {
				currentNode = currentNode->right;
			} else {
				currentNode = currentNode->left;
			}
		}

		node *newNode = new node();
		newNode->key = key;
		newNode->parent = prevNode;
		if (prevNode->key < key) {
			prevNode->right = newNode;
		} else {
			prevNode->left = newNode;
		}
	}
	void print() {
		vector<int> acc;
		if (root == NULL) {
			cout << endl;
			cout << endl;
		} else {
			cout << " " << join(isToAs(visitInorder(root, acc)), " ");
			cout << " " << join(isToAs(visitPreorder(root, acc)), " ");
		}
	}
private:
	vector<int> visitPreorder(node *node, vector<int> acc) {
		if (node == NULL) {
			return acc;
		}
		acc.push_back(node->key);
		if (node->left!= NULL) {
			acc = visitPreorder(node->left, acc);
		}
		if (node->right!= NULL) {
			acc = visitPreorder(node->right, acc);
		}
		return acc;
	}
	vector<int> visitInorder(node *node, vector<int> acc) {
		if (node == NULL) {
			return acc;
		}
		if (node->left!= NULL) {
			acc = visitInorder(node->left, acc);
		}
		acc.push_back(node->key);
		if (node->right!= NULL) {
			acc = visitInorder(node->right, acc);
		}
		return acc;
	}
	vector<string> isToAs(vector<int> is) {
		vector<string> as;
		int n = is.size();
		for (int i = 0; i < n; i++) {
			as.push_back(to_string(is[i]));
		}
		return as;
	}
	string join(vector<string> vs, string delimiter) {
		string acc;
		for (int i = 0; i < vs.size(); i++) {
			if (i > 0) {
				acc += delimiter;
			}
			acc += vs[i];
		}
		return acc;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	tree tree;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "insert") {
			int key;
			cin >> key;
			tree.insert(key);
		} else if (command == "print") {
			tree.print();
		} else {
			throw "unknown command: " + command;
		}
	}
}

