package main

import (
	"fmt"
	"math"
)

// Function to find the number of digits in a given number
func digit(n int64) int {
	res := 0 // Initialize result
	for n > 0 { // While number is not zero
		res++ // Increment result by 1
		n /= 10 // Divide number by 10 to get next digit
	}
	return res // Return the result
}

// Function to run the program
func run() {
	var n int64 // Initialize number variable
	fmt.Scanf("%d", &n) // Read number from standard input
	min := digit(n) // Initialize minimum with the number of digits in the number
	for i := int64(1); i*i <= n; i++ { // Loop from 1 to square root of the number
		if n%i != 0 {
			continue // If current number is not a factor of the given number, skip to next iteration
		}
		a := i // Initialize first factor
		b := n / i // Initialize second factor
		min = int(math.Min(float64(min), float64(MAX(digit(a), digit(b))))) // Update minimum
	}
	fmt.Println(min) // Print the minimum number of digits in any factor of the given number
}

// Function to get the maximum of two integers
func MAX(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Function to get the minimum of two integers
func MIN(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Main function
func main() {
	run() // Call run function to execute the program
}
