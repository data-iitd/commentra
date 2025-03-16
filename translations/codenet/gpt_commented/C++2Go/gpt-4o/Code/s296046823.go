package main

import (
	"fmt"
)

func main() {
	// Declare variables N and K to hold the number of elements and the divisor respectively
	var N, K int
	
	// Read the values of N and K from standard input
	fmt.Scan(&N, &K)

	// Initialize a slice of size N to store the input elements
	v := make([]int, N)
	
	// Read N integers from standard input and store them in the slice v
	for i := 0; i < N; i++ {
		fmt.Scan(&v[i])
	}

	// Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
	// This is done using integer arithmetic to avoid floating-point operations
	count := (N - 1 + (K - 2)) / (K - 1)
	
	// Output the calculated count of groups
	fmt.Println(count)
}

// <END-OF-CODE>
