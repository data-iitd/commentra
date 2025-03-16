package main

// Define a structure for a doubly linked list node
type node struct {
  key int
  next *node
  prev *node
}

// Define a pointer type for the node structure
type NodePointer *node

// Function to initialize the doubly linked list
func init() {
  N := new(node) // Allocate memory for the head node
  N.next = N     // Point next of head to itself (circular)
  N.prev = N     // Point prev of head to itself (circular)
}

// Function to print the elements of the list
func printList() {
  cur := N.next // Start from the first node
  snl := 1      // Flag to manage spacing
  for cur!= N { // Traverse until we reach the head again
    if snl == 0 {
      fmt.Printf(" ") // Print space before the next number
    }
    fmt.Printf("%d", cur.key) // Print the key of the current node
    cur = cur.next
    snl = 0
  }
  fmt.Printf("\n") // Print a newline after the list
}

// Function to delete the first node in the list
func deleteFirst() {
  t := N.next // Node to be deleted (first node)
  N.next = t.next
  t.next.prev = N
}

// Function to delete the last node in the list
func deleteLast() {
  delnode := N.prev // Node to be deleted (last node)
  N.prev = delnode.prev
  delnode.prev.next = N
  free(delnode)
}

// Function to delete a node with a specific key
func delete(skey int) {
  judge := 0
  n := N.next
  for n!= N {
    if n.key == skey {
      judge = 1
      break
    }
    n = n.next
  }
  if judge == 1 {
    t := n.prev
    t.next = n.next
    t.next.prev = t
    free(n)
  }
}

// Function to insert a new node with a specific key
func insert(skey int) {
  new := new(node)
  new.key = skey
  var count int
  count = 0
  if count == 0 {
    new.next = N
    N.next = new
    new.prev = N
    N.prev = new
    count++
  } else {
    new.next = N.next
    N.next.prev = new
    N.next = new
    new.prev = N
    count++
  }
}

// Main function to execute the program
func main() {
  var key, n, i int
  var com [12]byte
  fmt.Scanf("%d", &n)
  init()
  for i = 0; i < n; i++ {
    fmt.Scanf("%s", &com)
    if string(com) == "insert" {
      fmt.Scanf("%d", &key)
      insert(key)
    } else if string(com) == "deleteFirst" {
      deleteFirst()
    } else if string(com) == "deleteLast" {
      deleteLast()
    } else {
      fmt.Scanf("%d", &key)
      delete(key)
    }
  }
  printList()
}

