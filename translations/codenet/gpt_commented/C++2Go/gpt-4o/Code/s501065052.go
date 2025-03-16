package main

import (
	"fmt"
)

func main() {
	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Create a slice to store the positions of elements
	mem := make([]int, N+1)

	// Populate the 'mem' slice with the positions of each element
	for i := 1; i <= N; i++ {
		var P int
		fmt.Scan(&P) // Read the element
		mem[P] = i   // Store the position of the element in 'mem'
	}

	// Initialize counters for the longest increasing subsequence
	maxcnt := 1 // Maximum count of increasing sequence found
	cnt := 1    // Current count of increasing sequence

	// Iterate through the 'mem' slice to find the longest increasing subsequence
	for i := 1; i < N; i++ {
		// Check if the current position is less than the next position
		if mem[i] < mem[i+1] {
			cnt++ // Increment the current count if increasing
		} else {
			// Update the maximum count if the current count is greater
			if cnt > maxcnt {
				maxcnt = cnt
			}
			cnt = 1 // Reset current count
		}
		// Check at the last element to update max count
		if i == N-1 {
			if cnt > maxcnt {
				maxcnt = cnt
			}
		}
	}

	// Output the minimum number of elements to remove to get the longest increasing subsequence
	fmt.Println(N - maxcnt)
}

// <END-OF-CODE>
