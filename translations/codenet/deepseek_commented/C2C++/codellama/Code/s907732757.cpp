#include<iostream>
#include<cstdlib>
#include<cstring>

// Define the structure for a node in the doubly linked list
struct node
{
    int key;          // The value stored in the node
    struct node *next; // Pointer to the next node
    struct node *prev; // Pointer to the previous node
};

node *head; // Global pointer to the head of the doubly linked list

// Function prototypes
node *makenode(int);
void insert(int);
void delete(int);
void deleteFirst();
void deleteLast();

int main()
{
    int i, n, a;
    char op[16];
    node *x;
    
    // Initialize the head node
    head = makenode(0);
    head->next = head;
    head->prev = head;
    
    // Read the number of operations
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        // Read the operation type
        scanf("%s", op);
        if(strcmp(op, "insert") == 0)
        {
            // Read the value to insert
            scanf("%d", &a);
            insert(a);
        }
        else if(strcmp(op, "delete") == 0)
        {
            // Read the value to delete
            scanf("%d", &a);
            delete(a);
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
    while(x->next != head)
    {
        printf("%d", x->next->key);
        x = x->next;
        if(x->next != head)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

// Function to create a new node with the given key
node *makenode(int a)
{
    node *x;
    x = new node; // Allocate memory for the new node
    x->key = a; // Set the key of the new node
    x->next = NULL; // Initialize next pointer to NULL
    x->prev = NULL; // Initialize prev pointer to NULL
    return x; // Return the pointer to the new node
}

// Function to insert a new node with the given key after the head node
void insert(int a)
{
    node *x;
    x = makenode(a); // Create a new node
    x->next = head->next; // Set the next pointer of the new node to the current head->next
    head->next->prev = x; // Set the prev pointer of the current head->next to the new node
    head->next = x; // Set the next pointer of the head to the new node
    x->prev = head; // Set the prev pointer of the new node to the head
}

// Function to delete the node with the given key
void delete(int a)
{
    node *x;
    x = head;
    
    // Traverse the list to find the node with the given key
    while(x->next != head)
    {
        x = x->next;
        if(x->key == a)
        {
            x->prev->next = x->next; // Update the next pointer of the previous node
            x->next->prev = x->prev; // Update the prev pointer of the next node
            delete x; // Free the memory of the node to be deleted
            break; // Exit the loop after deleting the node
        }
    }
}

// Function to delete the first node after the head node
void deleteFirst()
{
    node *x;
    x = head->next; // Get the first node
    head->next = x->next; // Update the next pointer of the head to the node after the first node
    x->next->prev = head; // Update the prev pointer of the node after the first node to the head
    delete x; // Free the memory of the node to be deleted
}

// Function to delete the last node before the head node
void deleteLast()
{
    node *x;
    x = head->prev; // Get the last node
    head->prev = x->prev; // Update the prev pointer of the head to the node before the last node
    x->prev->next = head; // Update the next pointer of the node before the last node to the head
    delete x; // Free the memory of the node to be deleted
}

