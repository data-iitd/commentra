package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	P := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&P[i])
		P[i]-- // Store input values after decrementing by 1
	}

	// Create a map to store the index of each element for quick lookup
	mapIndex := make(map[int]int)
	for i := 0; i < N; i++ {
		mapIndex[P[i]] = i // Map each value to its index
	}

	// Slice to store indices where the order is not increasing
	var nglist []int
	for i := 0; i < N-1; i++ {
		// Check if the current index is greater than the next index in the map
		if mapIndex[i] > mapIndex[i+1] {
			nglist = append(nglist, i) // Add the index to the nglist if the order is violated
		}
	}

	// If there are no indices in nglist, print 0 and exit
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}

	// Calculate the minimum number of moves required to fix the order
	ans := min(N-nglist[0]-1, nglist[len(nglist)-1]+1)
	for i := 0; i < len(nglist)-1; i++ {
		// Update ans with the minimum moves needed between consecutive indices in nglist
		ans = min(nglist[i]+1+N-nglist[i+1]-1, ans)
	}

	// Print the result which is the minimum number of moves
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
