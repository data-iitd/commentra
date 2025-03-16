package main

import (
	"fmt"
	"math/gcd"
)

// Function to calculate GCD of two numbers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to calculate GCD of a slice of integers
func gcdOfSlice(arr []int) int {
	result := arr[0]
	for _, value := range arr[1:] {
		result = gcd(result, value)
	}
	return result
}

func main() {
	// Read an integer input N, which represents the number of elements in the list
	var N int
	fmt.Scan(&N)

	// Read a line of input, split it into individual string elements, convert them to integers,
	// and store them in a slice A
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Calculate the GCD of all elements in the slice A
	result := gcdOfSlice(A)

	// Print the calculated GCD
	fmt.Println(result)
}

// <END-OF-CODE>
