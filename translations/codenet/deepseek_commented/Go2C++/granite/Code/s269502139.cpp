

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Define the `node` structure
// This structure represents a node in a doubly linked list.
// It contains an integer key, and pointers to the previous and next nodes.
struct node {
    int key;
    node* prev;
    node* next;
};

// Recursive Print Function
// The `rPrint` method prints the keys of the nodes in the list from the current node to the last node.
void rPrint(node* n, stringstream& buf) {
    buf << n->key;
    if (n->next!= nullptr) {
        buf << " ";
        rPrint(n->next, buf);
    }
}

// Delete Method
// The `Delete` method removes the current node from the list and adjusts the pointers of the surrounding nodes.
void Delete(node* n, node*& first, node*& last) {
    if (n->prev!= nullptr && n->next!= nullptr) {
        //swap
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    if (n->next == nullptr && n->prev == nullptr) {
        first = nullptr;
        last = nullptr;
    }

    if (n->prev == nullptr) {
        first = n->next;
        if (n->next!= nullptr) {
            n->next->prev = nullptr;
        }
    }

    if (n->next == nullptr) {
        last = n->prev;
        if (n->prev!= nullptr) {
            n->prev->next = nullptr;
        }
    }
}

// Node Initialization
// The `initNode` function creates a new node with the given key.
node* initNode(int key) {
    node* n = new node();
    n->key = key;
    return n;
}

// Main Function
// The main function reads commands from standard input, performs operations on the doubly linked list, and prints the final list.
int main() {
    string cmd;
    node* first = nullptr;
    node* last = nullptr;

    while (cin >> cmd) {
        if (cmd == "deleteFirst") {
            Delete(first, first, last);
        } else if (cmd == "deleteLast") {
            Delete(last, first, last);
        } else {
            stringstream ss(cmd);
            string op;
            ss >> op;
            if (op == "delete") {
                int k;
                ss >> k;
                for (node* a = first; a!= nullptr; a = a->next) {
                    if (a->key == k) {
                        Delete(a, first, last);
                        break;
                    }
                }
            } else if (op == "insert") {
                int k;
                ss >> k;
                node* n = initNode(k);
                n->next = first;
                if (first!= nullptr) {
                    first->prev = n;
                }

                first = n;
                if (last == nullptr) {
                    last = n;
                }
            }
        }
    }

    stringstream buf;
    rPrint(first, buf);
    cout << buf.str() << endl;

    return 0;
}

This code now includes comments that describe each logical block, making it easier to understand the structure and functionality of the C++ code.