package main

import (
	"fmt"
)

func main() {
	var N, K int
	var A [200100]int
	var B [200100]int = [200100]int{-1}
	var now int = 1
	var cnt int = 0

	// Read input values
	fmt.Scan(&N, &K)

	// Read array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i+1])
	}

	// B[1] is always 0
	B[1] = 0

	// Simulation of the algorithm
	var j int
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
		for j := 0; j < tmp; j++ {
			now = A[now]
		}
	}

	// Print the answer
	fmt.Println(now)
}

