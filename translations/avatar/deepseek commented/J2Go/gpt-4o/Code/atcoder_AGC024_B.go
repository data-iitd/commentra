package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements in the array P
	P := make([]int, N) // Initialize the array P with N elements
	for i := 0; i < N; i++ {
		fmt.Scan(&P[i]) // Read each element
		P[i]-- // Adjust to 0-based index
	}

	// Create a map to map each value in P to its index
	mapIndex := make(map[int]int)
	for i := 0; i < N; i++ {
		mapIndex[P[i]] = i
	}

	// Create a slice to store indices of elements that are out of order
	var nglist []int
	for i := 0; i < N-1; i++ {
		if mapIndex[i] > mapIndex[i+1] {
			nglist = append(nglist, i) // Add the index to nglist if the current element is greater than the next element
		}
	}

	// If nglist is empty, the array P is already sorted
	if len(nglist) == 0 {
		fmt.Println(0) // Print 0 and return as the array is sorted
		return
	}

	// Calculate the minimum number of swaps required to sort the array P
	ans := min(N-nglist[0]-1, nglist[len(nglist)-1]+1)
	for i := 0; i < len(nglist)-1; i++ {
		ans = min(nglist[i]+1+N-nglist[i+1]-1, ans)
	}

	// Print the minimum number of swaps required
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
