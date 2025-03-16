package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements or nodes
	ans := make([]int, n) // Initialize a slice to store the count of incoming edges for each node

	for i := 0; i < n-1; i++ { // Loop to read edges and populate the slice
		var a int
		fmt.Scan(&a) // Read an integer
		a-- // Decrement by 1 to convert to 0-based indexing
		ans[a]++ // Increment the count of incoming edges for the node
	}

	for i := 0; i < n; i++ { // Loop to output the results
		fmt.Println(ans[i]) // Print the number of incoming edges for each node
	}
}

// <END-OF-CODE>
