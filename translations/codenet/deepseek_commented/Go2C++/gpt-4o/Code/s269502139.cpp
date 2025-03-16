#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// Define the `Node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
struct Node {
    int32_t key;
    Node* prev;
    Node* next;

    Node(int32_t k) : key(k), prev(nullptr), next(nullptr) {}
};

// Recursive Print Function
// The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
void rPrint(Node* n, ostringstream& buf) {
    buf << n->key;
    if (n->next != nullptr) {
        buf << " ";
        rPrint(n->next, buf);
    }
}

// Delete Method
// The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
pair<Node*, Node*> Delete(Node* n, Node* first, Node* last) {
    if (n->prev != nullptr && n->next != nullptr) {
        // Swap
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return {first, last};
    }

    if (n->next == nullptr && n->prev == nullptr) {
        return {nullptr, nullptr};
    }

    if (n->prev == nullptr) {
        first = n->next;
        n->next->prev = nullptr;
    }

    if (n->next == nullptr) {
        last = n->prev;
        n->prev->next = nullptr;
    }

    return {first, last};
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main() {
    string command;
    Node* first = nullptr;
    Node* last = nullptr;

    while (getline(cin, command)) {
        if (command == "deleteFirst") {
            if (first != nullptr) {
                tie(first, last) = Delete(first, first, last);
            }
        } else if (command == "deleteLast") {
            if (last != nullptr) {
                tie(first, last) = Delete(last, first, last);
            }
        } else {
            istringstream iss(command);
            string cmd;
            int k;
            iss >> cmd >> k;
            int32_t k32 = static_cast<int32_t>(k);

            if (cmd == "delete") {
                for (Node* a = first; a != nullptr; a = a->next) {
                    if (a->key == k32) {
                        tie(first, last) = Delete(a, first, last);
                        break;
                    }
                }
            } else if (cmd == "insert") {
                Node* n = new Node(k32);
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

    ostringstream buf;
    if (first != nullptr) {
        rPrint(first, buf);
    }
    cout << buf.str() << endl;

    return 0;
}

// <END-OF-CODE>
