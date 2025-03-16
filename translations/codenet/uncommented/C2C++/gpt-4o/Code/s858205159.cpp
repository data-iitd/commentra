#include <iostream>
#include <string>

struct Node {
    unsigned int key;
    Node* next;
    Node* prev;
};

typedef Node* NodePointer;

NodePointer nil;

NodePointer listSearch(int key) {
    NodePointer cur = nil->next;
    while (cur != nil) {
        if (cur->key == key) break;
        cur = cur->next;
    }
    return cur;
}

void init() {
    nil = new Node();
    nil->next = nil;
    nil->prev = nil;
}

void printList() {
    NodePointer cur = nil->next;
    bool isFirst = true;
    while (true) {
        if (cur == nil) break;
        if (!isFirst) std::cout << " ";
        std::cout << cur->key;
        cur = cur->next;
        isFirst = false;
    }
    std::cout << std::endl;
}

void deleteNode(NodePointer t) {
    if (t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
}

void deleteFirst() {
    NodePointer t = nil->next;
    if (t == nil) return;
    deleteNode(t);
}

void deleteLast() {
    NodePointer t = nil->prev;
    if (t == nil) return;
    deleteNode(t);
}

void deleteKey(int key) {
    NodePointer t = listSearch(key);
    if (t != nil) deleteNode(t);
}

void insert(int key) {
    NodePointer x = new Node();
    x->key = key;
    x->prev = nil;
    x->next = nil->next;
    x->next->prev = x;
    nil->next = x;
}

int main() {
    int key, n;
    std::string com;
    int size = 0;
    int np = 0, nd = 0;

    std::cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        std::cin >> com >> key;
        if (com[0] == 'i') {
            insert(key);
            np++;
            size++;
        } else if (com[0] == 'd') {
            if (com.length() > 6) {
                if (com[6] == 'F') deleteFirst();
                else if (com[6] == 'L') deleteLast();
            } else {
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }

    printList();
    return 0;
}

// <END-OF-CODE>
