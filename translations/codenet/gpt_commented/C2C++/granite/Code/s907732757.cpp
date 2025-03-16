
#include<iostream>
#include<cstdlib>
#include<cstring>

// Define a doubly linked list node structure
struct _node
{
    int key;                // Value of the node
    _node *next;    // Pointer to the next node
    _node *prev;    // Pointer to the previous node
};

typedef _node node;

node *head; // Pointer to the head of the doubly linked list

// Function prototypes for node operations
node *makenode(int);
void insert(int);
void deleteNode(int);
void deleteFirst();
void deleteLast();

int main()
{
    int i, n, a;           // Variables for loop index, number of operations, and value to insert/delete
    char op[16];          // Array to hold operation commands
    node *x;              // Temporary node pointer for traversal
    
    // Initialize the head node of the doubly linked list
    head = new node;
    head->next = head;    // Point next of head to itself (circular)
    head->prev = head;    // Point prev of head to itself (circular)
    
    // Read the number of operations to perform
    std::cin >> n;
    for(i = 0; i < n; i++)
    {
        // Read the operation command
        std::cin >> op;
        if(strcmp(op, "insert") == 0) // Check if the operation is "insert"
        {
            std::cin >> a; // Read the value to insert
            insert(a);       // Call insert function
        }
        else if(strcmp(op, "delete") == 0) // Check if the operation is "delete"
        {
            std::cin >> a; // Read the value to delete
            deleteNode(a);       // Call delete function
        }
        else if(strcmp(op, "deleteFirst") == 0) // Check if the operation is "deleteFirst"
        {
            deleteFirst();   // Call function to delete the first node
        }
        else if(strcmp(op, "deleteLast") == 0) // Check if the operation is "deleteLast"
        {
            deleteLast();    // Call function to delete the last node
        }
    }
    
    // Print the remaining elements in the list
    x = head;
    while(x->next!= head) // Traverse the list until we reach the head again
    {
        std::cout << x->next->key << " "; // Print the key of the next node
        x = x->next; // Move to the next node
    }
    std::cout << std::endl; // Print newline after all elements

    return 0; // Return success
}

// Function to create a new node with a given key
node *makenode(int a)
{
    node *x; // Temporary node pointer
    x = new node; // Allocate memory for a new node
    x->key = a; // Set the key of the new node
    return x; // Return the new node
}

// Function to insert a new node with a given key at the beginning of the list
void insert(int a)
{
    node *x; // Temporary node pointer
    x = madeNode(a); // Create a new node
    x->next = head->next; // Set the new node's next to the current first node
    head->next->prev = x; // Update the current first node's previous to the new node
    head->next = x; // Update head's next to the new node
    x->prev = head; // Set the new node's previous to head
}

// Function to delete a node with a given key from the list
void deleteNode(int a)
{
    node *x; // Temporary node pointer
    x = head; // Start from the head
    
    // Traverse the list to find the node with the given key
    while(x->next!= head)
    {
        x = x->next; // Move to the next node
        if(x->key == a) // Check if the current node's key matches the key to delete
        {
            // Update the pointers to remove the node from the list
            x->prev->next = x->next; // Bypass the node to delete it
            x->next->prev = x->prev; // Update the previous node's next pointer
            delete x; // Free the memory of the deleted node
            break; // Exit the loop after deletion
        }
    }
}

// Function to delete the first node in the list
void deleteFirst()
{
    node *x; // Temporary node pointer
    x = head->next; // Get the first node
    head->next = x->next; // Update head's next to the second node
    x->next->prev = head; // Update the new first node's previous to head
    delete x; // Free the memory of the deleted node
}

// Function to delete the last node in the list
void deleteLast()
{
    node *x; // Temporary node pointer
    x = head->prev; // Get the last node
    head->prev = x->prev; // Update head's previous to the second last node
    x->prev->next = head; // Update the new last node's next to head
    delete x; // Free the memory of the deleted node
}

