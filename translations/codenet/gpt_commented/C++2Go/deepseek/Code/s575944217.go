package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of vertices (or nodes)
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)

	// Initialize a slice to store the count of edges for each vertex
	ans := make([]int, n)

	// Read n-1 edges and count the occurrences for each vertex
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		var a int
		fmt.Sscan(scanner.Text(), &a)
		a-- // Convert to 0-based index
		ans[a]++ // Increment the count for the corresponding vertex
	}

	// Output the count of edges for each vertex
	for i := 0; i < n; i++ {
		fmt.Println(ans[i]) // Print the count for vertex i
	}
}

