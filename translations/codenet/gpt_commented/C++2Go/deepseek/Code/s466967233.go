package main

import (
	"fmt"
)

func main() {
	var N, K int
	var A [200100]int
	var B [200100]int = [-1]int{-1}
	var now int = 1
	var cnt int = 0

	// Read the number of elements (N) and the number of steps (K)
	fmt.Scan(&N, &K)

	// Read the elements into array A
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize array B to -1 to indicate unvisited positions
	for i := 0; i < 200100; i++ {
		B[i] = -1
	}

	// Mark the starting position as visited at step 0
	B[1] = 0

	// Traverse the positions based on the values in A
	for j := 1; j <= K; j++ {
		now = A[now]

		// Check if the current position has been visited before
		if B[now] == -1 {
			B[now] = j
		} else {
			// If the position has been visited, calculate the cycle length
			cnt = j
			break
		}
	}

	// If we did not reach the maximum steps K
	if j < K {
		tmp := (K - B[now]) % (cnt - B[now])

		// Move to the final position after the calculated additional steps
		for j := 0; j < tmp; j++ {
			now = A[now]
		}
	}

	// Output the final position after all movements
	fmt.Println(now)
}

