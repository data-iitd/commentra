package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Node represents a node in the tree
type Node struct {
	pattern  int64 // Variable to store the pattern value
	index    int   // Index of the node
	children []int // List of child nodes
	parent   int   // Parent index, -1 indicates no parent
}

// NewNode creates a new node for the given index
func NewNode(i int) *Node {
	return &Node{
		index:    i,
		children: make([]int, 0),
	}
}

// SetParent sets the parent of the node and calculates the pattern
func (n *Node) SetParent(K int, parent int, use int, nodes []*Node) {
	n.pattern = int64(K-use) // Calculate the pattern based on K and used count
	n.parent = parent        // Set the parent index
	count := 1                // Initialize count of used nodes

	// If the node has a parent, increment the count
	if parent!= -1 {
		count++
	}

	// Recursively set the parent for each child node
	for _, c := range n.children {
		if c == n.parent { // Skip the parent node
			continue
		}
		nodes[c].SetParent(K, n.index, count, nodes) // Recursive call for child
		count++ // Increment count for each child processed
	}
}

// Solve the problem
func solve() {
	in := bufio.NewScanner(os.Stdin) // Create a scanner for input
	in.Split(bufio.ScanWords)

	N, K := readInt(in), readInt(in) // Read the number of nodes and value of K
	nodes := make([]*Node, N)          // Array to hold all nodes

	// Initialize nodes
	for i := 0; i < N; i++ {
		nodes[i] = NewNode(i) // Create a new node for each index
	}

	// Read edges and build the tree structure
	for i := 0; i < N-1; i++ {
		a, b := readInt(in)-1, readInt(in)-1 // Read first and second node of the edge
		nodes[a].children = append(nodes[a].children, b) // Add b as a child of a
		nodes[b].children = append(nodes[b].children, a) // Add a as a child of b (undirected tree)
	}

	in.Scan() // Discard the newline character

	// Set the parent for the root node (node 0)
	nodes[0].SetParent(K, -1, 0, nodes)

	patterns := int64(1) // Variable to store the product of patterns

	// Calculate the product of all node patterns
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % 1_000_000_007 // Update patterns with modulo
	}

	// Output the final result
	fmt.Println(patterns)
}

// ReadInt reads a single integer from stdin
func readInt(in *bufio.Scanner) int {
	in.Scan()
	i, _ := strconv.Atoi(in.Text())
	return i
}

func main() {
	solve()
}

