package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of elements N from input
	var N int
	fmt.Scanf("%d", &N)

	// Initialize a slice A to hold N integers
	A := make([]int, N)
	
	// Read N integers from input into the slice A
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}

	// Sort the slice A in ascending order
	sort.Sort(sort.IntSlice(A))

	// Initialize a variable to hold the total difference sum
	var ans int
	
	// Calculate the sum of differences between consecutive elements in the sorted slice
	for i := 1; i < N; i++ {
		ans += A[i] - A[i-1]
	}

	// Output the total sum of differences
	fmt.Println(ans)
}
