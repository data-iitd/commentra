
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
    int key;
    struct _node *next;
    struct _node *prev;
} node;

node *head; // Initialize head pointer to NULL

node *makenode(int a)
{
    node *x; // Allocate memory for new node
    x = malloc(sizeof(node));
    x->key = a; // Set the key value of the new node
    return x; // Return the new node
}
// Initialize the head node with a dummy node
void init()
{
    head = makenode(0);
    head->next = head;
    head->prev = head;
}

void init()
{
    if(head == NULL) // Check if head is NULL, if so initialize it
    {
        init();
    }
}

void insert(int a)
{
    node *x; // Allocate memory for new node
    x = makenode(a);
    
    // Insert new node at the end of the list
    x->next = head->next;
    head->next->prev = x;
    head->next = x;
    x->prev = head;
}

void delete(int a)
{
    node *x, *prev;
    x = head;
    
    // Search for the node to be deleted
    while(x->next != head)
    {
        x = x->next;
        if(x->key == a) // Found the node to be deleted
        {
            prev = x->prev; // Save the previous node
            prev->next = x->next; // Update the previous node's next pointer
            x->next->prev = prev; // Update the next node's prev pointer
            free(x); // Free the memory occupied by the deleted node
            break;
        }
    }
}

void deleteFirst()
{
    node *x;
    x = head->next; // Save the second node in a temporary variable
    
    // Update the head pointer and the previous node's next pointer
    head->next = x->next;
    x->next->prev = head;
    
    // Free the memory occupied by the first node
    free(x);
}

void deleteLast()
{
    node *x, *prev;
    x = head;
    
    // Search for the second last node
    while(x->next != head)
    {
        x = x->next;
    }
    
    prev = x->prev; // Save the previous node
    
    // Update the previous node's next pointer and the head pointer's prev pointer
    prev->next = NULL;
    head->prev = prev;
    
    // Free the memory occupied by the last node
    free(x);
}

int main()
{
    int i, n, a;
    char op[16];
    node *x;
    
    init(); // Initialize the head node
    
    scanf("%d", &n); // Read the number of operations
    
    for(i=0; i<n; i++)
    {
        scanf("%s", op); // Read the operation
        
        if(strcmp(op, "insert") == 0) // If the operation is to insert a node
        {
            scanf("%d", &a); // Read the key value of the node to be inserted
            insert(a); // Call the insert function
        }
        else if(strcmp(op, "delete") == 0) // If the operation is to delete a node
        {
            scanf("%d", &a); // Read the key value of the node to be deleted
            delete(a); // Call the delete function
        }
        else if(strcmp(op, "deleteFirst") == 0) // If the operation is to delete the first node
        {
            deleteFirst(); // Call the deleteFirst function
        }
        else if(strcmp(op, "deleteLast") == 0) // If the operation is to delete the last node
        {
            deleteLast(); // Call the deleteLast function
        }
    }
    
    x = head; // Initialize a pointer to traverse the list
    
    while(x->next != head) // Traverse the list and print the keys of the nodes
    {
        printf("%d ", x->next->key);
        x = x->next;
    }
    
    printf("\n"); // Print a newline character at the end

    return 0;
}

