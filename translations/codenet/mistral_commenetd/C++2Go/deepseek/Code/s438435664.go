package main

import (
	"fmt"
	"math"
)

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(x, y int) int {
	// Base case: if x is smaller than y, swap x and y
	if x < y {
		x, y = y, x
	}

	// Recursive case: find the remainder of x divided by y and repeat
	for y != 0 {
		x, y = y, x%y
	}

	// Return the GCD (the last non-zero value of x)
	return x
}

// Function to find the least common multiple (LCM) of two numbers
func lcm(x, y int) int {
	// Return the product of x and y divided by their GCD
	return x / gcd(x, y) * y
}

// Function to calculate the factorial (kaijo) of a number
func kaijo(k int) int {
	sum := 1
	// Calculate the factorial by multiplying the number with all the numbers less than it
	for i := 1; i <= k; i++ {
		sum *= i
		// Modulo the result by 1000000000+7 to keep the result within a certain range
		sum %= 1000000000 + 7
	}
	// Return the result
	return sum
}

// Main function
func main() {
	// Read the input values for n and k from the standard input
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize a variable to store the sum of the results
	sum := 0

	// Iterate through all possible block sizes from 1 to n
	for b := 1; b <= n; b++ {
		// Calculate the number of blocks of size b that can fit into n+1
		cnt := (n + 1) / b

		// Calculate the remainder of n+1 when divided by b
		md := (n + 1) % b

		// Add the number of blocks of size b that cover k or more numbers to the sum
		sum += cnt * max(b-k, 0) + max(md-k, 0)

		// If k is 0, subtract 1 from the sum (since an empty block doesn't contribute to the sum)
		if k == 0 {
			sum--
		}
	}

	// Print the result to the standard output
	fmt.Println(sum)
}

// Helper function to find the larger of two numbers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to find the smaller of two numbers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

