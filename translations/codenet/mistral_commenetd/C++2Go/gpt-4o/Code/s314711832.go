package main

import (
	"fmt"
	"math"
)

const (
	INF = 1000000001
	N   = 100000
)

type Edge struct {
	source int
	target int
	weight int
}

var edges []Edge
var distances [N]int
var prevDistances [N]int

func main() {
	var V, E, r int // V: number of vertices, E: number of edges, r: source vertex

	// Read input
	fmt.Scan(&V, &E, &r)

	// Initialize edges slice
	for i := 0; i < E; i++ {
		var source, target, distance int
		fmt.Scan(&source, &target, &distance)
		newEdge := Edge{source, target, distance}
		edges = append(edges, newEdge)
	}

	// Initialize distances array with maximum value
	for i := 0; i < N; i++ {
		distances[i] = INF // max value
	}

	// Set initial distance of source vertex to 0
	distances[r] = 0

	// Bellman-Ford algorithm
	for i := 1; i < V; i++ {
		// Initialize previous distances array with current distances
		copy(prevDistances[:], distances[:])

		// Update distances for all vertices
		for _, edge := range edges {
			if distances[edge.source] != INF && distances[edge.source]+edge.weight < distances[edge.target] {
				distances[edge.target] = distances[edge.source] + edge.weight
			}
		}

		// Check if all distances have been updated
		same := true
		for j := 0; j < V; j++ {
			if distances[j] != prevDistances[j] {
				same = false
				break
			}
		}

		// If all distances have been updated, break the loop
		if same {
			break
		}
	}

	// Print results
	for i := 0; i < V; i++ {
		if distances[i] == INF {
			fmt.Println("INF")
		} else {
			fmt.Println(distances[i])
		}
	}
}

// <END-OF-CODE>
