package main

import (
	"fmt"
	"os"
)

const maxRecursionLimit = 100000

// Node represents each node in the graph
type Node struct {
	val   int
	color bool
	a     [][]int // Adjacency list to store connected nodes and weights
}

var nodeSet = make(map[*Node]struct{})

// traverse recursively traverses the graph and colors the nodes
func traverse(node *Node, distance int) {
	// If the node has already been visited, return
	if _, visited := nodeSet[node]; visited {
		return
	}
	nodeSet[node] = struct{}{} // Mark the node as visited

	// Iterate through each adjacent node
	for _, pair := range node.a {
		adjNode := nodes[pair[0]] // Get the adjacent node
		dis := pair[1]            // Get the distance (weight) to the adjacent node
		// Determine the color of the adjacent node based on the distance
		if (distance + dis) % 2 == 0 {
			adjNode.color = root.color // Same color as root
		} else {
			adjNode.color = !root.color // Opposite color to root
		}
		// Recursively traverse to the adjacent node
		traverse(adjNode, distance + dis)
	}
}

var nodes []*Node
var root *Node

func main() {
	// Read the number of nodes from input
	var n int
	fmt.Scan(&n)
	nodes = make([]*Node, n)

	// Initialize nodes and store them in a slice
	for i := 0; i < n; i++ {
		nodes[i] = &Node{}
	}

	// Read edges and construct the graph
	for i := 0; i < n-1; i++ {
		var u, v, w int
		fmt.Scan(&u, &v, &w)
		node1 := nodes[u-1] // Get the first node (adjusting for 0-indexing)
		node2 := nodes[v-1] // Get the second node (adjusting for 0-indexing)
		node1.val = u       // Set the value of the first node
		node2.val = v       // Set the value of the second node
		// Add the edge to both nodes' adjacency lists
		node1.a = append(node1.a, []int{v - 1, w})
		node2.a = append(node2.a, []int{u - 1, w})
	}

	// Set the root node and initialize its color
	root = nodes[0]
	root.color = true // Color the root node as True

	// Start the traversal from the root node with an initial distance of 0
	traverse(root, 0)

	// Output the color of each node
	for i := 0; i < n; i++ {
		if nodes[i].color {
			fmt.Println(1) // Print 1 for True color
		} else {
			fmt.Println(0) // Print 0 for False color
		}
	}
}

// <END-OF-CODE>
