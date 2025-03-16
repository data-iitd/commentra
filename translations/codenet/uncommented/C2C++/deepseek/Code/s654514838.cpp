#include <iostream>
#include <cstdlib>
using namespace std;

#define NIL nullptr

struct Node {
    int key;
    int priority;
    Node *right, *left;
};

Node * Delete(Node **, int);
Node * deleteNode(Node **, int);

bool find(Node *p, int x) {
    while (p != NIL) {
        if (p->key == x) return true;
        else if (p->key > x) p = p->left;
        else p = p->right;
    }
    return false;
}

void inorder(Node *a) {
    if (a->left != NIL) inorder(a->left);
    cout << " " << a->key;
    if (a->right != NIL) inorder(a->right);
    return;
}

void preorder(Node *p) {
    cout << " " << p->key;
    if (p->left != NIL) preorder(p->left);
    if (p->right != NIL) preorder(p->right);
    return;
}

void print(Node *p) {
    inorder(p);
    cout << endl;
    preorder(p);
    cout << endl;
    return;
}

Node * makeNode(int x, int y) {
    Node *newNode = new Node;
    newNode->key = x;
    newNode->priority = y;
    newNode->left = NIL;
    newNode->right = NIL;
    return newNode;
}

Node *rightRotate(Node *p) {
    Node *q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
}

Node *leftRotate(Node *p) {
    Node *q = p->right;
    p->right = q->left;
    q->left = p;
    return q;
}

Node* insert(Node **t, int key, int priority) {
    Node *newNode;
    if (*t == NIL)
        return newNode = makeNode(key, priority);
    if ((*t)->key == key)
        return *t;

    if (key < (*t)->key) {
        (*t)->left = insert(&(*t)->left, key, priority);
        if ((*t)->priority < (*t)->left->priority)
            *t = rightRotate(*t);
    } else {
        (*t)->right = insert(&(*t)->right, key, priority);
        if ((*t)->priority < (*t)->right->priority)
            *t = leftRotate(*t);
    }
    return *t;
}

Node * Delete(Node **t, int key) {
    if (*t == NIL)
        return NIL;

    if (key < (*t)->key)
        (*t)->left = Delete(&(*t)->left, key);
    else if (key > (*t)->key)
        (*t)->right = Delete(&(*t)->right, key);
    else
        return deleteNode(t, key);
    return *t;
}

Node * deleteNode(Node **t, int key) {
    if ((*t)->left == NIL && (*t)->right == NIL) {
        return NIL;
    } else if ((*t)->left == NIL) {
        *t = leftRotate(*t);
    } else if ((*t)->right == NIL) {
        *t = rightRotate(*t);
    } else {
        if ((*t)->left->priority > (*t)->right->priority)
            *t = rightRotate(*t);
        else
            *t = leftRotate(*t);
    }
    return Delete(t, key);
}

int main() {
    int num, x, y;
    char com[8];
    Node *root = NIL;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> com;
        switch (com[0]) {
            case 'i':
                cin >> x >> y;
                root = insert(&root, x, y);
                break;
            case 'd':
                cin >> x;
                root = Delete(&root, x);
                break;
            case 'f':
                cin >> x;
                if (find(root, x)) cout << "yes" << endl;
                else cout << "no" << endl;
                break;
            case 'p':
                print(root);
                break;
        }
    }
    return 0;
}
