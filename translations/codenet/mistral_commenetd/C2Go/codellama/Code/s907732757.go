
package main

import (
    "fmt"
    "strings"
)

type node struct {
    key int
    next *node
    prev *node
}

var head *node // Initialize head pointer to nil

func makenode(a int) *node {
    x := new(node) // Allocate memory for new node
    x.key = a // Set the key value of the new node
    return x // Return the new node
}

// Initialize the head node with a dummy node
func init() {
    head = makenode(0)
    head.next = head
    head.prev = head
}

func init() {
    if head == nil { // Check if head is nil, if so initialize it
        init()
    }
}

func insert(a int) {
    x := makenode(a) // Allocate memory for new node
    
    // Insert new node at the end of the list
    x.next = head.next
    head.next.prev = x
    head.next = x
    x.prev = head
}

func delete(a int) {
    x := head // Initialize x to head
    
    // Search for the node to be deleted
    for x.next != head {
        x = x.next
        if x.key == a { // Found the node to be deleted
            prev := x.prev // Save the previous node
            prev.next = x.next // Update the previous node's next pointer
            x.next.prev = prev // Update the next node's prev pointer
            x = nil // Free the memory occupied by the deleted node
            break
        }
    }
}

func deleteFirst() {
    x := head.next // Save the second node in a temporary variable
    
    // Update the head pointer and the previous node's next pointer
    head.next = x.next
    x.next.prev = head
    
    // Free the memory occupied by the first node
    x = nil
}

func deleteLast() {
    x := head // Initialize x to head
    
    // Search for the second last node
    for x.next != head {
        x = x.next
    }
    
    prev := x.prev // Save the previous node
    
    // Update the previous node's next pointer and the head pointer's prev pointer
    prev.next = nil
    head.prev = prev
    
    // Free the memory occupied by the last node
    x = nil
}

func main() {
    var i, n, a int
    var op string
    var x *node
    
    init() // Initialize the head node
    
    fmt.Scan(&n) // Read the number of operations
    
    for i = 0; i < n; i++ {
        fmt.Scan(&op) // Read the operation
        
        if strings.Compare(op, "insert") == 0 { // If the operation is to insert a node
            fmt.Scan(&a) // Read the key value of the node to be inserted
            insert(a) // Call the insert function
        } else if strings.Compare(op, "delete") == 0 { // If the operation is to delete a node
            fmt.Scan(&a) // Read the key value of the node to be deleted
            delete(a) // Call the delete function
        } else if strings.Compare(op, "deleteFirst") == 0 { // If the operation is to delete the first node
            deleteFirst() // Call the deleteFirst function
        } else if strings.Compare(op, "deleteLast") == 0 { // If the operation is to delete the last node
            deleteLast() // Call the deleteLast function
        }
    }
    
    x = head // Initialize a pointer to traverse the list
    
    for x.next != head { // Traverse the list and print the keys of the nodes
        fmt.Printf("%d ", x.next.key)
        x = x.next
    }
    
    fmt.Printf("\n") // Print a newline character at the end
}

