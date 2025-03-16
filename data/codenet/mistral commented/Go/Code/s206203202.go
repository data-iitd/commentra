// Package main is the entry point of the program
package main

import "fmt"

// Abs function returns the absolute value of an integer
func Abs(x int) int {
	if x < 0 {
		// If the input integer is negative, return its negation
		return -x
	}
	// Otherwise, return the input integer as it is
	return x
}

// min function returns the minimum of two integers
func min(a, b int) int {
	if a > b {
		// If the first integer is greater than the second, return the second
		return b
	}
	// Otherwise, return the first integer
	return a
}

// main function is the entry point of the program
func main() {
	// Declare and initialize two integer variables, N and K, using fmt.Scan
	var N, K int
	fmt.Scan(&N, &K)

	// Declare and initialize an integer variable, x, with the value of N modulo K
	var x int
	x = N % K

	// Call the Abs function to get the absolute value of x if it's negative
	x = Abs(x)

	// Call the min function to find the minimum between x and Abs(x-K)
	x = min(Abs(x-K), x)

	// Print the result using fmt.Println
	fmt.Println(x)

}