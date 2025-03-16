package main

import (
	"fmt"
)

func main() {
	var N, K int
	var A [200100]int
	var B [200100]int = [200100]int{-1} // Array to track visited nodes
	var now int = 1 // Starting node
	var cnt int = 0 // Counter for cycle detection

	fmt.Scan(&N, &K)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i+1]) // Read the sequence of nodes
	}

	// Detect cycle and find the position after K steps
	B[1] = 0 // Mark the starting node
	for j := 1; j <= K; j++ {
		now = A[now] // Move to the next node
		if B[now] == -1 {
			B[now] = j // Mark the node as visited
		} else {
			cnt = j // Record the cycle start
			break // Exit the loop as cycle is detected
		}
	}
	if j < K {
		tmp := (K - B[now]) % (cnt - B[now]) // Calculate remaining steps
		for j := 0; j < tmp; j++ {
			now = A[now] // Move to the position after K steps
		}
	}
	fmt.Println(now) // Output the final position
}
