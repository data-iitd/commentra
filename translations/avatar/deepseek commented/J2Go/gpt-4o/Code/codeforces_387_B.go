package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n) // Read the number of elements n
	fmt.Scan(&m) // Read the number of elements m

	req := make([]int, n) // Initialize slice req
	pre := make([]int, m) // Initialize slice pre

	// Read elements into req
	for i := 0; i < n; i++ {
		fmt.Scan(&req[i])
	}

	// Read elements into pre
	for i := 0; i < m; i++ {
		fmt.Scan(&pre[i])
	}

	i, j := n-1, m-1 // Initialize indices i and j
	ans := 0         // Initialize ans to store the result

	// Implement the logic to find the number of elements in req that are greater than the corresponding elements in pre
	for i >= 0 && j >= 0 {
		if req[i] > pre[j] { // If the element in req is greater than the element in pre
			ans++ // Increment ans
		} else {
			j-- // Decrement j to check the next element in pre
		}
		i-- // Decrement i in each iteration
	}

	// Print the result which is the sum of ans and the remaining elements in req
	fmt.Print(ans + i + 1)
}

// <END-OF-CODE>
