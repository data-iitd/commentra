#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Node {
    int key;
    Node* prev;
    Node* next;
};

void rPrint(Node* n, std::ostringstream& buf) {
    buf << n->key;
    if (n->next != nullptr) {
        buf << " ";
        rPrint(n->next, buf);
    }
}

Node* deleteNode(Node* first, Node* last, Node* n) {
    if (n->prev != nullptr && n->next != nullptr) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    } else if (n->next == nullptr && n->prev == nullptr) {
        first = last = nullptr;
    } else if (n->prev == nullptr) {
        first = n->next;
        n->next->prev = nullptr;
    } else if (n->next == nullptr) {
        last = n->prev;
        n->prev->next = nullptr;
    }
    return first;
}

Node* initNode(int key) {
    Node* n = new Node;
    n->key = key;
    n->prev = nullptr;
    n->next = nullptr;
    return n;
}

int main() {
    std::string cmd;
    Node* first = nullptr;
    Node* last = nullptr;

    while (std::getline(std::cin, cmd)) {
        std::istringstream xcmd(cmd);
        std::string operation;
        xcmd >> operation;

        if (operation == "deleteFirst") {
            first = deleteNode(first, last, first);
        } else if (operation == "deleteLast") {
            first = deleteNode(first, last, last);
        } else {
            int k;
            xcmd >> k;
            Node* n = initNode(k);

            if (operation == "delete") {
                for (Node* a = first; a != nullptr; a = a->next) {
                    if (a->key == k) {
                        first = deleteNode(first, last, a);
                        break;
                    }
                }
            } else if (operation == "insert") {
                n->next = first;
                if (first != nullptr) {
                    first->prev = n;
                }
                first = n;
                if (last == nullptr) {
                    last = n;
                }
            }
        }
    }

    std::ostringstream buf;
    if (first != nullptr) {
        rPrint(first, buf);
    }
    std::cout << buf.str() << std::endl;

    return 0;
}

