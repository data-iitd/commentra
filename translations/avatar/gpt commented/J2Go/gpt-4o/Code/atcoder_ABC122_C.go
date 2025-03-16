package main

import (
	"fmt"
)

const mod = 1000000007

func main() {
	var n, q int
	fmt.Scan(&n, &q)

	// Read the character array from input
	c := make([]rune, n)
	for i := 0; i < n; i++ {
		var ch rune
		fmt.Scanf("%c", &ch)
		c[i] = ch
	}

	// Initialize a 2D slice to store the ranges for each query
	rangeQueries := make([][2]int, q)

	// Read the ranges for each query
	for i := 0; i < q; i++ {
		fmt.Scan(&rangeQueries[i][0], &rangeQueries[i][1])
	}

	// Initialize slices to track fragments and cumulative sums
	frag := make([]int, n+1) // To count occurrences of "AC"
	rui := make([]int, n+1)  // To store cumulative sums of fragments

	// Loop through the character array to count occurrences of "AC"
	for i := 2; i <= n; i++ {
		// Check if the current and previous characters form "AC"
		if c[i-2] == 'A' && c[i-1] == 'C' {
			frag[i]++ // Increment the fragment count
		}
		// Update the cumulative sum of fragments
		rui[i] = rui[i-1] + frag[i]
	}

	// Process each query to find the number of "AC" in the specified range
	for i := 0; i < q; i++ {
		left := rangeQueries[i][0]   // Get the left index of the query
		right := rangeQueries[i][1]  // Get the right index of the query

		// Calculate and print the result for the current query
		fmt.Println(rui[right] - rui[left])
	}
}

// <END-OF-CODE>
