package main

import (
	"fmt"
)

func main() {
	// Declare variables for the number of elements (N) and the threshold value (X)
	var N, X int
	
	// Read the values of N and X from standard input
	fmt.Scan(&N, &X)
	
	// Initialize a slice L of size N to store the elements
	L := make([]int, N)
	
	// Read N elements into the slice L
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}
	
	// Initialize index variable and a variable to accumulate the sum
	var d int
	
	// Iterate through the elements of the slice L
	for i := 0; i < N; i++ {
		// Accumulate the sum of elements
		d += L[i]
		
		// Check if the accumulated sum exceeds the threshold X
		if d > X {
			// Output the number of elements processed before exceeding X
			fmt.Println(i + 1) // i + 1 because we want to count the number of elements
			return
		}
	}
	
	// If the loop completes without exceeding X, output N
	fmt.Println(N)
}

// <END-OF-CODE>
