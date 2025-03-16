package main

import (
	"fmt"
	"math"
)

// Function to find the smallest divisor of n
func div(n int) int {
	// Check if n is even, return 2 if it is
	if n%2 == 0 {
		return 2
	}

	// Calculate the square root of n for optimization
	s := int(math.Sqrt(float64(n)))

	// Check for odd divisors from 3 up to the square root of n
	for i := 3; i <= s; i += 2 {
		// If i is a divisor of n, return it
		if n%i == 0 {
			return i
		}
	}

	// If no divisors found, return n (n is prime)
	return n
}

func main() {
	var num int // Variable to store the input number
	fmt.Scan(&num) // Read an integer from the user
	fmt.Print(num, ":") // Output the initial number followed by a colon

	// Loop until num is reduced to 1
	for num != 1 {
		// Find and output the smallest divisor of num
		smallestDivisor := div(num)
		fmt.Print(" ", smallestDivisor)
		// Divide num by its smallest divisor
		num = num / smallestDivisor
	}
	fmt.Println() // Print a newline at the end of output
}

// <END-OF-CODE>
