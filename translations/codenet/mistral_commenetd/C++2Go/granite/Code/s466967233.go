
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize variables
	N, K := 0, 0
	A := make([]int, 200100)
	B := make([]int, 200100)
	now, cnt := 1, 0

	// Read input values
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &N, &K)
	for i := 1; i <= N; i++ {
		fmt.Fscanf(reader, "%d\n", &A[i])
	}

	// Initialize B array with -1
	for i := 0; i < 200100; i++ {
		B[i] = -1
	}

	// B[1] is always 0
	B[1] = 0

	// Simulation of the algorithm
	j := 1
	for j <= K {
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
		for j = 0; j < tmp; j++ {
			now = A[now]
		}
	}

	// Print the answer
	fmt.Println(now)
}

