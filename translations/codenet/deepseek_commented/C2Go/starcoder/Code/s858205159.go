<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

// Define the structure for a node in the doubly linked list
type node struct {
	key  int
	next *node
	prev *node
}

// Type alias for a pointer to a node
type NodePointer *node

// Sentinel node (dummy node) for the doubly linked list
var nil = &node{0, nil, nil}

// Function to search for a node with a given key
func listSearch(key int) NodePointer {
	cur := nil.next
	for cur!= nil {
		if cur.key == key {
			break
		}
		cur = cur.next
	}
	return cur
}

// Function to initialize the doubly linked list with a sentinel node
func init() {
	nil.next = nil
	nil.prev = nil
}

// Function to print the entire list starting from the first node
func printList() {
	cur := nil.next
	isf := true
	for {
		if cur == nil {
			break
		}
		if isf == false {
			print(" ")
		}
		print(cur.key)
		cur = cur.next
		isf = false
	}
	print("\n")
}

// Function to delete a specified node from the list
func deleteNode(t *node) {
	if t == nil {
		return
	}
	t.prev.next = t.next
	t.next.prev = t.prev
	free(t)
}

// Function to delete the first node in the list
func deleteFirst() {
	t := nil.next
	if t == nil {
		return
	}
	deleteNode(t)
}

// Function to delete the last node in the list
func deleteLast() {
	t := nil.prev
	if t == nil {
		return
	}
	deleteNode(t)
}

// Function to delete the node with a specified key
func deleteKey(key int) {
	t := listSearch(key)
	if t!= nil {
		deleteNode(t)
	}
}

// Function to insert a new node with a specified key at the beginning of the list
func insert(key int) {
	x := new(node)
	x.key = key
	x.prev = nil
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
}

// Main function to read commands and manipulate the doubly linked list
func main() {
	var key, n, i int
	var com [20]byte
	var np, nd int
	var size int = 0
	scanf("%d", &n)
	init()
	for i = 0; i < n; i++ {
		scanf("%s%d", &com, &key)
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} else if com[0] == 'd' {
			if com[6] == 'F' {
				deleteFirst()
			} else if com[6] == 'L' {
				deleteLast()
			} else {
				deleteKey(key)
				nd++
			}
			size--
		}
	}
	printList()
}

