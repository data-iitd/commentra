package main

import (
	"fmt"
	"math"
)

// Function to compute the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
	// Ensure 'a' is the larger number for the algorithm
	if a < b {
		a, b = b, a
	}
	for b != 0 {
		a, b = b, a % b
	}
	return a // Return the GCD
}

func main() {
	var n int // Variable to store the number of integers
	fmt.Scan(&n) // Read the number of integers from input

	var ans int // Variable to store the current GCD result
	fmt.Scan(&ans) // Read the first integer and initialize 'ans' with it

	// Loop through the remaining integers to compute the GCD
	for i := 1; i < n; i++ {
		var a int // Variable to store the current integer
		fmt.Scan(&a) // Read the current integer from input
		ans = gcd(ans, a) // Update 'ans' with the GCD of 'ans' and 'a'
	}

	// Output the final GCD result
	fmt.Println(ans)
}

