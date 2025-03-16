#include <iostream>
#include <string>

using namespace std;

// Define the structure for a node in the doubly linked list
struct Node {
    int key;          // The value stored in the node
    Node* next;      // Pointer to the next node
    Node* prev;      // Pointer to the previous node
};

// Global pointer to the head of the doubly linked list
Node* head;

// Function prototypes
Node* makenode(int);
void insert(int);
void deleteNode(int);
void deleteFirst();
void deleteLast();

int main() {
    int n, a;
    string op;

    // Initialize the head node
    head = makenode(0);
    head->next = head;
    head->prev = head;

    // Read the number of operations
    cin >> n;
    for (int i = 0; i < n; i++) {
        // Read the operation type
        cin >> op;
        if (op == "insert") {
            // Read the value to insert
            cin >> a;
            insert(a);
        } else if (op == "delete") {
            // Read the value to delete
            cin >> a;
            deleteNode(a);
        } else if (op == "deleteFirst") {
            deleteFirst();
        } else if (op == "deleteLast") {
            deleteLast();
        }
    }

    // Print the list
    Node* x = head;
    while (x->next != head) {
        cout << x->next->key;
        x = x->next;
        if (x->next != head) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

// Function to create a new node with the given key
Node* makenode(int a) {
    Node* x = new Node(); // Allocate memory for the new node
    x->key = a;           // Set the key of the new node
    x->next = nullptr;    // Initialize next pointer to nullptr
    x->prev = nullptr;    // Initialize prev pointer to nullptr
    return x;            // Return the pointer to the new node
}

// Function to insert a new node with the given key after the head node
void insert(int a) {
    Node* x = makenode(a); // Create a new node
    x->next = head->next;  // Set the next pointer of the new node to the current head->next
    head->next->prev = x;  // Set the prev pointer of the current head->next to the new node
    head->next = x;        // Set the next pointer of the head to the new node
    x->prev = head;        // Set the prev pointer of the new node to the head
}

// Function to delete the node with the given key
void deleteNode(int a) {
    Node* x = head;

    // Traverse the list to find the node with the given key
    while (x->next != head) {
        x = x->next;
        if (x->key == a) {
            x->prev->next = x->next; // Update the next pointer of the previous node
            x->next->prev = x->prev; // Update the prev pointer of the next node
            delete x;                // Free the memory of the node to be deleted
            break;                   // Exit the loop after deleting the node
        }
    }
}

// Function to delete the first node after the head node
void deleteFirst() {
    Node* x = head->next; // Get the first node
    head->next = x->next; // Update the next pointer of the head to the node after the first node
    x->next->prev = head;  // Update the prev pointer of the node after the first node to the head
    delete x;             // Free the memory of the node to be deleted
}

// Function to delete the last node before the head node
void deleteLast() {
    Node* x = head->prev; // Get the last node
    head->prev = x->prev; // Update the prev pointer of the head to the node before the last node
    x->prev->next = head;  // Update the next pointer of the node before the last node to the head
    delete x;             // Free the memory of the node to be deleted
}

// <END-OF-CODE>
