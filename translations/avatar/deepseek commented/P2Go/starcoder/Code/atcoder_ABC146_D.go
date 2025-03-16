package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to perform Breadth-First Search (BFS) to color the graph
func bfs(v int, N int, G []deque, E map[int]int) int {
	// Initialize visited list to keep track of visited nodes
	visited := make([]int, N)
	// Initialize a queue for BFS using deque
	queue := make(deque, 0)
	// Initialize the maximum color index K
	K := -1
	// List to store the color of each node, initialized to -1 (no color)
	node2color := make([]int, N)
	// Start BFS from vertex v
	queue.append(v)
	visited[v] = 1
	for len(queue) > 0 {
		// Dequeue the front node
		q := queue[0]
		queue = queue[1:]
		// Initialize color for the current node
		color := 0
		// Iterate over all adjacent nodes
		for nex := range G[q] {
			if visited[nex] {
				continue
			}
			visited[nex] = 1
			color += 1
			// Ensure the color is different from the parent node's color
			if color == node2color[q] {
				color += 1
			}
			// Assign the color to the node and record the edge color
			node2color[nex] = color
			E[min(q, nex)*N+max(q, nex)] = color
			// Enqueue the adjacent node for further exploration
			queue.append(nex)
		}
		// Update the maximum color used
		K = max(K, color)
	}
	return K
}

// Main function to read input, construct the graph, and execute the BFS
func main() {
	// Read the number of nodes N
	N, _ := strconv.Atoi(readLine())
	// Initialize a list of deque objects to represent the graph
	G := make([]deque, N)
	// Initialize an empty dictionary to store edge colors
	E := make(map[int]int)
	// Read edges to populate the graph and edge dictionary
	for i := 0; i < N-1; i++ {
		a, b := readLineAsSliceInt()
		G[a-1].append(b - 1)
		G[b-1].append(a - 1)
		E[(a-1)*N+b-1] = 0
	}
	// Perform BFS to determine the maximum color and edge colors
	K := bfs(0, N, G, E)
	// Print the maximum color used
	fmt.Println(K)
	// Print the colors of all edges
	for _, value := range E {
		fmt.Println(value)
	}
}

// ReadLine reads a string line from stdin
func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return string(str)
}

// ReadLineAsSliceInt reads a string line from stdin and returns a slice of integers
func readLineAsSliceInt() []int {
	line := readLine()
	return StringToSliceInt(line)
}

// StringToSliceInt converts a string to a slice of integers
func StringToSliceInt(str string) []int {
	slice := make([]int, 0)
	for _, rune := range str {
		slice = append(slice, int(rune)-48)
	}
	return slice
}

// 