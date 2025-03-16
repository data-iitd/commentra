
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define the Node class to represent each node in the graph
type Node struct {
	val  int
	color bool
	a    [][2] *Node
}

// Read the number of nodes in the graph
func readNodes() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// Read each edge in the graph and establish connections between nodes
func readEdges(nodes []*Node) {
	for i := 0; i < len(nodes); i++ {
		for j := 0; j < len(nodes); j++ {
			var u, v, w int
			fmt.Scanf("%d %d %d", &u, &v, &w)
			if i == u-1 && j == v-1 {
				nodes[i].a = append(nodes[i].a, [2]*Node{nodes[j], w})
				nodes[j].a = append(nodes[j].a, [2]*Node{nodes[i], w})
			}
		}
	}
}

// Set the root node to the first node in the list
func setRoot(nodes []*Node) *Node {
	return nodes[0]
}

// Set the color of the root node to True
func setColor(root *Node) {
	root.color = true
}

// Initialize a set to keep track of visited nodes
var nodeSet = make(map[*Node]bool)

// Define the traverse function to recursively traverse the graph
func traverse(node *Node, distance int) {
	if nodeSet[node] {
		return
	}
	nodeSet[node] = true
	for _, pair := range node.a {
		adjNode := pair[0]
		dis := pair[1]
		if (distance + dis) % 2 == 0 {
			adjNode.color = root.color
		} else {
			adjNode.color =!root.color
		}
		traverse(adjNode, distance+dis)
	}
}

// Call the traverse function starting from the root node with a distance of 0
func main() {
	n := readNodes()
	nodes := make([]*Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = &Node{}
	}
	readEdges(nodes)
	root := setRoot(nodes)
	setColor(root)
	traverse(root, 0)
	for _, node := range nodes {
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

