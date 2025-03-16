#include <iostream>
#include <string>
#include <cstdlib>

// Define a doubly linked list node structure
struct node {
    unsigned int key;          // Key value of the node
    node *next;                // Pointer to the next node
    node *prev;                // Pointer to the previous node
};

typedef node * NodePointer; // Define a pointer type for node

NodePointer nil; // Sentinel node to represent the head and tail of the list

// Function prototypes
NodePointer listSearch(int);
void init(void);
void printList(void);
void deleteNode(NodePointer);
void deleteFirst(void);
void deleteLast(void);
void delete(int);
void insert(int);

int main() {
    int key, n, i; // Variables for key, number of operations, and loop index
    int size = 0;  // Variable to keep track of the size of the list
    std::string com;  // String to hold command strings
    int np = 0, nd = 0; // Counters for number of insertions and deletions

    // Read the number of operations to perform
    std::cin >> n;
    
    // Initialize the doubly linked list
    init();
    
    // Loop to process each operation
    for (i = 0; i < n; i++) {
        // Read command and key value
        std::cin >> com >> key;
        
        // If the command is to insert a node
        if (com[0] == 'i') {
            insert(key); // Insert the key into the list
            np++;        // Increment the insertion counter
            size++;      // Increment the size of the list
        }
        // If the command is to delete a node
        else if (com[0] == 'd') {
            // Check for specific delete commands (delete first or last)
            if (com.length() > 6) {
                if (com[6] == 'F') {
                    deleteFirst(); // Delete the first node
                } else if (com[6] == 'L') {
                    deleteLast(); // Delete the last node
                }
            } else {
                delete(key); // Delete the node with the specified key
                nd++;        // Increment the deletion counter
            }
            size--; // Decrement the size of the list
        }
    }

    // Print the final state of the list
    printList();
    
    return 0; // Exit the program
}

// Function to search for a node with a specific key
NodePointer listSearch(int key) {
    NodePointer cur = nil->next; // Start searching from the first node

    // Traverse the list until the end or until the key is found
    while (cur != nil && cur->key != key)
        cur = cur->next;

    return cur; // Return the found node or nil if not found
}

// Function to initialize the doubly linked list
void init(void) {
    nil = new node; // Allocate memory for the sentinel node
    nil->next = nil; // Point next of nil to itself
    nil->prev = nil; // Point prev of nil to itself
}

// Function to print the contents of the list
void printList(void) {
    NodePointer cur = nil->next; // Start from the first node
    int isf = 1; // Flag to manage spacing between numbers

    // Loop to print each node's key
    while (1) {
        if (cur == nil) break; // Stop if we reach the sentinel node
        if (isf == 0) std::cout << " "; // Print space before subsequent numbers
        std::cout << cur->key; // Print the key of the current node
        cur = cur->next; // Move to the next node
        isf = 0; // Set flag to indicate that the first number has been printed
    }
    std::cout << std::endl; // Print a newline at the end
}

// Function to delete a specific node from the list
void deleteNode(NodePointer t) {
    t->prev->next = t->next; // Bypass the node to be deleted
    t->next->prev = t->prev; // Bypass the node to be deleted
    delete t; // Free the memory allocated for the node
}

// Function to delete the first node in the list
void deleteFirst(void) {
    NodePointer t = nil->next; // Get the first node
    if (t == nil) // Check if the list is empty
        return;
    
    deleteNode(t); // Delete the first node
}

// Function to delete the last node in the list
void deleteLast(void) {
    NodePointer t = nil->prev; // Get the last node
    if (t == nil) // Check if the list is empty
        return;
    
    deleteNode(t); // Delete the last node
}

// Function to delete a node with a specific key
void delete(int key) {
    NodePointer t = listSearch(key); // Search for the node with the given key

    if (t == nil) // If the node is not found, return
        return;

    deleteNode(t); // Delete the found node
}

// Function to insert a new node with a specific key at the beginning of the list
void insert(int key) {
    NodePointer x; // Pointer for the new node
    x = new node; // Allocate memory for the new node
    x->key = key; // Set the key of the new node

    // Insert the new node at the beginning of the list
    x->next = nil->next; // Point the new node's next to the current first node
    nil->next->prev = x; // Update the current first node's previous to point to the new node
    nil->next = x; // Update the sentinel's next to point to the new node
    x->prev = nil; // Set the new node's previous to the sentinel
}

