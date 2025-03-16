#include <iostream>
#include <string>

using namespace std;

// Define the structure for a node in the circular doubly linked list
struct Node {
    int key;          // Integer key stored in the node
    Node* next;      // Pointer to the next node in the list
    Node* prev;      // Pointer to the previous node in the list
};

// Declare a global variable N of type Node*
Node* N;

// Initialize the circular doubly linked list
void init() {
    N = new Node(); // Allocate memory for the sentinel node
    N->next = N;    // Set the next pointer of the sentinel node to itself
    N->prev = N;    // Set the previous pointer of the sentinel node to itself
}

// Print the elements of the circular doubly linked list
void printList() {
    Node* cur = N->next; // Start from the first node
    bool firstElement = true; // Flag to determine if it's the first element
    while (cur != N) { // Iterate until the sentinel node is reached
        if (!firstElement) cout << " "; // Print a space before non-first elements
        cout << cur->key; // Print the key of the current node
        cur = cur->next; // Move to the next node
        firstElement = false; // Set the flag to indicate a non-first element
    }
    cout << endl; // Print a newline at the end
}

// Delete the first node in the circular doubly linked list
void deleteFirst() {
    Node* t = N->next; // Store the first node
    N->next = t->next; // Update the next pointer of the sentinel node
    t->next->prev = N; // Update the previous pointer of the new first node
    delete t; // Free the memory of the deleted node
}

// Delete the last node in the circular doubly linked list
void deleteLast() {
    Node* delnode = N->prev; // Store the last node
    N->prev = delnode->prev; // Update the previous pointer of the sentinel node
    delnode->prev->next = N; // Update the next pointer of the new last node
    delete delnode; // Free the memory of the deleted node
}

// Delete a node with a specific key from the circular doubly linked list
void deleteNode(int skey) {
    Node* n; // Temporary pointer for node search

    // Iterate through the list to find the node with the specified key
    for (n = N->next; n != N; n = n->next) {
        if (n->key == skey) {
            Node* t = n->prev;
            t->next = n->next;
            n->next->prev = t;
            delete n; // Free the memory of the deleted node
            return; // Exit after deleting the node
        }
    }
}

// Insert a new node with a specific key into the circular doubly linked list
void insert(int skey) {
    Node* newNode = new Node(); // Pointer to the new node
    newNode->key = skey; // Set the key of the new node

    // Special case: if the list is empty, set the new node as the only node
    if (N->next == N) {
        newNode->next = N;
        N->next = newNode;
        newNode->prev = N;
        N->prev = newNode;
    } else {
        newNode->next = N->next; // Set the next pointer of the new node
        N->next->prev = newNode; // Update the previous pointer of the current first node
        N->next = newNode; // Update the next pointer of the sentinel node
        newNode->prev = N; // Set the previous pointer of the new node
    }
}

// Main function to execute the operations on the circular doubly linked list
int main() {
    int key, n;
    string command; // String to store the command

    cin >> n; // Read the number of commands
    init(); // Initialize the circular doubly linked list
    for (int i = 0; i < n; i++) { // Loop through the number of commands
        cin >> command; // Read the command
        if (command == "insert") { // If the command is to insert
            cin >> key; // Read the key to insert
            insert(key); // Insert the key into the list
        } else if (command == "deleteFirst") // If the command is to delete the first node
            deleteFirst();
        else if (command == "deleteLast") // If the command is to delete the last node
            deleteLast();
        else { // If the command is to delete a specific node
            cin >> key; // Read the key to delete
            deleteNode(key); // Delete the node with the specified key
        }
    }
    printList(); // Print the final state of the list
    return 0;
}

// <END-OF-CODE>
