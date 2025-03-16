package main

import (
	"fmt"
)

const (
	INF = 1000000001 // Define a constant for infinity (a large value)
	N   = 100000     // Define a constant for the maximum number of vertices
)

// Structure to represent an edge in the graph
type Edge struct {
	source int // Source vertex of the edge
	target int // Target vertex of the edge
	weight int // Weight of the edge
}

var edges []Edge // Slice to store all edges of the graph

var distances [N]int         // Array to store the shortest distances from the source vertex
var prevDistances [N]int     // Array to store the previous distances for comparison

func main() {
	var V, E, r int // Variables for number of vertices, edges, and the source vertex

	// Read the number of vertices, edges, and the source vertex from input
	fmt.Scan(&V, &E, &r)

	// Read all edges from input and store them in the edges slice
	for i := 0; i < E; i++ {
		var source, target, distance int // Variables to hold edge data
		fmt.Scan(&source, &target, &distance) // Read edge data
		newEdge := Edge{source, target, distance} // Create a new edge
		edges = append(edges, newEdge) // Add the new edge to the edges slice
	}

	// Initialize distances array to infinity for all vertices
	for i := 0; i < N; i++ {
		distances[i] = INF // Set all distances to a maximum value (infinity)
	}

	distances[r] = 0 // Set the distance to the source vertex to 0

	// Main loop to relax edges V-1 times
	for i := 1; i < V; i++ {
		// Copy current distances to previous distances for comparison
		copy(prevDistances[:], distances[:])

		// Relax all edges
		for _, edge := range edges {
			// Update the distance to the target vertex if a shorter path is found
			if distances[edge.source]+edge.weight < distances[edge.target] {
				distances[edge.target] = distances[edge.source] + edge.weight
			}
		}

		// Check if any distance was updated in this iteration
		same := true // Flag to check if distances remain the same
		for j := 0; j < V; j++ {
			if distances[j] != prevDistances[j] {
				same = false // If any distance changed, set flag to false
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

// <END-OF-CODE>
