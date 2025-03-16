package main

import (
	"fmt"
	"os"
	"strconv"
)

// Inner class to represent a node in the tree
type Node struct {
	pattern int64 // Variable to store the pattern value
	index   int   // Index of the node
	children []int // List of child nodes
	parent  int   // Parent index, -1 indicates no parent
}

// Constructor to initialize the node with its index
func NewNode(i int) *Node {
	return &Node{index: i}
}

// Method to set the parent of the node and calculate the pattern
func (n *Node) SetParent(K, parent, use int, nodes []*Node) {
	n.pattern = K - use // Calculate the pattern based on K and used count
	n.parent = parent   // Set the parent index
	count := 1          // Initialize count of used nodes

	// If the node has a parent, increment the count
	if parent != -1 {
		count++
	}

	// Recursively set the parent for each child node
	for _, n := range n.children {
		if n == n.parent { // Skip the parent node
			continue
		}
		nodes[n].SetParent(K, n.index, count, nodes) // Recursive call for child
		count++                                      // Increment count for each child processed
	}
}

// Main logic to solve the problem
func solve() {
	scanner := os.Stdin // Create a scanner for input
	N, _ := strconv.Atoi(ReadLine(scanner)) // Read the number of nodes
	K, _ := strconv.Atoi(ReadLine(scanner)) // Read the value of K
	nodes := make([]*Node, N)                // Array to hold all nodes

	// Initialize nodes
	for i := 0; i < N; i++ {
		nodes[i] = NewNode(i) // Create a new node for each index
	}

	// Read edges and build the tree structure
	for i := 0; i < N-1; i++ {
		a, _ := strconv.Atoi(ReadLine(scanner)) // Read first node of the edge
		b, _ := strconv.Atoi(ReadLine(scanner)) // Read second node of the edge
		nodes[a].children = append(nodes[a].children, b) // Add b as a child of a
		nodes[b].children = append(nodes[b].children, a) // Add a as a child of b (undirected tree)
	}

	// Set the parent for the root node (node 0)
	nodes[0].SetParent(K, -1, 0, nodes)

	patterns := int64(1) // Variable to store the product of patterns

	// Calculate the product of all node patterns
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % 1000000007 // Update patterns with modulo
	}

	// Output the final result
	fmt.Println(patterns)
}

// ReadLine reads a line of text from stdin and returns it with the newline character removed
func ReadLine(reader *os.File) string {
	buffer := make([]byte, 0)
	for {
		l, p, e := reader.ReadLine()
		buffer = append(buffer, l...)
		if e != nil {
			break
		}
		if !p {
			break
		}
	}
	return string(buffer)
}

// Main method to execute the program
func main() {
	solve() // Call the solve method to execute the logic
}

