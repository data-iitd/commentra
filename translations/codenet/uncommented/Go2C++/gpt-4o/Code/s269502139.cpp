#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

class Node {
public:
    int32_t key;
    Node* prev;
    Node* next;

    Node(int32_t k) : key(k), prev(nullptr), next(nullptr) {}

    void rPrint(std::ostringstream& buf) {
        buf << key;
        if (next != nullptr) {
            buf << " ";
            next->rPrint(buf);
        }
    }

    std::pair<Node*, Node*> Delete(Node* first, Node* last) {
        if (prev != nullptr && next != nullptr) {
            // swap
            prev->next = next;
            next->prev = prev;
            return {first, last};
        }

        if (next == nullptr && prev == nullptr) {
            return {nullptr, nullptr};
        }

        if (prev == nullptr) {
            first = next;
            if (next != nullptr) {
                next->prev = nullptr;
            }
        }

        if (next == nullptr) {
            last = prev;
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }

        return {first, last};
    }
};

Node* initNode(int32_t key) {
    return new Node(key);
}

int main() {
    std::string cmd;
    Node* first = nullptr;
    Node* last = nullptr;

    while (std::getline(std::cin, cmd)) {
        if (cmd == "deleteFirst") {
            if (first != nullptr) {
                std::tie(first, last) = first->Delete(first, last);
            }
        } else if (cmd == "deleteLast") {
            if (last != nullptr) {
                std::tie(first, last) = last->Delete(first, last);
            }
        } else {
            std::istringstream iss(cmd);
            std::string operation;
            int32_t k;
            iss >> operation >> k;

            if (operation == "delete") {
                for (Node* a = first; a != nullptr; a = a->next) {
                    if (a->key == k) {
                        std::tie(first, last) = a->Delete(first, last);
                        break;
                    }
                }
            } else if (operation == "insert") {
                Node* n = initNode(k);
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
        first->rPrint(buf);
    }
    std::cout << buf.str() << std::endl;

    return 0;
}

// <END-OF-CODE>
