package main

import (
	"fmt"
	"math"
)

// Define a type for 64-bit integers
type int64 int64

// Macros for mathematical operations: MAX, MIN, and ABS
func MAX(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func MIN(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func ABS(a int64) int64 {
	if a > 0 {
		return a
	}
	return -a
}

// Function to count the number of digits in a given integer
func digit(n int64) int {
	res := 0 // Initialize digit count to zero
	// Loop until all digits are processed
	for n > 0 {
		res++ // Increment digit count
		n /= 10 // Remove the last digit
	}
	return res // Return the total count of digits
}

// Function to execute the main logic of the program
func run() {
	var n int64 // Variable to store the input number
	// Read a long long integer from standard input
	fmt.Scan(&n)

	// Initialize minimum digit count with the digit count of n
	min := digit(n)
	var i int64

	// Loop through all possible divisors of n
	for i = 1; i*i <= n; i++ {
		// Skip if i is not a divisor of n
		if n%i != 0 {
			continue
		}

		// Calculate the corresponding divisor
		a := i
		b := n / i

		// Update the minimum digit count based on the digits of the divisors
		min = MIN(min, MAX(digit(a), digit(b)))
	}

	// Print the minimum digit count found
	fmt.Println(min)
}

// Main function to start the program execution
func main() {
	run() // Call the run function to execute the logic
}

