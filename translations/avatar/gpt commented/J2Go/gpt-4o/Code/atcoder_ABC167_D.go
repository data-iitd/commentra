package main

import (
	"fmt"
)

func main() {
	// Initialize scanner for input
	var N int
	var K int64
	fmt.Scan(&N, &K)

	// Initialize the array A to store the input values
	A := make([]int, N)

	// Read N integers into the array A and adjust values to be zero-indexed
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		A[i]-- // Adjust to zero-indexed
	}

	// Set to track used indices and slices to store index and position
	used := make(map[int]struct{})
	idx := make([]int, N)
	pos := make([]int, N)

	// Initialize variables for the cycle detection
	next := 0
	cur := 0

	// Detect the cycle in the array using the 'used' map
	for _, exists := used[next]; !exists; {
		used[next] = struct{}{}
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	// Calculate the lengths of the cycle and the position of the next element
	a := int64(cur - idx[next])
	b := int64(idx[next])

	// Calculate the answer based on the cycle length and K
	ans := (10000*a + K - b) % a + b

	// If b is greater than K, set ans to K
	if b > K {
		ans = K
	}

	// Output the result, adjusting for 1-based indexing
	fmt.Println(pos[ans] + 1)
}

// <END-OF-CODE>
