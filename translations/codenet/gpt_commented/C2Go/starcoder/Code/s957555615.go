package main

// Define the structure for a node in the binary search tree
type node struct {
	right *node
	left  *node
	parent *node
	key int
}

var root *node

// Function to find the minimum node in a subtree
func treeMinimum(x *node) *node {
	for x.left!= nil { // Traverse to the leftmost node
		x = x.left
	}
	return x
}

// Function to find the maximum node in a subtree
func treeMaximum(x *node) *node {
	for x.right!= nil { // Traverse to the rightmost node
		x = x.right
	}
	return x
}

// Function to search for a node with a specific key in the tree
func treeSearch(u *node, k int) *node {
	if u == nil || k == u.key { // Base case: found the node or reached a leaf
		return u
	}

	// Recursively search in the left or right subtree based on the key
	if k < u.key {
		return treeSearch(u.left, k)
	} else {
		return treeSearch(u.right, k)
	}
}

// Function to find the successor of a given node in the binary search tree
func treeSuccessor(x *node) *node {
	var y *node
	if x.right!= nil { // If right child exists, successor is the minimum in the right subtree
		return treeMinimum(x.right)
	}

	y = x.parent
	// Traverse up the tree until we find a node that is a left child
	for y!= nil && x == y.right {
		x = y
		y = y.parent
	}
	return y
}

// Function to delete a node from the binary search tree
func treeDelete(z *node) {
	var y *node // Node to be deleted
	var x *node // Child of y

	// Determine the node to delete (y) based on the number of children
	if z.left == nil || z.right == nil {
		y = z
	} else {
		y = treeSuccessor(z)
	}

	// Determine the child of y
	if y.left!= nil {
		x = y.left
	} else {
		x = y.right
	}

	// Update the parent of x if it exists
	if x!= nil {
		x.parent = y.parent
	}

	// Update the parent's child pointer to x
	if y.parent == nil {
		root = x
	} else if y == y.parent.left {
		y.parent.left = x
	} else {
		y.parent.right = x
	}

	// Copy the key from y to z if they are different
	if y!= z {
		z.key = y.key
	}
}

// Function to insert a new key into the binary search tree
func insert(k int) {
	var y *node // Parent node
	var x *node // Current node
	var z *node // New node to be inserted

	// Allocate memory for the new node and set its key
	z = new(node)
	z.key = k
	z.left = nil
	z.right = nil

	// Find the appropriate position for the new node
	for x!= nil {
		y = x
		if z.key < x.key {
			x = x.left
		} else {
			x = x.right
		}
	}
	z.parent = y
	if y == nil {
		root = z
	} else if z.key < y.key {
		y.left = z
	} else {
		y.right = z
	}
}

// Function for inorder traversal of the tree
func inorder(u *node) {
	if u == nil {
		return
	}
	inorder(u.left)
	fmt.Printf(" %d", u.key)
	inorder(u.right)
}

// Function for preorder traversal of the tree
func preorder(u *node) {
	if u == nil {
		return
	}
	fmt.Printf(" %d", u.key)
	preorder(u.left)
	preorder(u.right)
}

// Main function to execute the program
func main() {
	var n, i, x int
	var com [20]byte

	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%s", &com)
		if com[0] == 'f' {
			fmt.Scanf("%d", &x)
			t := treeSearch(root, x)
			if t!= nil {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		} else if com[0] == 'i' {
			fmt.Scanf("%d", &x)
			insert(x)
		} else if com[0] == 'p' {
			inorder(root)
			fmt.Println()
			preorder(root)
			fmt.Println()
		} else if com[0] == 'd' {
			fmt.Scanf("%d", &x)
			treeDelete(treeSearch(root, x))
		}
	}
}

