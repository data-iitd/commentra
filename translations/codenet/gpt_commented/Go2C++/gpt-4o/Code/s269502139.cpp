#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// Define a doubly linked list node structure
struct Node {
    int32_t key; // The value of the node
    Node* prev;  // Pointer to the previous node
    Node* next;  // Pointer to the next node

    Node(int32_t k) : key(k), prev(nullptr), next(nullptr) {} // Constructor to initialize a node
};

// Method to recursively print the keys of the linked list starting from the current node
void rPrint(Node* n, ostringstream& buf) {
    buf << n->key; // Append the current node's key to the buffer
    if (n->next != nullptr) {
        buf << " "; // Add a space if there is a next node
        rPrint(n->next, buf); // Recursively print the next node
    }
}

// Method to delete the current node from the linked list
pair<Node*, Node*> Delete(Node* n, Node* first, Node* last) {
    if (n->prev != nullptr && n->next != nullptr) {
        // Node is in the middle; update pointers of adjacent nodes
        n->prev->next = n->next;
        n->next->prev = n->prev;
        return {first, last}; // Return unchanged first and last pointers
    }

    if (n->next == nullptr && n->prev == nullptr) {
        // Node is the only node in the list
        return {nullptr, nullptr}; // Return nullptr for both first and last
    }

    if (n->prev == nullptr) {
        // Node is the first node
        first = n->next; // Update first to the next node
        if (first != nullptr) {
            first->prev = nullptr; // Set the previous pointer of the new first node to nullptr
        }
    }

    if (n->next == nullptr) {
        // Node is the last node
        last = n->prev; // Update last to the previous node
        if (last != nullptr) {
            last->next = nullptr; // Set the next pointer of the new last node to nullptr
        }
    }

    return {first, last}; // Return updated first and last pointers
}

// Function to initialize a new node with a given key
Node* initNode(int32_t key) {
    return new Node(key); // Create a new node
}

// Main function to execute the program
int main() {
    string command;
    Node* first = nullptr; // Initialize pointers for the first and last nodes of the list
    Node* last = nullptr;

    // Loop to process each command from the input
    while (getline(cin, command)) {
        if (command == "deleteFirst") {
            // Command to delete the first node
            if (first != nullptr) {
                tie(first, last) = Delete(first, first, last);
            }
        } else if (command == "deleteLast") {
            // Command to delete the last node
            if (last != nullptr) {
                tie(first, last) = Delete(last, first, last);
            }
        } else {
            // Handle commands that involve inserting or deleting specific keys
            istringstream iss(command);
            string cmd;
            int k;
            iss >> cmd >> k; // Read command and key
            int32_t k32 = static_cast<int32_t>(k); // Convert the integer to int32_t
            if (cmd == "delete") {
                // Command to delete a node with a specific key
                for (Node* a = first; a != nullptr; a = a->next) {
                    if (a->key == k32) {
                        tie(first, last) = Delete(a, first, last); // Delete the node and update first and last
                        break;
                    }
                }
            } else if (cmd == "insert") {
                // Command to insert a new node at the beginning of the list
                Node* n = initNode(k32); // Initialize a new node
                n->next = first; // Set the new node's next pointer to the current first node
                if (first != nullptr) {
                    first->prev = n; // Update the previous pointer of the current first node
                }
                first = n; // Update first to the new node
                if (last == nullptr) {
                    last = n; // If the list was empty, set last to the new node
                }
            }
        }
    }

    ostringstream buf;
    rPrint(first, buf); // Print the keys of the linked list starting from the first node
    cout << buf.str() << endl; // Output the result

    // Clean up memory
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }

    return 0;
}

// <END-OF-CODE>
