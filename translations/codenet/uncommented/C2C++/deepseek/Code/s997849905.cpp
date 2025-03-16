#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

struct node {
    int key;
    node* next;
    node* prev;
};

typedef node* NodePointer;
NodePointer N;

void init() {
    N = new node;
    N->next = N;
    N->prev = N;
}

void printList() {
    NodePointer cur = N->next;
    int snl = 1;
    while (cur != N) {
        if (!snl) std::cout << " ";
        std::cout << cur->key;
        cur = cur->next;
        snl = 0;
    }
    std::cout << std::endl;
}

void deleteFirst() {
    NodePointer t = N->next;
    N->next = t->next;
    t->next->prev = N;
    delete t;
}

void deleteLast() {
    NodePointer delnode = N->prev;
    N->prev = delnode->prev;
    delnode->prev->next = N;
    delete delnode;
}

void delete(int skey) {
    bool judge = false;
    NodePointer t;
    NodePointer n;

    for (n = N->next; n != N; n = n->next) {
        if (n->key == skey) {
            judge = true;
        }
    }

    if (judge) {
        n = N->next;
        while (n != N) {
            if (n->key == skey)
                break;
            n = n->next;
        }
        t = n->prev;
        t->next = n->next;
        t->next->prev = t;
        delete n;
    }
}

void insert(int skey) {
    NodePointer newNode;
    static int count = 0;
    newNode = new node;
    newNode->key = skey;

    if (count == 0) {
        newNode->next = N;
        N->next = newNode;
        newNode->prev = N;
        N->prev = newNode;
        count++;
    }
    else {
        newNode->next = N->next;
        N->next->prev = newNode;
        N->next = newNode;
        newNode->prev = N;
        count++;
    }
}

int main() {
    int key, n, i;
    std::string com;

    std::cin >> n;
    init();
    for (i = 0; i < n; i++) {
        std::cin >> com;
        if (com == "insert") {
            std::cin >> key;
            insert(key);
        }
        else if (com == "deleteFirst")
            deleteFirst();
        else if (com == "deleteLast")
            deleteLast();
        else {
            std::cin >> key;
            delete(key);
        }
    }
    printList();
    return 0;
}

