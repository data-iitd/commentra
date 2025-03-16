package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables N and K with user input
	N, K := 0, 0
	fmt.Scan(&N, &K)

	// Create a vector 'v' of size N to store the input integers
	v := make([]int, N)

	// Read N integers from the user and store them in the vector 'v'
	for i := 0; i < N; i++ {
		fmt.Scan(&v[i])
	}

	// Calculate the number of subarrays of size K that can be formed from the vector 'v'
	count := (N - 1) + ((K - 1) - 1)
	count = count / (K - 1)

	// Output the result to the console
	fmt.Println(count)
}

