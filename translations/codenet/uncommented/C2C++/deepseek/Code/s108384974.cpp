#include <iostream>
#include <memory>

struct node {
    int key;
    std::shared_ptr<node> p;
    std::shared_ptr<node> l;
    std::shared_ptr<node> r;
};

typedef std::shared_ptr<node> NodePointer;

NodePointer r, NIL;

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

    NodePointer z = std::make_shared<node>();
    z->key = k;
    z->l = NIL;
    z->r = NIL;

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
    int n, i, z, x;
    std::string s;

    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> s;
        if (s == "find") {
            std::cin >> x;
            NodePointer t = find(r, x);
            if (t == NIL) std::cout << "no" << std::endl;
            else std::cout << "yes" << std::endl;

        } else if (s == "insert") {
            std::cin >> z;
            insert(z);
        } else {
            print();
        }
    }

    return 0;
}

