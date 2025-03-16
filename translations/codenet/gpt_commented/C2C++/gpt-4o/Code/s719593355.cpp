#include <iostream>
#include <string>

using namespace std;

// Define a doubly linked list node structure
struct Node {
    unsigned int key;          // Key value of the node
    Node* next;               // Pointer to the next node
    Node* prev;               // Pointer to the previous node
};

class DoublyLinkedList {
private:
    Node* nil; // Sentinel node to represent the head and tail of the list

public:
    // Constructor to initialize the doubly linked list
    DoublyLinkedList() {
        nil = new Node(); // Allocate memory for the sentinel node
        nil->next = nil;  // Point next of nil to itself
        nil->prev = nil;  // Point prev of nil to itself
    }

    // Destructor to clean up the list
    ~DoublyLinkedList() {
        while (nil->next != nil) {
            deleteFirst();
        }
        delete nil; // Free the sentinel node
    }

    // Function prototypes
    Node* listSearch(int key);
    void printList();
    void deleteNode(Node* t);
    void deleteFirst();
    void deleteLast();
    void deleteKey(int key);
    void insert(int key);
};

// Function to search for a node with a specific key
Node* DoublyLinkedList::listSearch(int key) {
    Node* cur = nil->next; // Start searching from the first node

    // Traverse the list until the end or until the key is found
    while (cur != nil && cur->key != key)
        cur = cur->next;

    return cur; // Return the found node or nil if not found
}

// Function to print the contents of the list
void DoublyLinkedList::printList() {
    Node* cur = nil->next; // Start from the first node
    bool isFirst = true;   // Flag to manage spacing between numbers

    // Loop to print each node's key
    while (cur != nil) {
        if (!isFirst) cout << " "; // Print space before subsequent numbers
        cout << cur->key; // Print the key of the current node
        cur = cur->next; // Move to the next node
        isFirst = false; // Set flag to indicate that the first number has been printed
    }
    cout << endl; // Print a newline at the end
}

// Function to delete a specific node from the list
void DoublyLinkedList::deleteNode(Node* t) {
    t->prev->next = t->next; // Bypass the node to be deleted
    t->next->prev = t->prev; // Bypass the node to be deleted
    delete t; // Free the memory allocated for the node
}

// Function to delete the first node in the list
void DoublyLinkedList::deleteFirst() {
    Node* t = nil->next; // Get the first node
    if (t == nil) // Check if the list is empty
        return;

    deleteNode(t); // Delete the first node
}

// Function to delete the last node in the list
void DoublyLinkedList::deleteLast() {
    Node* t = nil->prev; // Get the last node
    if (t == nil) // Check if the list is empty
        return;

    deleteNode(t); // Delete the last node
}

// Function to delete a node with a specific key
void DoublyLinkedList::deleteKey(int key) {
    Node* t = listSearch(key); // Search for the node with the given key

    if (t == nil) // If the node is not found, return
        return;

    deleteNode(t); // Delete the found node
}

// Function to insert a new node with a specific key at the beginning of the list
void DoublyLinkedList::insert(int key) {
    Node* x = new Node(); // Allocate memory for the new node
    x->key = key; // Set the key of the new node

    // Insert the new node at the beginning of the list
    x->next = nil->next; // Point the new node's next to the current first node
    nil->next->prev = x; // Update the current first node's previous to point to the new node
    nil->next = x; // Update the sentinel's next to point to the new node
    x->prev = nil; // Set the new node's previous to the sentinel
}

int main() {
    int key, n; // Variables for key and number of operations
    string command; // Variable to hold command strings
    int np = 0, nd = 0; // Counters for number of insertions and deletions

    // Read the number of operations to perform
    cin >> n;

    // Initialize the doubly linked list
    DoublyLinkedList list;

    // Loop to process each operation
    for (int i = 0; i < n; i++) {
        // Read command and key value
        cin >> command >> key;

        // If the command is to insert a node
        if (command[0] == 'i') {
            list.insert(key); // Insert the key into the list
            np++; // Increment the insertion counter
        }
        // If the command is to delete a node
        else if (command[0] == 'd') {
            // Check for specific delete commands (delete first or last)
            if (command.length() > 6) {
                if (command[6] == 'F') {
                    list.deleteFirst(); // Delete the first node
                } else if (command[6] == 'L') {
                    list.deleteLast(); // Delete the last node
                }
            } else {
                list.deleteKey(key); // Delete the node with the specified key
                nd++; // Increment the deletion counter
            }
        }
    }

    // Print the final state of the list
    list.printList();

    return 0; // Exit the program
}

// <END-OF-CODE>
