package main

import (
	"fmt"
	"math"
)

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
	fmt.Scanf("%d", &n)

	// Initialize minimum digit count with the digit count of n
	min := digit(n)

	// Loop through all possible divisors of n
	for i := int64(1); i*i <= n; i++ {
		// Skip if i is not a divisor of n
		if n%i != 0 {
			continue
		}

		// Calculate the corresponding divisor
		a := i
		b := n / i

		// Update the minimum digit count based on the digits of the divisors
		min = int(math.Min(float64(min), float64(max(digit(a), digit(b)))))
	}

	// Print the minimum digit count found
	fmt.Println(min)
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Main function to start the program execution
func main() {
	run() // Call the run function to execute the logic
}

// <END-OF-CODE>
