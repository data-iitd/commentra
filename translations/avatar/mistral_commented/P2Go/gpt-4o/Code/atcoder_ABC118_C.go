package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	// Ask the user for the number of elements in the list
	var N int
	fmt.Scan(&N)

	// Get a list of integers from the user input
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Use the gcd function to calculate the GCD of all integers in the list A
	result := A[0]
	for i := 1; i < N; i++ {
		result = gcd(result, A[i])
	}

	// Print the result, which is the GCD of all the integers in the list A
	fmt.Println(result)
}

// <END-OF-CODE>
