
package main

import (
	"fmt"
	"math"
)

// Define a struct to represent an edge
type edge struct {
	source, target, weight int
}

// Define a slice to store all edges
var edges []edge

// Define a slice to store all distances
var distances []int

// Define a slice to store previous distances
var prevDistances []int

// Define a constant for infinity
const INF = math.MaxInt32

// Define a constant for the number of vertices
const N = 100000

// Define a function to initialize the distances slice
func initDistances() {
	distances = make([]int, N)
	for i := 0; i < N; i++ {
		distances[i] = INF
	}
}

// Define a function to initialize the previous distances slice
func initPrevDistances() {
	prevDistances = make([]int, N)
	for i := 0; i < N; i++ {
		prevDistances[i] = 0
	}
}

// Define a function to update the distances slice
func updateDistances() {
	for i := 0; i < len(edges); i++ {
		distances[edges[i].target] = min(distances[edges[i].source]+edges[i].weight, distances[edges[i].target])
	}
}

// Define a function to check if all distances have been updated
func checkDistances() bool {
	for i := 0; i < len(distances); i++ {
		if distances[i] != prevDistances[i] {
			return false
		}
	}
	return true
}

// Define a function to print the results
func printResults() {
	for i := 0; i < len(distances); i++ {
		if distances[i] == INF {
			fmt.Println("INF")
		} else {
			fmt.Println(distances[i])
		}
	}
}

// Define a function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Define a function to read input
func readInput() {
	var V, E, r int
	fmt.Scan(&V, &E, &r)

	// Initialize edges slice
	for i := 0; i < E; i++ {
		var source, target, distance int
		fmt.Scan(&source, &target, &distance)
		edges = append(edges, edge{source, target, distance})
	}

	// Initialize distances slice
	initDistances()

	// Initialize previous distances slice
	initPrevDistances()

	// Set initial distance of source vertex to 0
	distances[r] = 0
}

// Define a function to run the Bellman-Ford algorithm
func bellmanFord() {
	for i := 1; i < V; i++ {
		// Initialize previous distances slice with current distances
		for j := 0; j < V; j++ {
			prevDistances[j] = distances[j]
		}

		// Update distances for all vertices
		updateDistances()

		// Check if all distances have been updated
		if checkDistances() {
			break
		}
	}
}

// Define a function to run the program
func main() {
	// Read input
	readInput()

	// Run the Bellman-Ford algorithm
	bellmanFord()

	// Print results
	printResults()
}

