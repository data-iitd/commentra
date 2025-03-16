
#include<iostream>
#include<cstdlib>
#include<cstring>

// Define the structure for a node in the doubly linked list
struct _node
{
    int key;          // The value stored in the node
    _node *next; // Pointer to the next node
    _node *prev; // Pointer to the previous node
};

typedef _node node;

node *head; // Global pointer to the head of the doubly linked list

// Function prototypes
node *makenode(int);
void insert(int);
void deleteNode(int);
void deleteFirst();
void deleteLast();

int main()
{
    int i, n, a;
    char op[16];
    node *x;
    
    // Initialize the head node
    head = new node;
    head->next = head;
    head->prev = head;
    
    // Read the number of operations
    std::cin >> n;
    for(i=0; i<n; i++)
    {
        // Read the operation type
        std::cin >> op;
        if(strcmp(op, "insert") == 0)
        {
            // Read the value to insert
            std::cin >> a;
            insert(a);
        }
        else if(strcmp(op, "delete") == 0)
        {
            // Read the value to delete
            std::cin >> a;
            deleteNode(a);
        }
        else if(strcmp(op, "deleteFirst") == 0)
        {
            deleteFirst();
        }
        else if(strcmp(op, "deleteLast") == 0)
        {
            deleteLast();
        }
    }
    
    // Print the list
    x = head;
    while(x->next!= head)
    {
        std::cout << x->next->key << " ";
        x = x->next;
    }
    std::cout << "\n";

    return 0;
}

// Function to create a new node with the given key
node *makenode(int a)
{
    node *x = new node;
    x->key = a;
    x->next = NULL;
    x->prev = NULL;
    return x;
}

// Function to insert a new node with the given key after the head node
void insert(int a)
{
    node *x = new node;
    x->key = a;
    x->next = head->next;
    head->next->prev = x;
    head->next = x;
    x->prev = head;
}

// Function to delete the node with the given key
void deleteNode(int a)
{
    node *x = head;
    
    // Traverse the list to find the node with the given key
    while(x->next!= head)
    {
        x = x->next;
        if(x->key == a)
        {
            x->prev->next = x->next;
            x->next->prev = x->prev;
            delete x;
            break;
        }
    }
}

// Function to delete the first node after the head node
void deleteFirst()
{
    node *x = head->next;
    head->next = x->next;
    x->next->prev = head;
    delete x;
}

// Function to delete the last node before the head node
void deleteLast()
{
    node *x = head->prev;
    head->prev = x->prev;
    x->prev->next = head;
    delete x;
}

The above C++ code is a translation of the given C code. It includes the necessary header files and defines the structure for a node in the doubly linked list. The main function reads the number of operations and performs the specified operations on the doubly linked list. The insert, deleteNode, deleteFirst, and deleteLast functions are implemented to insert, delete, and manipulate the nodes in the list. The code also includes the necessary memory management for creating and deleting nodes.