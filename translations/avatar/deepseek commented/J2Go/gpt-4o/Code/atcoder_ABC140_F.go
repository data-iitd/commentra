package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the integer N from standard input
	size := 1 << N // Calculate the size of the array S, which is 2^N
	S := make([]int, size) // Initialize an array S to store integers
	spawned := make([]bool, size) // Initialize a boolean array to track spawned elements
	spawned[size-1] = true // Set the last element of spawned to true, indicating it's initially active

	// Read integers into the array S
	for i := 0; i < size; i++ {
		fmt.Scan(&S[i])
	}

	sort.Ints(S) // Sort the array S
	active := []int{S[size-1]} // Initialize a slice to keep track of active elements
	spawned[size-1] = true

	// Iterate N times
	for i := 0; i < N; i++ {
		sort.Sort(sort.Reverse(sort.IntSlice(active))) // Sort the active slice in reverse order
		activated := []int{} // Initialize a slice to find new activated elements
		next := size - 1 // Initialize next to find new activated elements

		// Find new activated elements
		for _, slime := range active {
			for next >= 0 && (S[next] >= slime || spawned[next]) {
				next--
			}
			if next < 0 {
				fmt.Println("No") // If no new activated elements are found, print "No"
				return
			}
			spawned[next] = true // Mark the found element as spawned
			activated = append(activated, S[next]) // Add the found element to the activated slice
		}
		active = append(active, activated...) // Add the activated elements to the active slice
	}
	fmt.Println("Yes") // If N iterations are successful, print "Yes"
}

// <END-OF-CODE>
