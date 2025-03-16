package main

import (
	"fmt"
)

func main() {
	var N, K int64
	A := make([]int64, 200100)
	B := make([]int64, 200100) // Array to track visited nodes
	for i := range B {
		B[i] = -1 // Initialize all nodes as unvisited
	}
	now := int64(1) // Starting node
	cnt := int64(0) // Counter for cycle detection

	fmt.Scan(&N, &K)
	for i := int64(1); i <= N; i++ {
		fmt.Scan(&A[i]) // Read the sequence of nodes
	}

	B[1] = 0 // Mark the starting node
	var j int64
	for j = 1; j <= K; j++ {
		now = A[now] // Move to the next node
		if B[now] == -1 {
			B[now] = j // Mark the node as visited
		} else {
			cnt = j // Record the cycle start
			break    // Exit the loop as cycle is detected
		}
	}

	if j < K {
		tmp := (K - B[now]) % (cnt - B[now]) // Calculate remaining steps
		for j = 0; j < tmp; j++ {
			now = A[now] // Move to the position after K steps
		}
	}
	fmt.Println(now) // Output the final position
}

// <END-OF-CODE>
