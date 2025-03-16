
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

<<<<<<< HEAD
// Define constants
const (
	INF = 1000000001
)

// Define global variables
=======
// Global variables
>>>>>>> 98c87cb78a (data updated)
var (
	V int
	E int
	r int
	edges []edge
	distances []int
	prev_distances []int
)

<<<<<<< HEAD
// Define structs
=======
// Struct for edge
>>>>>>> 98c87cb78a (data updated)
type edge struct {
	source int
	target int
	weight int
}

<<<<<<< HEAD
// Define functions
func main() {
	// Read input
	fmt.Scanf("%d %d %d\n", &V, &E, &r)
=======
// Function to read input
func readInput() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read V, E and r
	fmt.Fscanf(reader, "%d %d %d\n", &V, &E, &r)
>>>>>>> 98c87cb78a (data updated)

	// Initialize edges vector
	for i := 0; i < E; i++ {
		var source, target, distance int
<<<<<<< HEAD
		fmt.Scanf("%d %d %d\n", &source, &target, &distance)
		new_edge := edge{source, target, distance}
		edges = append(edges, new_edge)
	}

	// Initialize distances array with maximum value
	for i := 0; i < N; i++ {
		distances[i] = INF
	}

	// Set initial distance of source vertex to 0
	distances[r] = 0

	// Bellman-Ford algorithm
	for i := 1; i < V; i++ {
		// Initialize previous distances array with current distances
		for j := 0; j < V; j++ {
			prev_distances[j] = distances[j]
		}

		// Update distances for all vertices
		for _, edge := range edges {
			distances[edge.target] = MIN(distances[edge.source]+edge.weight, distances[edge.target])
		}

		// Check if all distances have been updated
		same := true
		for j := 0; j < V; j++ {
			if distances[j]!= prev_distances[j] {
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
=======
		fmt.Fscanf(reader, "%d %d %d\n", &source, &target, &distance)
		new_edge := edge{source, target, distance}
		edges = append(edges, new_edge)
	}
}

// Function to initialize distances array with maximum value
func initDistances() {
	for i := 0; i < N; i++ {
		distances[i] = INF
	}
}

// Function to set initial distance of source vertex to 0
func setInitialDistance() {
	distances[r] = 0
}

// Function to update distances for all vertices
func updateDistances() {
	// Initialize previous distances array with current distances
	for i := 0; i < N; i++ {
		prev_distances[i] = distances[i]
	}

	// Update distances for all vertices
	for _, edge := range edges {
		distances[edge.target] = min(distances[edge.source]+edge.weight, distances[edge.target])
	}
}

// Function to check if all distances have been updated
func checkIfSame() bool {
	for i := 0; i < N; i++ {
		if distances[i]!= prev_distances[i] {
			return false
		}
	}
	return true
}

// Function to print results
func printResults() {
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i < V; i++ {
		if distances[i] == INF {
			fmt.Println("INF")
		} else {
			fmt.Println(distances[i])
		}
	}
}

<<<<<<< HEAD
// Define main function
func MIN(a, b int) int {
=======
// Function to find minimum of two integers
func min(a, b int) int {
>>>>>>> 98c87cb78a (data updated)
	if a < b {
		return a
	}
	return b
}

<<<<<<< HEAD
// Define main function
func MAX(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define main function
func ABS(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Define main function
func SGN(a int) int {
	if a < 0 {
		return -1
	}
	if a > 0 {
		return 1
	}
	return 0
}

// Define main function
func main() {

}

=======
// Main function
func main() {
	// Initialize global variables
	distances = make([]int, N)
	prev_distances = make([]int, N)

	// Read input
	readInput()

	// Initialize distances array with maximum value
	initDistances()

	// Set initial distance of source vertex to 0
	setInitialDistance()

	// Bellman-Ford algorithm
	for i := 1; i < V; i++ {
		// Update distances for all vertices
		updateDistances()

		// Check if all distances have been updated
		if checkIfSame() {
			break
		}
	}

	// Print results
	printResults()
}

// 
>>>>>>> 98c87cb78a (data updated)
