
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a structure for a node
type node struct {
	key  int
	next *node
	prev *node
}

// Initialize a pointer to the first node
var N *node

// Initialize the linked list
func init() {
	N = new(node)
	N.next = N
	N.prev = N
}

// Print the contents of the linked list
func printList() {
	cur := N.next
	snl := 1
	for cur!= N {
		if snl == 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", cur.key)
		cur = cur.next
		snl = 0
	}
	fmt.Printf("\n")
}

// Delete the first node from the list
func deleteFirst() {
	t := N.next
	N.next = t.next
	t.next.prev = N
}

// Delete the last node from the list
func deleteLast() {
	delnode := N.prev
	N.prev = delnode.prev
	delnode.prev.next = N
	delnode = nil
}

// Delete a node with the given key from the list
func delete(skey int) {
	judge := 0
	t := N.next
	n := N.next
	for n!= N {
		if n.key == skey {
			judge = 1
			break
		}
		n = n.next
	}
	if judge == 1 {
		n = N.next
		t = n.prev
		t.next = n.next
		t.next.prev = t
		n = nil
	}
}

// Insert a new node with the given key into the list
func insert(skey int) {
	new := new(node)
	new.key = skey
	if N.next == N {
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
	} else {
		new.next = N.next
		N.next.prev = new
		N.next = new
		new.prev = N
	}
}

// Main function to read commands and perform the corresponding operations
func main() {
	var key, n, i int
	var com string
	fmt.Scanf("%d", &n)
	init()
	for i = 0; i < n; i++ {
		fmt.Scanf("%s", &com)
		if strings.Compare(com, "insert") == 0 {
			fmt.Scanf("%d", &key)
			insert(key)
		} else if strings.Compare(com, "deleteFirst") == 0 {
			deleteFirst()
		} else if strings.Compare(com, "deleteLast") == 0 {
			deleteLast()
		} else {
			fmt.Scanf("%d", &key)
			delete(key)
		}
	}
	printList()
}

