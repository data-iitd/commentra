
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

// Define a structure for a node
type node struct {
	key  int
	next *node
	prev *node
}

// Initialize nil node with nil pointers
var nil = &node{0, nil, nil}

// Function to search a node with given key
func listSearch(key int) *node {
<<<<<<< HEAD
	cur := nil.next // Initialize current node as the first node after nil
	for cur!= nil { // Traverse the list until nil is reached
		if cur.key == key {
			break
		}
		cur = cur.next // Move to the next node
=======
	cur := nil.next
	for cur!= nil {
		if cur.key == key {
			break
		}
		cur = cur.next
>>>>>>> 98c87cb78a (data updated)
	}
	return cur
}

// Initialize the linked list with a nil node
func init() {
	nil.next = nil
	nil.prev = nil
}

// Function to print the linked list
func printList() {
<<<<<<< HEAD
	cur := nil.next // Initialize current node as the first node after nil
	isf := true     // Initialize isFirst flag to true
=======
	cur := nil.next
	isf := true
>>>>>>> 98c87cb78a (data updated)
	for {
		if cur == nil {
			break
		}
		if isf {
<<<<<<< HEAD
			fmt.Printf("[%d] ", cur.key) // If it's the first node, print its key with an index
		} else {
			fmt.Printf(" %d", cur.key) // Otherwise, print only the key
		}
		cur = cur.next // Move to the next node
		isf = false    // Set isFirst flag to false
	}
	fmt.Println() // Print a newline after the list is printed
=======
			fmt.Printf("[%d] ", cur.key)
		} else {
			fmt.Printf(" %d", cur.key)
		}
		cur = cur.next
		isf = false
	}
	fmt.Printf("\n")
>>>>>>> 98c87cb78a (data updated)
}

// Function to delete a node from the linked list
func deleteNode(t *node) {
	if t == nil {
		return
	}
	t.prev.next = t.next
	t.next.prev = t.prev
	free(t)
}

// Function to delete the first node from the linked list
func deleteFirst() {
	t := nil.next
	if t == nil {
		return
	}
	deleteNode(t)
}

// Function to delete the last node from the linked list
func deleteLast() {
	t := nil.prev
	if t == nil {
		return
	}
	deleteNode(t)
}

// Function to delete a node with the given key from the linked list
func deleteKey(key int) {
	t := listSearch(key)
	if t!= nil {
		deleteNode(t)
	}
}

// Function to insert a new node with the given key into the linked list
func insert(key int) {
	x := new(node)
	x.key = key
	x.prev = nil
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
}

// Main function to read commands and perform the corresponding actions
func main() {
	var key, n, i int
	var size, np, nd int
	var com [20]byte
	fmt.Scanf("%d", &n)
	init()
	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &com, &key)
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} else if com[0] == 'd' {
			if len(com) > 6 {
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
					deleteLast()
				}
			} else {
				deleteKey(key)
				nd++
			}
			size--
		}
	}
	printList()
}

