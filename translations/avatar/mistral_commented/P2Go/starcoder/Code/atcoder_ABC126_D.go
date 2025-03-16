
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Set the maximum recursion depth to 10^5
const maxDepth = 100000

// Define a Node class
type Node struct {
	val        int
	color      bool
	adjacencies []*Node
}

// Read input and initialize nodes
func readInput() []*Node {
	n, _ := strconv.Atoi(readLine())
	nodes := make([]*Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = &Node{
			val:        i,
			color:      false,
			adjacencies: make([]*Node, 0),
		}
	}
	return nodes
}

// Read a line from stdin
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return strings.TrimSpace(string(line))
}

// Traverse the graph and color nodes based on their distance from the root
func traverse(node *Node, distance int) {
	// Check if node has already been visited
	if node.color!= false {
		return
	}
	// Mark node as visited
	node.color = true
	// Color node based on its distance from the root
	for _, adj := range node.adjacencies {
		adj_distance := adj[1]
		if (distance + adj_distance) % 2 == 0 {
			adj[0].color = node.color
		} else {
			adj[0].color =!node.color
		}
		traverse(adj[0], distance + adj_distance)
	}
}

// Main function
func main() {
	// Read input and initialize nodes
	nodes := readInput()
	// Read edges and add adjacencies to nodes
	for i := 0; i < len(nodes)-1; i++ {
		u, v, w := readLine()
		u, _ = strconv.Atoi(u)
		v, _ = strconv.Atoi(v)
		w, _ = strconv.Atoi(w)
		nodes[u-1].adjacencies = append(nodes[u-1].adjacencies, nodes[v-1])
		nodes[v-1].adjacencies = append(nodes[v-1].adjacencies, nodes[u-1])
	}
	// Set the root node and color it
	root := nodes[0]
	root.color = true
	// Traverse the graph starting from the root
	traverse(root, 0)
	// Print the color of each node
	for _, node := range nodes {
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

