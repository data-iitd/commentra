#include <iostream>
#include <string>

struct Node {
    int key;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = new Node();
        head->next = head;
        head->prev = head;
    }

    void printList() {
        Node* cur = head->next;
        bool first = true;
        while (cur != head) {
            if (!first) std::cout << " ";
            std::cout << cur->key;
            cur = cur->next;
            first = false;
        }
        std::cout << std::endl;
    }

    void deleteFirst() {
        if (head->next == head) return; // List is empty
        Node* t = head->next;
        head->next = t->next;
        t->next->prev = head;
        delete t;
    }

    void deleteLast() {
        if (head->prev == head) return; // List is empty
        Node* delnode = head->prev;
        head->prev = delnode->prev;
        delnode->prev->next = head;
        delete delnode;
    }

    void deleteNode(int skey) {
        Node* n = head->next;
        while (n != head) {
            if (n->key == skey) {
                n->prev->next = n->next;
                n->next->prev = n->prev;
                delete n;
                return;
            }
            n = n->next;
        }
    }

    void insert(int skey) {
        Node* newNode = new Node();
        newNode->key = skey;

        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
};

int main() {
    int key, n;
    std::string command;

    std::cin >> n;
    DoublyLinkedList list;

    for (int i = 0; i < n; i++) {
        std::cin >> command;
        if (command == "insert") {
            std::cin >> key;
            list.insert(key);
        } else if (command == "deleteFirst") {
            list.deleteFirst();
        } else if (command == "deleteLast") {
            list.deleteLast();
        } else {
            std::cin >> key;
            list.deleteNode(key);
        }
    }
    list.printList();
    return 0;
}

// <END-OF-CODE>
