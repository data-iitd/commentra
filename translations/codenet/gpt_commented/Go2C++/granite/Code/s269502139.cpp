
#include <iostream>
#include <sstream>
#include <string>

// Define a doubly linked list node structure
struct Node {
    int key; // The value of the node
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node
};

// Method to recursively print the keys of the linked list starting from the current node
void rPrint(Node* n, std::stringstream& buf) {
    buf << n->key; // Append the current node's key to the buffer
    if (n->next!= nullptr) {
        buf << " "; // Add a space if there is a next node
        rPrint(n->next, buf); // Recursively print the next node
    }
}

// Method to delete the current node from the linked list
void deleteNode(Node* n, Node*& first, Node*& last) {
    if (n->prev!= nullptr && n->next!= nullptr) {
        // Node is in the middle; update pointers of adjacent nodes
        n->prev->next = n->next;
        n->next->prev = n->prev;
    } else if (n->next == nullptr && n->prev == nullptr) {
        // Node is the only node in the list
        first = nullptr; // Set first to nullptr
        last = nullptr; // Set last to nullptr
    } else if (n->prev == nullptr) {
        // Node is the first node
        first = n->next; // Update first to the next node
        if (first!= nullptr) {
            first->prev = nullptr; // Set the previous pointer of the new first node to nullptr
        }
    } else if (n->next == nullptr) {
        // Node is the last node
        last = n->prev; // Update last to the previous node
        if (last!= nullptr) {
            last->next = nullptr; // Set the next pointer of the new last node to nullptr
        }
    }
}

// Function to initialize a new node with a given key
Node* initNode(int key) {
    Node* n = new Node();
    n->key = key; // Set the key of the new node
    return n;
}

int main() {
    std::string line;
    std::getline(std::cin, line); // Read the first line of input (not used)

    Node* first = nullptr; // Initialize pointers for the first and last nodes of the list
    Node* last = nullptr;

    // Loop to process each command from the input
    while (std::getline(std::cin, line)) {
        if (line == "deleteFirst") {
            // Command to delete the first node
            deleteNode(first, first, last);
        } else if (line == "deleteLast") {
            // Command to delete the last node
            deleteNode(last, first, last);
        } else {
            // Handle commands that involve inserting or deleting specific keys
            std::istringstream iss(line);
            std::string cmd;
            int k;
            iss >> cmd >> k;
            if (cmd == "delete") {
                // Command to delete a node with a specific key
                Node* a = first;
                while (a!= nullptr) {
                    if (a->key == k) {
                        deleteNode(a, first, last); // Delete the node and update first and last
                        break;
                    }
                    a = a->next;
                }
            } else if (cmd == "insert") {
                // Command to insert a new node at the beginning of the list
                Node* n = initNode(k); // Initialize a new node
                n->next = first; // Set the new node's next pointer to the current first node
                if (first!= nullptr) {
                    first->prev = n; // Update the previous pointer of the current first node
                }
                first = n; // Update first to the new node
                if (last == nullptr) {
                    last = n; // If the list was empty, set last to the new node
                }
            }
        }
    }

    std::stringstream buf;
    rPrint(first, buf); // Print the keys of the linked list starting from the first node
    std::cout << buf.str() << std::endl; // Output the result

    return 0;
}

