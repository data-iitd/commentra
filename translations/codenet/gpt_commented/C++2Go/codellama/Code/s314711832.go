package main

import (
	"fmt"
	"math"
)

// Structure to represent an edge in the graph
type edge struct {
	source, target, weight int
}

var edges []edge // Vector to store all edges of the graph

var distances [100000]int // Array to store the shortest distances from the source vertex
var prevDistances [100000]int = [100000]int{0} // Array to store the previous distances for comparison

func main() {
	var V, E, r int // Variables for number of vertices, edges, and the source vertex

	// Read the number of vertices, edges, and the source vertex from input
	fmt.Scan(&V, &E, &r)

	// Read all edges from input and store them in the edges vector
	for i := 0; i < E; i++ {
		var source, target, distance int // Variables to hold edge data
		fmt.Scan(&source, &target, &distance) // Read edge data
		edges = append(edges, edge{source, target, distance}) // Add the new edge to the edges vector
	}

	// Initialize distances array to infinity for all vertices
	for i := 0; i < 100000; i++ {
		distances[i] = math.MaxInt32 // Set all distances to a maximum value (infinity)
	}

	distances[r] = 0 // Set the distance to the source vertex to 0

	// Main loop to relax edges V-1 times
	for i := 1; i < V; i++ {
		// Copy current distances to previous distances for comparison
		for j := 0; j < 100000; j++ {
			prevDistances[j] = distances[j]
		}

		// Relax all edges
		for _, edge := range edges {
			// Update the distance to the target vertex if a shorter path is found
			distances[edge.target] = int(math.Min(float64(distances[edge.source]+edge.weight), float64(distances[edge.target])))
		}

		// Check if any distance was updated in this iteration
		same := true // Flag to check if distances remain the same
		for j := 0; j < 100000; j++ {
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
	for i := 0; i < 100000; i++ {
		if distances[i] == math.MaxInt32 {
			fmt.Println("INF") // Print "INF" if the vertex is unreachable
		} else {
			fmt.Println(distances[i]) // Print the shortest distance
		}
	}
}

