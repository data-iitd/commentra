package main

import (
	"fmt"
	"math/gcd"
	"os"
)

func main() {
	var N int
	fmt.Scan(&N) // Take an integer input N, representing the number of elements in the list A.
	A := make([]int, N) // Create a slice of integers with length N.
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Take space-separated integers and assign them to the slice A.
	}

	g := A[0] // Initialize gcd with the first element of A.
	for _, num := range A[1:] {
		g = gcd(g, num) // Compute the GCD of all elements in the list A.
	}

	fmt.Println(g) // Print the computed GCD.
}

// Function to compute GCD of two numbers
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// Note: The math package in Go does not have a built-in GCD function,
// so we define our own GCD function here.
