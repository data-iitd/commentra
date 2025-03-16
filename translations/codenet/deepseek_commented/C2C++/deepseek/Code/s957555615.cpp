#include <iostream>
#include <memory>

struct node {
  std::shared_ptr<node> right;
  std::shared_ptr<node> left;
  std::shared_ptr<node> parent;
  int key;
};
typedef std::shared_ptr<node> Node;
const Node NIL = nullptr;

Node root;

// This function finds the node with the minimum key in the subtree rooted at x
Node treeMinimum(Node x) {
  while (x->left != NIL) x = x->left;
  return x;
}

// This function finds the node with the maximum key in the subtree rooted at x
Node treeMaximum(Node x) {
  while (x->right != NIL) x = x->right;
  return x;
}

// This function searches for a node with a given key k in the subtree rooted at u
Node treeSearch(Node u, int k) {
  if (u == NIL || k == u->key) return u;
  if (k < u->key) return treeSearch(u->left, k);
  else return treeSearch(u->right, k);
}

// This function finds the successor of a given node x in the tree
Node treeSuccessor(Node x) {
  Node y;
  if (x->right != NIL) return treeMinimum(x->right);
  y = x->parent;
  while (y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

// This function deletes a node z from the tree
void treeDelete(Node z) {
  Node y; // node to be deleted
  Node x; // child of y
  if (z->left == NIL || z->right == NIL) y = z;
  else y = treeSuccessor(z);
  if (y->left != NIL) x = y->left;
  else x = y->right;
  if (x != NIL) x->parent = y->parent;
  if (y->parent == NIL) root = x;
  else if (y == y->parent->left) y->parent->left = x;
  else y->parent->right = x;
  if (y != z) z->key = y->key;
}

// This function inserts a new node with key k into the tree
void insert(int k) {
  Node y = NIL;
  Node x = root;
  Node z;
  z = std::make_shared<node>();
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL) root = z;
  else if (z->key < y->key) y->left = z;
  else y->right = z;
}

// This function performs an inorder traversal of the tree and prints the keys
void inorder(Node u) {
  if (u == NIL) return;
  inorder(u->left);
  std::cout << " " << u->key;
  inorder(u->right);
}

// This function performs a preorder traversal of the tree and prints the keys
void preorder(Node u) {
  if (u == NIL) return;
  std::cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, i, x;
  char com[20];
  std::cin >> n;
  for (i = 0; i < n; i++) {
    std::cin >> com;
    if (com[0] == 'f') {
      std::cin >> x;
      Node t = treeSearch(root, x);
      if (t != NIL) std::cout << "yes\n";
      else std::cout << "no\n";
    } else if (com[0] == 'i') {
      std::cin >> x;
      insert(x);
    } else if (com[0] == 'p') {
      inorder(root);
      std::cout << "\n";
      preorder(root);
      std::cout << "\n";
    } else if (com[0] == 'd') {
      std::cin >> x;
      treeDelete(treeSearch(root, x));
    }
  }
  return 0;
}

