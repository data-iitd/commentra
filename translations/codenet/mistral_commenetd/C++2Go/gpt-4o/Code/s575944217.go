package main

import (
	"fmt"
)

func main() {
	// Read the number of vertices from the input
	var n int
	fmt.Scan(&n)

	// Initialize an answer slice of size n
	ans := make([]int, n)

	// Read the edges and increment the count of each vertex in the answer slice
	for i := 0; i < n-1; i++ {
		var a int
		fmt.Scan(&a)
		a-- // Decrement the vertex index as it is 0-indexed
		ans[a]++ // Increment the count of the vertex
	}

	// Print the answer slice
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

// <END-OF-CODE>
