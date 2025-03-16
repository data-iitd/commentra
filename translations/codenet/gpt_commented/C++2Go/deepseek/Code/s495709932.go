package main

import (
	"fmt"
	"math"
)

func main() {
	// Optimize input/output operations
	var N int
	fmt.Scan(&N)
	
	// Initialize a slice to store the elements
	A := make([]int64, N)
	
	// Read the elements into the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	
	// Initialize a variable to keep track of the maximum difference
	var answer int64 = 0
	
	// Iterate through all pairs of elements to find the maximum difference
	for i := 0; i < N - 1; i++ {
		for j := i + 1; j < N; j++ {
			// Calculate the absolute difference between the two elements
			diff := int64(math.Abs(float64(A[i] - A[j])))
			
			// Update the maximum difference found so far
			if diff > answer {
				answer = diff
			}
		}
	}
	
	// Output the maximum difference
	fmt.Println(answer)
}

