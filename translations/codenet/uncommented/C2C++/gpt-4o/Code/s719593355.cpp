#include <iostream>
#include <string>

struct Node {
    unsigned int key;
    Node* next;
    Node* prev;
};

typedef Node* NodePointer;

NodePointer nil;

NodePointer listSearch(int);
void init();
void printList();
void deleteNode(NodePointer);
void deleteFirst();
void deleteLast();
void deleteNodeByKey(int);
void insert(int);

int main() {
    int key, n;
    std::string command;

    std::cin >> n;

    init();

    for (int i = 0; i < n; i++) {
        std::cin >> command >> key;

        if (command[0] == 'i') {
            insert(key);
        } else if (command[0] == 'd') {
            if (command.length() > 6) {
                if (command[6] == 'F') {
                    deleteFirst();
                } else if (command[6] == 'L') {
                    deleteLast();
                }
            } else {
                deleteNodeByKey(key);
            }
        }
    }

    printList();

    return 0;
}

NodePointer listSearch(int key) {
    NodePointer cur = nil->next;

    while (cur != nil && cur->key != key) {
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

void deleteNodeByKey(int key) {
    NodePointer t = listSearch(key);

    if (t == nil) return;

    deleteNode(t);
}

void insert(int key) {
    NodePointer x = new Node();
    x->key = key;

    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

// <END-OF-CODE>
