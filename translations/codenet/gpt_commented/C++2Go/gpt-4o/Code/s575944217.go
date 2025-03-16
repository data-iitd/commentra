package main

import (
	"fmt"
)

func main() {
	// Read the number of vertices (or nodes)
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the count of edges for each vertex
	ans := make([]int, n)

	// Read n-1 edges and count the occurrences for each vertex
	for i := 0; i < n-1; i++ {
		var a int
		fmt.Scan(&a) // Read the vertex index
		a--          // Convert to 0-based index
		ans[a]++     // Increment the count for the corresponding vertex
	}

	// Output the count of edges for each vertex
	for i := 0; i < n; i++ {
		fmt.Println(ans[i]) // Print the count for vertex i
	}
}

// <END-OF-CODE>
