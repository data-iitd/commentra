package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var N, M int
	fmt.Scan(&N, &M)

	// Constants and initializations
	Inf := 1 << 62
	// a, b, and c are arrays of size M
	a := make([]int, M)
	b := make([]int, M)
	c := make([]int, M)

	// Read input values for a, b, and c
	for i := 0; i < M; i++ {
		fmt.Scan(&a[i], &b[i], &c[i])
		// Set c to its negation
		c[i] = -c[i]
	}

	// Initialize the dist array with the maximum value
	dist := make([]int, N)
	for i := 0; i < N; i++ {
		dist[i] = Inf
	}
	// Set the initial distance of the source node to 0
	dist[0] = 0

	// Dijkstra's algorithm loop
	for loop := 0; loop < N; loop++ {
		for i := 0; i < M; i++ {
			// Skip if the current node's distance is still the maximum value
			if dist[a[i]-1] == Inf {
				continue
			}
			// Update the distance if the new path is shorter
			if dist[b[i]-1] > dist[a[i]-1] + c[i] {
				dist[b[i]-1] = dist[a[i]-1] + c[i]
			}
		}
	}

	// Calculate the answer
	ans := dist[N-1]
	navigate := make([]bool, N)

	// Dijkstra's algorithm loop (second pass)
	for loop := 0; loop < N; loop++ {
		for i := 0; i < M; i++ {
			// Skip if the current node's distance is still the maximum value
			if dist[a[i]-1] == Inf {
				continue
			}
			// Update the distance if the new path is shorter
			if dist[b[i]-1] > dist[a[i]-1] + c[i] {
				dist[b[i]-1] = dist[a[i]-1] + c[i]
				navigate[b[i]-1] = true
			}
			// If the previous node is in the navigate array, set the current node's navigate array value to true
			if navigate[a[i]-1] == true {
				navigate[b[i]-1] = true
			}
		}
	}

	// Print the result
	if navigate[N-1] {
		fmt.Println("inf")
	} else {
		fmt.Println(-ans)
	}

	// End of the code
}	