#include <iostream>
#include <cstdlib>
#include <cstring>

// Define a structure for a node
struct node {
    unsigned int key; // Key value of the node
    struct node *next; // Pointer to the next node
    struct node *prev; // Pointer to the previous node
};

// Typedef a NodePointer as a pointer to the node structure
typedef struct node *NodePointer;

// Initialize nil node with NULL pointers
NodePointer nil = nullptr;

// Function to search a node with given key
NodePointer listSearch(int key) {
    NodePointer cur = nil->next; // Initialize current node as the first node after nil
    while (cur != nil) { // Traverse the list until nil is reached
        if (cur->key == key) break; // If the current node's key matches the given key, break the loop
        cur = cur->next; // Move to the next node
    }
    return cur; // Return the found node or NULL if not found
}

// Initialize the linked list with a nil node
void init() {
    nil = new node; // Allocate memory for the nil node
    nil->next = nil; // Initialize next pointer of nil to itself
    nil->prev = nil; // Initialize prev pointer of nil to itself
}

// Function to print the linked list
void printList() {
    NodePointer cur = nil->next; // Initialize current node as the first node after nil
    int isf = 1; // Initialize isFirst flag to 1
    while (cur != nil) { // Traverse the list until nil is reached
        if (isf == 1) std::cout << "[" << cur->key << "] "; // If it's the first node, print its key with an index
        else std::cout << " " << cur->key; // Otherwise, print only the key
        cur = cur->next; // Move to the next node
        isf = 0; // Set isFirst flag to 0
    }
    std::cout << std::endl; // Print a newline after the list is printed
}

// Function to delete a node from the linked list
void deleteNode(NodePointer t) {
    if (t == nil) return; // Return if the node to be deleted is nil
    t->prev->next = t->next; // Update the next pointer of the previous node to point to the next node
    t->next->prev = t->prev; // Update the prev pointer of the next node to point to the previous node
    delete t; // Free the memory allocated to the deleted node
}

// Function to delete the first node from the linked list
void deleteFirst() {
    NodePointer t = nil->next; // Initialize the node to be deleted as the first node
    if (t == nil) return; // Return if the list is empty
    deleteNode(t); // Delete the first node
}

// Function to delete the last node from the linked list
void deleteLast() {
    NodePointer t = nil->prev; // Initialize the node to be deleted as the last node
    if (t == nil) return; // Return if the list is empty
    deleteNode(t); // Delete the last node
}

// Function to delete a node with the given key from the linked list
void deleteKey(int key) {
    NodePointer t = listSearch(key); // Search for the node with the given key
    if (t != nil) deleteNode(t); // Delete the node if it's found
}

// Function to insert a new node with the given key into the linked list
void insert(int key) {
    NodePointer x = new node; // Allocate memory for the new node
    x->key = key; // Set the key value of the new node
    x->prev = nil; // Set the prev pointer of the new node to nil
    x->next = nil->next; // Set the next pointer of the new node to the first node after nil
    nil->next->prev = x; // Update the prev pointer of the first node after nil to point to the new node
    nil->next = x; // Update the next pointer of nil to point to the new node
}

// Main function to read commands and perform the corresponding actions
int main() {
    int key, n, i; // Initialize variables for reading commands and list size
    int size = 0; // Initialize the current size of the list
    char com[20]; // Initialize a character array to store the command
    int np = 0, nd = 0; // Initialize counters for number of insertions and deletions
    std::cin >> n; // Read the number of commands
    init(); // Initialize the linked list
    for (i = 0; i < n; i++) { // Traverse the commands
        std::cin >> com >> key; // Read the command and the key value
        if (com[0] == 'i') { // If the command is 'i', insert a new node
            insert(key);
            np++;
            size++;
        } else if (com[0] == 'd') { // If the command is 'd', delete a node
            if (strlen(com) > 6) { // If the command is 'd F' or 'd L', delete the first or last node
                if (com[6] == 'F') deleteFirst();
                else if (com[6] == 'L') deleteLast();
            } else { // Otherwise, delete a node with the given key
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }

    printList(); // Print the updated linked list
    return 0; // Return 0 to indicate successful execution
}

