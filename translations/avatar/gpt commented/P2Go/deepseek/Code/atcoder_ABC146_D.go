package main

import (
	"bufio"
	"fmt"
	"os"
)

func bfs(v int, N int, G [][]int, E map[[2]int]int) int {
	// Initialize visited list to keep track of visited nodes
	visited := make([]bool, N)
	// Initialize a queue for BFS
	queue := []int{v}
	K := -1 // Variable to track the maximum color used
	// Initialize a map to store the color assigned to each node
	node2color := make(map[int]int)
	
	// Start BFS from the given vertex 'v'
	visited[v] = true // Mark the starting node as visited
	
	for len(queue) > 0 {
		// Dequeue the front node
		q := queue[0]
		queue = queue[1:]
		color := 0 // Initialize color counter for the current node
		
		// Explore all adjacent nodes
		for _, nex := range G[q] {
			if visited[nex] {
				continue // Skip if the node has already been visited
			}
			
			visited[nex] = true // Mark the adjacent node as visited
			color++ // Increment the color counter
			
			// Ensure the color assigned to the next node is different from the current node's color
			if color == node2color[q] {
				color++
			}
			
			// Assign the color to the adjacent node
			node2color[nex] = color
			
			// Store the color used for the edge between the current node and the adjacent node
			if q < nex {
				E[[2]int{q, nex}] = color
			} else {
				E[[2]int{nex, q}] = color
			}
			
			// Enqueue the adjacent node for further exploration
			queue = append(queue, nex)
		}
		
		// Update the maximum color used
		if color > K {
			K = color
		}
	}
	
	return K // Return the maximum color used
}

func main() {
	// Use fast input method
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N := parseInt(scanner.Text())
	
	// Initialize the graph as a slice of slices
	G := make([][]int, N)
	// Initialize a map to store edge colors
	E := make(map[[2]int]int)
	
	// Read edges and build the graph
	for i := 0; i < N-1; i++ {
		scanner.Scan()
		a, b := parseInt(scanner.Text())
		a--
		b--
		G[a] = append(G[a], b) // Add edge from a to b
		G[b] = append(G[b], a) // Add edge from b to a
		E[[2]int{a, b}] = 0 // Initialize edge color to 0
	}
	
	// Perform BFS starting from node 0
	K := bfs(0, N, G, E)
	
	// Print the maximum color used
	fmt.Println(K)
	// Print the colors assigned to each edge
	for _, value := range E {
		fmt.Println(value)
	}
}

func parseInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
}

