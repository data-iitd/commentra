package main

import (
	"fmt"
)

func main() {
	var n, m int
	// Take input as two integers n and m from the user
	fmt.Scan(&n, &m)

	// Initialize a slice 'b' of length 2 * n with all elements as 1
	b := make([]int, n*2)
	for i := range b {
		b[i] = 1
	}

	// Set the first, last and middle elements of the slice 'b' to 0
	b[0] = 0
	b[n-1] = 0
	b[n] = 0
	b[2*n-1] = 0

	// Iterate through the given 'm' pairs of row and column indices
	for i := 0; i < m; i++ {
		var r, c int
		// Take row and column indices as input
		fmt.Scan(&r, &c)

		// Set the elements at the given row and column indices to 0 in the slice 'b'
		b[r-1] = 0
		b[n+c-1] = 0
	}

	// Check if n is odd and if the middle two elements of the slice 'b' are 1, then set the middle element to 0
	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}

	// Calculate and print the sum of all elements in the slice 'b'
	sum := 0
	for _, value := range b {
		sum += value
	}
	fmt.Println(sum)
}

// <END-OF-CODE>
