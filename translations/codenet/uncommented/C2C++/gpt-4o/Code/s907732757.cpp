#include <iostream>
#include <string>

struct Node {
    int key;
    Node* next;
    Node* prev;
};

Node* head;

Node* makeNode(int);
void insert(int);
void deleteNode(int);
void deleteFirst();
void deleteLast();

int main() {
    int n, a;
    std::string op;
    Node* x;

    head = makeNode(0);
    head->next = head;
    head->prev = head;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> op;
        if (op == "insert") {
            std::cin >> a;
            insert(a);
        } else if (op == "delete") {
            std::cin >> a;
            deleteNode(a);
        } else if (op == "deleteFirst") {
            deleteFirst();
        } else if (op == "deleteLast") {
            deleteLast();
        }
    }

    x = head;
    while (x->next != head) {
        std::cout << x->next->key;
        x = x->next;
        if (x->next != head) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

Node* makeNode(int a) {
    Node* x = new Node();
    x->key = a;
    return x;
}

void insert(int a) {
    Node* x = makeNode(a);
    x->next = head->next;
    head->next->prev = x;
    head->next = x;
    x->prev = head;
}

void deleteNode(int a) {
    Node* x = head;

    while (x->next != head) {
        x = x->next;
        if (x->key == a) {
            x->prev->next = x->next;
            x->next->prev = x->prev;
            delete x;
            break;
        }
    }
}

void deleteFirst() {
    Node* x = head->next;
    head->next = x->next;
    x->next->prev = head;
    delete x;
}

void deleteLast() {
    Node* x = head->prev;
    head->prev = x->prev;
    x->prev->next = head;
    delete x;
}

// <END-OF-CODE>
