#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the structure for a node in the doubly linked list
class Node
{
    int key;          // The value stored in the node
    Node next; // Pointer to the next node
    Node prev; // Pointer to the previous node

    // Constructor to create a new node with the given key
    Node(int a)
    {
        key = a;
        next = null;
        prev = null;
    }
}

Node head; // Global pointer to the head of the doubly linked list

// Function prototypes
Node makenode(int);
void insert(int);
void delete(int);
void deleteFirst();
void deleteLast();

int main()
{
    int i, n, a;
    String op;
    Node x;
    
    // Initialize the head node
    head = makenode(0);
    head.next = head;
    head.prev = head;
    
    // Read the number of operations
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        // Read the operation type
        scanf("%s", op);
        if(op.equals("insert"))
        {
            // Read the value to insert
            scanf("%d", &a);
            insert(a);
        }
        else if(op.equals("delete"))
        {
            // Read the value to delete
            scanf("%d", &a);
            delete(a);
        }
        else if(op.equals("deleteFirst"))
        {
            deleteFirst();
        }
        else if(op.equals("deleteLast"))
        {
            deleteLast();
        }
    }
    
    // Print the list
    x = head;
    while(x.next != head)
    {
        System.out.print(x.next.key);
        x = x.next;
        if(x.next != head)
        {
            System.out.print(" ");
        }
    }
    System.out.println();

    return 0;
}

// Function to create a new node with the given key
Node makenode(int a)
{
    Node x;
    x = new Node(a); // Allocate memory for the new node
    return x; // Return the pointer to the new node
}

// Function to insert a new node with the given key after the head node
void insert(int a)
{
    Node x;
    x = makenode(a); // Create a new node
    x.next = head.next; // Set the next pointer of the new node to the current head->next
    head.next.prev = x; // Set the prev pointer of the current head->next to the new node
    head.next = x; // Set the next pointer of the head to the new node
    x.prev = head; // Set the prev pointer of the new node to the head
}

// Function to delete the node with the given key
void delete(int a)
{
    Node x;
    x = head;
    
    // Traverse the list to find the node with the given key
    while(x.next != head)
    {
        x = x.next;
        if(x.key == a)
        {
            x.prev.next = x.next; // Update the next pointer of the previous node
            x.next.prev = x.prev; // Update the prev pointer of the next node
            x = null; // Free the memory of the node to be deleted
            break; // Exit the loop after deleting the node
        }
    }
}

// Function to delete the first node after the head node
void deleteFirst()
{
    Node x;
    x = head.next; // Get the first node
    head.next = x.next; // Update the next pointer of the head to the node after the first node
    x.next.prev = head; // Update the prev pointer of the node after the first node to the head
    x = null; // Free the memory of the node to be deleted
}

// Function to delete the last node before the head node
void deleteLast()
{
    Node x;
    x = head.prev; // Get the last node
    head.prev = x.prev; // Update the prev pointer of the head to the node before the last node
    x.prev.next = head; // Update the next pointer of the node before the last node to the head
    x = null; // Free the memory of the node to be deleted
}

