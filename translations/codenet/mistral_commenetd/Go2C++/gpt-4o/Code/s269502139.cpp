#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// Define a node structure with key, previous and next pointers
struct Node {
    int32_t key;
    Node* prev;
    Node* next;

    Node(int32_t k) : key(k), prev(nullptr), next(nullptr) {}
};

// Recursive function to print the linked list in reverse order
void rPrint(Node* n, ostringstream& buf) {
    buf << n->key;
    if (n->next != nullptr) {
        buf << " ";
        rPrint(n->next, buf);
    }
}

// Function to delete a node from the linked list
pair<Node*, Node*> Delete(Node* n, Node* first, Node* last) {
    // Base case: if node is the first and last node
    if (n->prev == nullptr && n->next == nullptr) {
        return {nullptr, nullptr};
    }

    // Base case: if node is the first node
    if (n->prev == nullptr) {
        first = n->next;
        n->next->prev = nullptr;
        return {first, last};
    }

    // Base case: if node is the last node
    if (n->next == nullptr) {
        last = n->prev;
        n->prev->next = nullptr;
        return {first, last};
    }

    // General case: swap the pointers of previous and next nodes
    n->prev->next = n->next;
    n->next->prev = n->prev;
    return {first, last};
}

// Main function to read commands from stdin and perform the corresponding actions
int main() {
    string command;
    Node* first = nullptr;
    Node* last = nullptr;

    // Process each command until EOF is reached
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

    // Print the linked list in reverse order
    ostringstream buf;
    rPrint(first, buf);
    cout << buf.str() << endl;

    // Clean up memory
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }

    return 0;
}

// <END-OF-CODE>
