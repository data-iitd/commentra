#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key;
    Node *next;
    Node *prev;
};

Node *head = nullptr; // Initialize head pointer to nullptr

Node* makenode(int a) {
    Node *x = new Node(); // Allocate memory for new node
    x->key = a; // Set the key value of the new node
    return x; // Return the new node
}

// Initialize the head node with a dummy node
void init() {
    head = makenode(0);
    head->next = head;
    head->prev = head;
}

void insert(int a) {
    Node *x = makenode(a); // Allocate memory for new node
    
    // Insert new node at the end of the list
    x->next = head->next;
    head->next->prev = x;
    head->next = x;
    x->prev = head;
}

void deleteNode(int a) {
    Node *x = head;
    
    // Search for the node to be deleted
    while (x->next != head) {
        x = x->next;
        if (x->key == a) { // Found the node to be deleted
            Node *prev = x->prev; // Save the previous node
            prev->next = x->next; // Update the previous node's next pointer
            x->next->prev = prev; // Update the next node's prev pointer
            delete x; // Free the memory occupied by the deleted node
            break;
        }
    }
}

void deleteFirst() {
    Node *x = head->next; // Save the second node in a temporary variable
    
    // Update the head pointer and the previous node's next pointer
    head->next = x->next;
    x->next->prev = head;
    
    // Free the memory occupied by the first node
    delete x;
}

void deleteLast() {
    Node *x = head;
    
    // Search for the second last node
    while (x->next != head) {
        x = x->next;
    }
    
    Node *prev = x->prev; // Save the previous node
    
    // Update the previous node's next pointer
    prev->next = head;
    head->prev = prev;
    
    // Free the memory occupied by the last node
    delete x;
}

int main() {
    int n, a;
    string op;
    
    init(); // Initialize the head node
    
    cin >> n; // Read the number of operations
    
    for (int i = 0; i < n; i++) {
        cin >> op; // Read the operation
        
        if (op == "insert") { // If the operation is to insert a node
            cin >> a; // Read the key value of the node to be inserted
            insert(a); // Call the insert function
        } else if (op == "delete") { // If the operation is to delete a node
            cin >> a; // Read the key value of the node to be deleted
            deleteNode(a); // Call the delete function
        } else if (op == "deleteFirst") { // If the operation is to delete the first node
            deleteFirst(); // Call the deleteFirst function
        } else if (op == "deleteLast") { // If the operation is to delete the last node
            deleteLast(); // Call the deleteLast function
        }
    }
    
    Node *x = head; // Initialize a pointer to traverse the list
    
    while (x->next != head) { // Traverse the list and print the keys of the nodes
        cout << x->next->key << " ";
        x = x->next;
    }
    
    cout << endl; // Print a newline character at the end

    return 0;
}

// <END-OF-CODE>
