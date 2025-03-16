#include <iostream>
#include <memory>

struct Node {
    int key;
    Node* p;
    Node* l;
    Node* r;

    Node(int k) : key(k), p(nullptr), l(nullptr), r(nullptr) {}
};

using NodePointer = Node*;

NodePointer r = nullptr;
NodePointer NIL = nullptr;

NodePointer find(NodePointer x, int k) {
    while (x != NIL && k != x->key) {
        if (k < x->key) {
            x = x->l;
        } else {
            x = x->r;
        }
    }
    return x;
}

void insert(int k) {
    NodePointer y = NIL;
    NodePointer x = r;

    NodePointer z = new Node(k);

    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->l;
        } else {
            x = x->r;
        }
    }
    z->p = y;

    if (y == NIL) {
        r = z;
    } else if (z->key < y->key) {
        y->l = z;
    } else {
        y->r = z;
    }
}

void inorder(NodePointer u) {
    if (u == NIL) {
        return;
    }
    inorder(u->l);
    std::cout << " " << u->key;
    inorder(u->r);
}

void preorder(NodePointer u) {
    if (u == NIL) {
        return;
    }
    std::cout << " " << u->key;
    preorder(u->l);
    preorder(u->r);
}

void print() {
    inorder(r);
    std::cout << std::endl;
    preorder(r);
    std::cout << std::endl;
}

int main() {
    int n, x, z;
    std::string s;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s;
        if (s[0] == 'f') {
            std::cin >> x;
            NodePointer t = find(r, x);
            if (t == NIL) std::cout << "no" << std::endl;
            else std::cout << "yes" << std::endl;

        } else if (s[0] == 'i') {
            std::cin >> z;
            insert(z);
        } else {
            print();
        }
    }

    return 0;
}

// <END-OF-CODE>
