package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	// Read the values of n and m from standard input

	b := make([]int, 2*n)
	for i := range b {
		b[i] = 1
	}
	// Initialize a slice `b` with 1s, size is 2*n

	b[0] = 0
	b[n-1] = 0
	b[n] = 0
	b[2*n-1] = 0
	// Set specific positions in `b` to 0

	for i := 0; i < m; i++ {
		var r, c int
		fmt.Scan(&r, &c)
		// Read each pair of row and column indices
		b[r-1] = 0
		b[n+c-1] = 0
		// Update `b` based on the input pairs
	}

	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}
	// Check if `n` is odd and specific positions in `b` are 1, then set them to 0

	sum := 0
	for _, value := range b {
		sum += value
	}
	fmt.Println(sum)
	// Print the sum of the slice `b`
}

// <END-OF-CODE>
