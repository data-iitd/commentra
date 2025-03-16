#include <iostream>
#include <string>

using namespace std;

// Define a structure for a node
struct Node {
    int key; // Key value of the node
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node
};

// Typedef a NodePointer as a pointer to a node
typedef Node* NodePointer;
NodePointer N; // Initialize a pointer to the first node

// Initialize the linked list
void init() {
    N = new Node(); // Allocate memory for the first node
    N->next = N; // Initialize next pointer of the first node to itself
    N->prev = N; // Initialize prev pointer of the first node to itself
}

// Print the contents of the linked list
void printList() {
    NodePointer cur = N->next; // Initialize a pointer to traverse the list
    bool snl = true; // Set a flag to control the printing of spaces between numbers
    while (cur != N) { // Traverse the list until the end is reached
        if (!snl) // If a space is not required before the number, print a space
            cout << " ";
        cout << cur->key; // Print the key value of the current node
        cur = cur->next; // Move to the next node
        snl = false; // Reset the flag for the next iteration
    }
    cout << endl; // Print a newline at the end
}

// Delete the first node from the list
void deleteFirst() {
    NodePointer t = N->next; // Initialize a pointer to the second node
    N->next = t->next; // Update the next pointer of the first node to point to the third node
    t->next->prev = N; // Update the prev pointer of the third node to point to the first node
    delete t; // Free the memory occupied by the deleted node
}

// Delete the last node from the list
void deleteLast() {
    NodePointer delnode = N->prev; // Initialize a pointer to the second last node
    N->prev = delnode->prev; // Update the prev pointer of the second last node to point to the node before it
    delnode->prev->next = N; // Update the next pointer of the second last node to point to the first node
    delete delnode; // Free the memory occupied by the last node
}

// Delete a node with the given key from the list
void deleteNode(int skey) {
    bool judge = false; // Initialize a flag to check if the node to be deleted exists
    NodePointer t, n; // Initialize two pointers to traverse the list

    for (n = N->next; n != N; n = n->next) { // Traverse the list to find the node to be deleted
        if (n->key == skey) { // If the key matches, set the flag
            judge = true;
            break;
        }
    }

    if (judge) { // If the node exists, delete it
        t = n->prev; // Initialize a pointer to the node before the node to be deleted
        t->next = n->next; // Update the next pointer of the previous node to point to the next node after the deleted node
        n->next->prev = t; // Update the prev pointer of the next node to point to the previous node
        delete n; // Free the memory occupied by the deleted node
    }
}

// Insert a new node with the given key into the list
void insert(int skey) {
    NodePointer newNode = new Node(); // Allocate memory for the new node
    newNode->key = skey; // Set the key value of the new node

    if (N->next == N) { // If the list is empty, initialize the first node
        newNode->next = N;
        N->next = newNode;
        newNode->prev = N;
        N->prev = newNode;
    } else { // If the list is not empty, insert the new node at the end
        newNode->next = N->next;
        N->next->prev = newNode;
        N->next = newNode;
        newNode->prev = N;
    }
}

// Main function to read commands and perform the corresponding operations
int main() {
    int key, n;
    string com; // Initialize a string to store the command

    cin >> n; // Read the number of operations to be performed
    init(); // Initialize the linked list

    for (int i = 0; i < n; i++) { // Perform each operation in the loop
        cin >> com; // Read the command string
        if (com == "insert") { // If the command is to insert a node
            cin >> key;
            insert(key);
        } else if (com == "deleteFirst") {
            deleteFirst(); // If the command is to delete the first node
        } else if (com == "deleteLast") {
            deleteLast(); // If the command is to delete the last node
        } else { // If the command is to delete a node with a given key
            cin >> key;
            deleteNode(key);
        }
    }
    printList(); // Print the updated list after performing all the operations
    return 0;
}

// <END-OF-CODE>
