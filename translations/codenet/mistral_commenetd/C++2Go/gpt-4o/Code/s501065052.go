package main

import (
	"fmt"
)

func main() {
	var N int // Read the number of elements in the memory array from the standard input
	fmt.Scan(&N)

	mem := make([]int, N+1) // Allocate memory for an integer slice of size N+1 to store the memory locations of each process

	for i := 1; i <= N; i++ { // Read the memory locations of each process and store them in the mem slice
		var P int
		fmt.Scan(&P)
		mem[P] = i
	}

	maxcnt := 1 // Initialize maxcnt to 1, which will store the maximum length of a consecutive increasing sequence of memory locations
	cnt := 1    // Initialize cnt to 1, which will store the current length of such a sequence

	for i := 1; i < N; i++ { // Traverse the mem slice and update maxcnt and cnt variables accordingly
		if mem[i] < mem[i+1] {
			cnt++
		} else {
			if cnt > maxcnt {
				maxcnt = cnt
			}
			cnt = 1
		}
	}

	// Update maxcnt with the length of the last consecutive increasing sequence
	if cnt > maxcnt {
		maxcnt = cnt
	}

	fmt.Println(N - maxcnt) // Print the result N - maxcnt to the standard output
}

// <END-OF-CODE>
