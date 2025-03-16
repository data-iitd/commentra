package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a struct to represent each node in the graph
type Node struct {
	val   int
	color bool
	a     [][]int
}

// Read the number of nodes from input
func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	nodes := make([]Node, n)

	// Initialize nodes and store them in a list
	for i := 0; i < n; i++ {
		nodes[i] = Node{val: i, a: [][]int{}}
	}

	// Read edges and construct the graph
	for i := 0; i < n-1; i++ {
		line := readLine(reader)
		parts := split(line, " ")
		u, _ := strconv.Atoi(parts[0])
		v, _ := strconv.Atoi(parts[1])
		w, _ := strconv.Atoi(parts[2])
		nodes[u-1].a = append(nodes[u-1].a, []int{v - 1, w})
		nodes[v-1].a = append(nodes[v-1].a, []int{u - 1, w})
	}

	// Set the root node and initialize its color
	root := &nodes[0]
	root.color = true
	nodeSet := make(map[int]bool)

	// Define a recursive function to traverse the graph
	var traverse func(node *Node, distance int)
	traverse = func(node *Node, distance int) {
		// If the node has already been visited, return
		if nodeSet[node.val] {
			return
		}
		nodeSet[node.val] = true

		// Iterate through each adjacent node
		for _, pair := range node.a {
			adjNode := &nodes[pair[0]]
			dis := pair[1]
			// Determine the color of the adjacent node based on the distance
			if (distance+dis)%2 == 0 {
				adjNode.color = root.color
			} else {
				adjNode.color = !root.color
			}
			// Recursively traverse to the adjacent node
			traverse(adjNode, distance+dis)
		}
	}

	// Start the traversal from the root node with an initial distance of 0
	traverse(root, 0)

	// Output the color of each node
	for _, node := range nodes {
		if node.color {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
	}
}

// Helper function to read a line from the input
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

// Helper function to split a string by a delimiter
func split(s, delimiter string) []string {
	result := []string{}
	for len(s) > 0 {
		index := 0
		for i := 0; i < len(delimiter); i++ {
			if i+index < len(s) && s[i+index] == delimiter[i] {
				index++
			} else {
				break
			}
		}
		if index > 0 {
			result = append(result, s[:index])
			s = s[index:]
		} else {
			break
		}
	}
	return result
}
