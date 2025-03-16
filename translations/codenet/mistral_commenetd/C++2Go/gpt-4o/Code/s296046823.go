package main

import (
	"fmt"
)

func main() {
	// Initialize variables N and K with user input
	var N, K int
	fmt.Scan(&N, &K)

	// Create a slice 'v' of size N to store the input integers
	v := make([]int, N)

	// Read N integers from the user and store them in the slice 'v'
	for i := 0; i < N; i++ {
		fmt.Scan(&v[i])
	}

	// Calculate the number of subarrays of size K that can be formed from the slice 'v'
	count := ((N - 1) + ((K - 1) - 1)) / (K - 1)

	// Output the result to the console
	fmt.Println(count)
}

// <END-OF-CODE>
