package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements from user input

	A := make([][2]int, N) // Create a slice of tuples (index, value)

	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x) // Read each element from user input
		A[i] = [2]int{i + 1, x} // Store the index (1-based) and value
	}

	// Sort the slice based on the second item (the value) in each tuple
	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	// Extract the first item (the original index) from each sorted tuple into a new slice
	A__ := make([]int, N)
	for i := 0; i < N; i++ {
		A__[i] = A[i][0]
	}

	// Print the indices of the sorted values, separated by spaces
	for i := 0; i < N-1; i++ { // Loop through all but the last index
		fmt.Print(A__[i], " ") // Print each index followed by a space
	}
	fmt.Println(A__[N-1]) // Print the last index without a trailing space
}

// <END-OF-CODE>
