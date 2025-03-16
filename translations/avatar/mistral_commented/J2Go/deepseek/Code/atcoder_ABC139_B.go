package main

import (
	"fmt"
)

func main() {
	// Read first integer input A from user
	var A int
	fmt.Scan(&A)

	// Read second integer input B from user
	var B int
	fmt.Scan(&B)

	// Initialize variables for storing remainders and result
	var amari int
	var result int

	// Calculate the result by dividing B by A - 1 and storing the quotient
	result = (B - 1) / (A - 1)

	// Calculate the remainder of B divided by A - 1 and store it in amari
	amari = (B - 1) % (A - 1)

	// Check if the remainder is not zero
	if amari != 0 {
		// If the remainder is not zero, increment the result by 1
		result += 1
	}

	// Write the result to the standard output
	fmt.Println(result)
}
