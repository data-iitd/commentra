package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize a slice of integers with N elements, all set to 0
	a := make([]int, N)

	// Read M groups of integers, where each group represents a switch and its corresponding states
	for i := 0; i < M; i++ {
		var k int
		fmt.Scan(&k)
		for j := 0; j < k; j++ {
			var s int
			fmt.Scan(&s)
			s-- // Convert to zero-based index
			a[s] |= (1 << i) // Set the i-th bit for switch s
		}
	}

	// Read the final state of each light
	var p int
	for i := 0; i < M; i++ {
		var x int
		fmt.Scan(&x)
		p |= (x << i) // Set the i-th bit for the final state
	}

	// Calculate the number of possible configurations of switch states that match the final state of the lights
	ans := 0
	for s := 0; s < (1 << N); s++ {
		var t int
		for i := 0; i < N; i++ {
			if (s>>i)&1 == 1 { // Check if the i-th bit is set
				t ^= a[i] // XOR with the corresponding switch state
			}
		}
		if p == t { // Check if the final state matches
			ans++
		}
	}

	// Print the result
	fmt.Println(ans)
}
