<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Define the maximum number of nodes
const MAX = 25

// Define the node structure
type node struct {
	l, r, par int
}

var N [MAX]node

// Function declarations
func init(n int) {
	for i := 0; i < n; i++ {
		N[i].par = N[i].l = N[i].r = -1
	}
}

// Preorder traversal: root, left, right
func Preorder(p int) {
	if p!= -1 {
		fmt.Printf(" %d", p) // Print current node
		Preorder(N[p].l) // Recursively traverse left subtree
		Preorder(N[p].r) // Recursively traverse right subtree
	}
}

// Inorder traversal: left, root, right
func Inorder(p int) {
	if p!= -1 {
		Inorder(N[p].l) // Recursively traverse left subtree
		fmt.Printf(" %d", p) // Print current node
		Inorder(N[p].r) // Recursively traverse right subtree
	}
}

// Postorder traversal: left, right, root
func Postorder(p int) {
	if p!= -1 {
		Postorder(N[p].l) // Recursively traverse left subtree
		Postorder(N[p].r) // Recursively traverse right subtree
		fmt.Printf(" %d", p) // Print current node
	}
}

func main() {
	var n, i, id, l, r int
	var p int

	fmt.Scanf("%d", &n) // Read the number of nodes
	init(n) // Initialize the nodes

	// Read each node's id, left child, and right child
	for i = 0; i < n; i++ {
		fmt.Scanf("%d%d%d", &id, &l, &r)

		if l!= -1 {
			N[id].l = l // Set left child
			N[l].par = id // Set parent of left child
		}
		if r!= -1 {
			N[id].r = r // Set right child
			N[r].par = id // Set parent of right child
		}
	}

	// Find the root node (the node with no parent)
	for i = 0; i < n; i++ {
		if N[i].par == -1 {
			p = i // Store the index of the root node
			break
		}
	}

	// Print the preorder, inorder, and postorder traversals
	fmt.Println("Preorder")
	Preorder(p)
	fmt.Println("")

	fmt.Println("Inorder")
	Inorder(p)
	fmt.Println("")

	fmt.Println("Postorder")
	Postorder(p)
	fmt.Println("")
}

