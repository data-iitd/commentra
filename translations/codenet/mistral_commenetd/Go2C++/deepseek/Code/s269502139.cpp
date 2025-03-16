#include <iostream>
#include <sstream>
#include <string>

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

Node* deleteNode(Node* n, Node*& first, Node*& last) {
    if (n->prev == nullptr && n->next == nullptr) {
        first = last = nullptr;
        delete n;
        return nullptr;
    }
    if (n->prev == nullptr) {
        first = n->next;
        if (first != nullptr) {
            first->prev = nullptr;
        }
        delete n;
        return first;
    }
    if (n->next == nullptr) {
        last = n->prev;
        last->next = nullptr;
        delete n;
        return first;
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    return first;
}

Node* initNode(int key) {
    Node* n = new Node{key, nullptr, nullptr};
    return n;
}

int main() {
    std::string cmd;
    Node* first = nullptr;
    Node* last = nullptr;

    while (std::getline(std::cin, cmd)) {
        std::istringstream iss(cmd);
        std::string action;
        iss >> action;

        if (action == "deleteFirst") {
            first = deleteNode(first, first, last);
        } else if (action == "deleteLast") {
            last = deleteNode(last, first, last);
        } else {
            int key;
            iss >> key;
            Node* n = initNode(key);
            if (action == "insert") {
                n->next = first;
                if (first != nullptr) {
                    first->prev = n;
                }
                first = n;
                if (last == nullptr) {
                    last = n;
                }
            } else if (action == "delete") {
                for (Node* a = first; a != nullptr; a = a->next) {
                    if (a->key == key) {
                        first = deleteNode(a, first, last);
                        break;
                    }
                }
            }
        }
    }

    std::ostringstream buf;
    rPrint(first, buf);
    std::cout << buf.str() << std::endl;

    return 0;
}

