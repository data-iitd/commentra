#include <iostream>
#include <string>

using namespace std;

// Define a structure for a doubly linked list node
struct Node {
    unsigned int key;          // Key value of the node
    Node* next;               // Pointer to the next node
    Node* prev;               // Pointer to the previous node
};

typedef Node* NodePointer; // Define NodePointer as a pointer to a node structure

NodePointer nil; // Sentinel node to represent the head and tail of the list

// Function to search for a node with a specific key
NodePointer listSearch(int key) {
    NodePointer cur = nil->next; // Start from the first node
    while (cur != nil) {          // Traverse until the sentinel node
        if (cur->key == key) break; // If the key is found, break the loop
        cur = cur->next;          // Move to the next node
    }
    return cur; // Return the found node or sentinel if not found
}

// Function to initialize the linked list
void init() {
    nil = new Node(); // Allocate memory for the sentinel node
    nil->next = nil;  // Point next of sentinel to itself
    nil->prev = nil;  // Point prev of sentinel to itself
}

// Function to print all the keys in the linked list
void printList() {
    NodePointer cur = nil->next; // Start from the first node
    bool isFirst = true; // Flag to manage spacing between numbers
    while (cur != nil) { // Stop if we reach the sentinel node
        if (!isFirst) cout << " "; // Print space before the next number if not the first
        cout << cur->key; // Print the key of the current node
        cur = cur->next; // Move to the next node
        isFirst = false; // Set flag to indicate that we have printed at least one number
    }
    cout << endl; // Print a new line after printing all keys
}

// Function to delete a specific node from the list
void deleteNode(NodePointer t) {
    if (t == nil) return; // Do nothing if the node is the sentinel
    t->prev->next = t->next; // Bypass the node in the next pointer of the previous node
    t->next->prev = t->prev; // Bypass the node in the prev pointer of the next node
    delete t; // Free the memory allocated for the node
}

// Function to delete the first node in the list
void deleteFirst() {
    NodePointer t = nil->next; // Get the first node
    if (t == nil) return; // Do nothing if the list is empty
    deleteNode(t); // Delete the first node
}

// Function to delete the last node in the list
void deleteLast() {
    NodePointer t = nil->prev; // Get the last node
    if (t == nil) return; // Do nothing if the list is empty
    deleteNode(t); // Delete the last node
}

// Function to delete a node with a specific key
void deleteKey(int key) {
    NodePointer t = listSearch(key); // Search for the node with the key
    if (t != nil) deleteNode(t); // If found, delete the node
}

// Function to insert a new node with a specific key at the beginning of the list
void insert(int key) {
    NodePointer x = new Node(); // Allocate memory for the new node
    x->key = key; // Set the key of the new node
    x->prev = nil; // Set the previous pointer to the sentinel
    x->next = nil->next; // Set the next pointer to the current first node
    x->next->prev = x; // Update the previous pointer of the current first node to point to the new node
    nil->next = x; // Update the sentinel's next pointer to point to the new node
}

// Main function to execute the program
int main() {
    int key, n; // Variables for key and number of operations
    int size = 0; // Variable to keep track of the size of the list
    string com; // String to store command
    int np = 0, nd = 0; // Counters for number of insertions and deletions
    cin >> n; // Read the number of operations
    init(); // Initialize the linked list
    for (int i = 0; i < n; i++) { // Loop through each operation
        cin >> com >> key; // Read the command and key
        if (com[0] == 'i') { // If the command is 'insert'
            insert(key); np++; size++; // Insert the key and update counters
        } else if (com[0] == 'd') { // If the command is 'delete'
            if (com.length() > 6) { // Check if the command specifies 'First' or 'Last'
                if (com[6] == 'F') deleteFirst(); // Delete the first node
                else if (com[6] == 'L') deleteLast(); // Delete the last node
            } else {
                deleteKey(key); nd++; // Delete the node with the specified key
            }
            size--; // Decrease the size of the list
        }
    }

    printList(); // Print the final state of the list
    return 0; // Return success
}

// <END-OF-CODE>
