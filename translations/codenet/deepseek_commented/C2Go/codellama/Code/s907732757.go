#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the structure for a node in the doubly linked list
type node struct
{
    key int;          // The value stored in the node
    next *node; // Pointer to the next node
    prev *node; // Pointer to the previous node
}

var head *node // Global pointer to the head of the doubly linked list

// Function prototypes
func makenode(int) *node
func insert(int)
func delete(int)
func deleteFirst()
func deleteLast()

func main()
{
    var i, n, a int
    var op string
    var x *node
    
    // Initialize the head node
    head = makenode(0)
    head.next = head
    head.prev = head
    
    // Read the number of operations
    fmt.Scanf("%d", &n)
    for i = 0; i < n; i++
    {
        // Read the operation type
        fmt.Scanf("%s", &op)
        if strings.Compare(op, "insert") == 0
        {
            // Read the value to insert
            fmt.Scanf("%d", &a)
            insert(a)
        }
        else if strings.Compare(op, "delete") == 0
        {
            // Read the value to delete
            fmt.Scanf("%d", &a)
            delete(a)
        }
        else if strings.Compare(op, "deleteFirst") == 0
        {
            deleteFirst()
        }
        else if strings.Compare(op, "deleteLast") == 0
        {
            deleteLast()
        }
    }
    
    // Print the list
    x = head
    for x.next != head
    {
        fmt.Printf("%d", x.next.key)
        x = x.next
        if x.next != head
        {
            fmt.Printf(" ")
        }
    }
    fmt.Printf("\n")

    return 0
}

// Function to create a new node with the given key
func makenode(a int) *node
{
    var x *node
    x = new(node) // Allocate memory for the new node
    x.key = a // Set the key of the new node
    x.next = nil // Initialize next pointer to NULL
    x.prev = nil // Initialize prev pointer to NULL
    return x // Return the pointer to the new node
}

// Function to insert a new node with the given key after the head node
func insert(a int)
{
    var x *node
    x = makenode(a) // Create a new node
    x.next = head.next // Set the next pointer of the new node to the current head->next
    head.next.prev = x // Set the prev pointer of the current head->next to the new node
    head.next = x // Set the next pointer of the head to the new node
    x.prev = head // Set the prev pointer of the new node to the head
}

// Function to delete the node with the given key
func delete(a int)
{
    var x *node
    x = head
    
    // Traverse the list to find the node with the given key
    for x.next != head
    {
        x = x.next
        if x.key == a
        {
            x.prev.next = x.next // Update the next pointer of the previous node
            x.next.prev = x.prev // Update the prev pointer of the next node
            free(x) // Free the memory of the node to be deleted
            break // Exit the loop after deleting the node
        }
    }
}

// Function to delete the first node after the head node
func deleteFirst()
{
    var x *node
    x = head.next // Get the first node
    head.next = x.next // Update the next pointer of the head to the node after the first node
    x.next.prev = head // Update the prev pointer of the node after the first node to the head
    free(x) // Free the memory of the node to be deleted
}

// Function to delete the last node before the head node
func deleteLast()
{
    var x *node
    x = head.prev // Get the last node
    head.prev = x.prev // Update the prev pointer of the head to the node before the last node
    x.prev.next = head // Update the next pointer of the node before the last node to the head
    free(x) // Free the memory of the node to be deleted
}

