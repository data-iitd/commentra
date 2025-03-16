package main

import (
	"fmt"
	"math/big"
)

// Define a function to calculate the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func main() {
	// Ask the user for the number of elements in the list
	var N int
	fmt.Scan(&N)

	// Get a list of integers from the user input
	var A []int
	for i := 0; i < N; i++ {
		var num int
		fmt.Scan(&num)
		A = append(A, num)
	}

	// Initialize a variable to hold the GCD of all integers in the list A
	gcd := A[0]

	// Use a loop to calculate the GCD of all integers in the list A
	for i := 1; i < N; i++ {
		gcd = gcd(A[i], gcd)
	}

	// Print the result, which is the GCD of all the integers in the list A
	fmt.Println(gcd)
}
