package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for infinity (a large value)
const INF = 1000000001

// Define a constant for the maximum number of vertices
const N = 100000

// Structure to represent an edge in the graph
type edge struct {
	source int
	target int
	weight int
}

// Global variables to store all edges of the graph
var edges []edge

// Global variables to store the shortest distances from the source vertex
var distances [N]int
var prev_distances [N]int

func main() {
	// Read the number of vertices, edges, and the source vertex from input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &V, &E, &r)

	// Read all edges from input and store them in the edges vector
	for i := 0; i < E; i++ {
		var source, target, distance int
		fmt.Fscan(reader, &source, &target, &distance)
		new_edge := edge{source, target, distance}
		edges = append(edges, new_edge)
	}

	// Initialize distances array to infinity for all vertices
	for i := 0; i < N; i++ {
		distances[i] = INF
	}

	distances[r] = 0

	// Main loop to relax edges V-1 times
	for i := 1; i < V; i++ {
		// Copy current distances to previous distances for comparison
		for j := 0; j < V; j++ {
			prev_distances[j] = distances[j]
		}

		// Relax all edges
		for _, edge := range edges {
			// Update the distance to the target vertex if a shorter path is found
			distances[edge.target] = min(distances[edge.source]+edge.weight, distances[edge.target])
		}

		// Check if any distance was updated in this iteration
		same := true
		for j := 0; j < V; j++ {
			if distances[j]!= prev_distances[j] {
				same = false
				break
			}
		}

		// If no distances were updated, break out of the loop early
		if same {
			break
		}
	}

	// Output the shortest distances from the source vertex to all other vertices
	for i := 0; i < V; i++ {
		if distances[i] == INF {
			fmt.Println("INF") // Print "INF" if the vertex is unreachable
		} else {
			fmt.Println(distances[i]) // Print the shortest distance
		}
	}
}

// Function to find the minimum of two values
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 