
package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strconv"
)

// Function to perform Breadth-First Search (BFS) to color the graph
func bfs(v int, N int, G []*list.List, E map[string]int) int {
	// Initialize visited list to keep track of visited nodes
	visited := make([]bool, N)
	// Initialize a queue for BFS using list
	queue := list.New()
	// Initialize the maximum color index K
	K := -1
	// List to store the color of each node, initialized to -1 (no color)
	node2color := make([]int, N)
	// Start BFS from vertex v
	queue.PushBack(v)
	visited[v] = true
	for queue.Len() > 0 {
		// Dequeue the front node
		q := queue.Front()
		queue.Remove(q)
		// Initialize color for the current node
		color := 0
		// Iterate over all adjacent nodes
		for e := G[q.Value.(int)].Front(); e!= nil; e = e.Next() {
			nex := e.Value.(int)
			if visited[nex] {
				continue
			}
			visited[nex] = true
			color += 1
			// Ensure the color is different from the parent node's color
			if color == node2color[q.Value.(int)] {
				color += 1
			}
			// Assign the color to the node and record the edge color
			node2color[nex] = color
			E[fmt.Sprintf("%d %d", q.Value.(int), nex)] = color
			// Enqueue the adjacent node for further exploration
			queue.PushBack(nex)
		}
		// Update the maximum color used
		K = max(K, color)
	}
	return K
}

// Main function to read input, construct the graph, and execute the BFS
func main() {
	// Initialize a list of list objects to represent the graph
	G := make([]*list.List, 0)
	// Initialize an empty dictionary to store edge colors
	E := make(map[string]int)
	// Read the number of nodes N
	N, _ := strconv.Atoi(read())
	// Populate the graph and edge dictionary
	for i := 0; i < N; i++ {
		G = append(G, list.New())
	}
	for i := 0; i < N-1; i++ {
		a, _ := strconv.Atoi(read())
		b, _ := strconv.Atoi(read())
		G[a-1].PushBack(b - 1)
		G[b-1].PushBack(a - 1)
		E[fmt.Sprintf("%d %d", a-1, b-1)] = 0
	}
	// Perform BFS to determine the maximum color and edge colors
	K := bfs(0, N, G, E)
	// Print the maximum color used
	fmt.Println(K)
	// Print the colors of all edges
	for key, value := range E {
		fmt.Println(value)
	}
}

// Function to read input from the standard input
func read() string {
	buf := make([]byte, 0)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		buf = append(buf, scanner.Bytes()...)
	}
	return string(buf)
}

// Function to find the maximum of two integers
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// Execute the main function
func main() {
	main()
}

