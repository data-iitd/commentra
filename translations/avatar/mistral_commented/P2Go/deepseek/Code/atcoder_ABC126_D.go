package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a Node struct
type Node struct {
	val       int
	color     bool
	adjacencies [][2]int
}

// Read input and initialize nodes
func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	nodes := make([]Node, n)

	// Initialize nodes
	for i := 0; i < n; i++ {
		nodes[i] = Node{val: i + 1, color: true}
	}

	// Read edges and add adjacencies to nodes
	for i := 0; i < n - 1; i++ {
		line := readLine(reader)
		parts := split(line, " ")
		u, _ := strconv.Atoi(parts[0])
		v, _ := strconv.Atoi(parts[1])
		w, _ := strconv.Atoi(parts[2])
		nodes[u - 1].adjacencies = append(nodes[u - 1].adjacencies, [2]int{v - 1, w})
		nodes[v - 1].adjacencies = append(nodes[v - 1].adjacencies, [2]int{u - 1, w})
	}

	// Set the root node and color it
	root := &nodes[0]
	root.color = true

	// Traverse the graph and color nodes based on their distance from the root
	var traverse func(node *Node, distance int)
	visited := make(map[*Node]bool)
	traverse = func(node *Node, distance int) {
		if visited[node] {
			return
		}
		visited[node] = true
		for _, adj := range node.adjacencies {
			adjNode := &nodes[adj[0]]
			adjDistance := adj[1]
			if (distance + adjDistance) % 2 == 0 {
				adjNode.color = root.color
			} else {
				adjNode.color = !root.color
			}
			traverse(adjNode, distance + adjDistance)
		}
	}

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

// Helper function to read a line from the reader
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line) - 1]
}

// Helper function to split a string by a delimiter
func split(s, delimiter string) []string {
	result := []string{}
	for len(s) > 0 {
		index := 0
		for i := 0; i < len(delimiter); i++ {
			if s[i] == delimiter[i] {
				index++
			} else {
				break
			}
		}
		if index > 0 {
			result = append(result, s[:index])
			s = s[index:]
		} else {
			result = append(result, s[:1])
			s = s[1:]
		}
	}
	return result
}

