
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Node struct to store the information of a node
type Node struct {
	pattern  int
	index    int
	children []int
	parent   int
}

// Main function
func main() {
	var N, K int
	var nodes []Node
	var in string
	var a, b int
	var patterns int

	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &N, &K)

	// Creating an array of Node objects
	nodes = make([]Node, N)
	for i := 0; i < N; i++ {
		nodes[i] = Node{0, i, make([]int, 0), -1}
	}

	// Reading the edges and adding them to the linked list of children for both nodes
	for i := 0; i < N-1; i++ {
		in, _ = reader.ReadString('\n')
		in = strings.TrimSpace(in)
		a, _ = strconv.Atoi(strings.Split(in, " ")[0])
		b, _ = strconv.Atoi(strings.Split(in, " ")[1])
		nodes[a-1].children = append(nodes[a-1].children, b-1)
		nodes[b-1].children = append(nodes[b-1].children, a-1)
	}

	// Setting the parent and calculating the pattern for the root node
	nodes[0].setParent(K, -1, 0, nodes)

	// Calculating the pattern for the entire tree by multiplying the patterns of subtrees and taking the modulo with 1,000,000,007
	patterns = 1
	for i := 0; i < N; i++ {
		patterns = (patterns * nodes[i].pattern) % 1_000_000_007
	}

	// Printing the result
	fmt.Println(patterns)
}

// setParent method to set the parent of this node and calculate its pattern
func (node *Node) setParent(K, parent, use int, nodes []Node) {
	node.pattern = K - use
	node.parent = parent
	count := 1
	if parent!= -1 {
		count++
	}
	for _, n := range node.children {
		if n == node.parent {
			continue
		}
		nodes[n].setParent(K, node.index, count, nodes)
		count++
	}
}

