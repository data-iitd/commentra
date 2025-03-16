package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var N, K int64
	A := make([]int64, 200100)
	B := make([]int64, 200100)
	now := int64(1)
	cnt := int64(0)

	// Read input values
	fmt.Scan(&N, &K)

	// Read array A
	for i := int64(1); i <= N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize B array with -1
	for i := int64(0); i < 200100; i++ {
		B[i] = -1
	}

	// B[1] is always 0
	B[1] = 0

	// Simulation of the algorithm
	var j int64
	for j = 1; j <= K; j++ {
		// Move to the next node
		now = A[now]

		// If the node has not been reached yet, update B[now]
		if B[now] == -1 {
			B[now] = j
		} else {
			// If the node has already been reached, calculate the answer
			cnt = j
			break
		}
	}

	// If the simulation has not reached the end, calculate the answer
	if j < K {
		tmp := (K - B[now]) % (cnt - B[now])

		// Move to the final node
		for j := int64(0); j < tmp; j++ {
			now = A[now]
		}
	}

	// Print the answer
	fmt.Println(now)
}

// <END-OF-CODE>
