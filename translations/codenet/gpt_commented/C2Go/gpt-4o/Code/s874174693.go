package main

import (
	"fmt"
)

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int64) int64 {
	var c int64
	for b > 0 {
		c = a % b
		a = b
		b = c
	}
	return a // Return the GCD
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a < b {
		return b // Return b if a is less than b
	}
	return a // Otherwise return a
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a // Return a if it is less than b
	}
	return b // Otherwise return b
}

// Function to update the value of a if b is greater
func chmax(a *int, b int) {
	if *a < b {
		*a = b // Update a to b if b is greater
	}
}

// Function to update the value of a if b is smaller
func chmin(a *int, b int) {
	if *a > b {
		*a = b // Update a to b if b is smaller
	}
}

// Main function
func main() {
	var n int
	// Read an integer n from input
	fmt.Scan(&n)
	sum := 0 // Initialize sum to 0
	m := n   // Store the original value of n

	// Calculate the sum of the digits of n (up to 9 digits)
	for i := 0; i < 9; i++ {
		sum += n % 10 // Add the last digit to sum
		n /= 10      // Remove the last digit
	}

	// Check if m is divisible by the sum of its digits
	if m%sum == 0 {
		fmt.Println("Yes") // Print "Yes" if divisible
	} else {
		fmt.Println("No") // Print "No" if not divisible
	}
}

// <END-OF-CODE>
