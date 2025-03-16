package main

import (
	"fmt"
)

func main() {
	// Read the number of elements in the array P from the standard input
	var N int
	fmt.Scan(&N)

	// Initialize an integer slice P of size N
	P := make([]int, N)

	// Read each element of P from the standard input and store it in the corresponding index of the slice
	for i := 0; i < N; i++ {
		var temp int
		fmt.Scan(&temp)
		P[i] = temp - 1
	}

	// Create a map to store the indices of the array P corresponding to each unique element
	mapIndices := make(map[int]int)

	// Iterate through each element of the array P and add its index to the map
	for i := 0; i < N; i++ {
		mapIndices[P[i]] = i
	}

	// Create a slice to store the indices of the non-decreasing subsequences
	var nglist []int

	// Iterate through each index i of the array P, where i < N - 1
	for i := 0; i < N-1; i++ {
		// If the index i corresponds to a smaller element than the next index, add its index to the slice
		if mapIndices[i] > mapIndices[i+1] {
			nglist = append(nglist, i)
		}
	}

	// If there are no non-decreasing subsequences, print 0 and exit the program
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}

	// Calculate the answer by finding the minimum length of a non-decreasing subsequence
	ans := min(N-nglist[0]-1, nglist[len(nglist)-1]+1)

	// Iterate through each pair of consecutive indices in the slice nglist and update the answer if necessary
	for i := 0; i < len(nglist)-1; i++ {
		ans = min(nglist[i]+1+N-nglist[i+1]-1, ans)
	}

	// Print the answer
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
