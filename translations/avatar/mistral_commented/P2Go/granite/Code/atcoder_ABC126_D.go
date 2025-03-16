

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a Node struct
type Node struct {
	val        int
	color      bool
	adjacencies []*Node
}

// Initialize the root node
func initRootNode(nodes []*Node) *Node {
	root := nodes[0]
	root.val = 0
	root.color = true
	return root
}

// Read input and initialize nodes
func initNodes(n int) []*Node {
	nodes := make([]*Node, n)
	for i := 0; i < n; i++ {
		nodes[i] = &Node{}
	}
	return nodes
}

// Read edges and add adjacencies to nodes
func initAdjacencies(nodes []*Node, n int) {
	for i := 0; i < n-1; i++ {
		u, v, w := readInt32()
		nodeU := nodes[u-1]
		nodeV := nodes[v-1]
		nodeU.val = int(u)
		nodeV.val = int(v)
		nodeU.adjacencies = append(nodeU.adjacencies, nodeV)
		nodeV.adjacencies = append(nodeV.adjacencies, nodeU)
	}
}

// Traverse the graph and color nodes based on their distance from the root
func traverse(node *Node, distance int) {
	if node == nil {
		return
	}
	if node.color {
		return
	}
	node.color = true
	for _, adj := range node.adjacencies {
		traverse(adj, distance+1)
	}
}

// Print the color of each node
func printColors(nodes []*Node) {
	for _, node := range nodes {
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

// Read input and return an integer
func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

// Read input and return an integer32
func readInt32() (int32, int32, int32) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	fields := strings.Fields(sc.Text())
	u, _ := strconv.ParseInt(fields[0], 10, 32)
	v, _ := strconv.ParseInt(fields[1], 10, 32)
	w, _ := strconv.ParseInt(fields[2], 10, 32)
	return int32(u), int32(v), int32(w)
}

func main() {
	n := readInt()
	nodes := initNodes(n)
	initAdjacencies(nodes, n)
	root := initRootNode(nodes)
	traverse(root, 0)
	printColors(nodes)
}

