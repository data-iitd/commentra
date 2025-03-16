package main

import (
	"fmt"
)

const mod = 1000000007

func main() {
	var n, q int
	fmt.Scan(&n, &q)

	// Read the string
	var c string
	fmt.Scan(&c)

	// Read the ranges for the queries
	rangeQueries := make([][2]int, q)
	for i := 0; i < q; i++ {
		fmt.Scan(&rangeQueries[i][0], &rangeQueries[i][1])
	}

	// Initialize arrays to count "AC" fragments and store cumulative sums
	frag := make([]int, n+1)
	rui := make([]int, n+1)

	// Process the string to find "AC" fragments
	for i := 2; i <= n; i++ {
		if c[i-2] == 'A' && c[i-1] == 'C' {
			frag[i]++
		}
		// Update the cumulative sum array
		rui[i] = rui[i-1] + frag[i]
	}

	// Process the queries
	for i := 0; i < q; i++ {
		left := rangeQueries[i][0]
		right := rangeQueries[i][1]
		// Calculate the number of "AC" fragments in the given range
		fmt.Println(rui[right] - rui[left])
	}
}

// <END-OF-CODE>
