package main

import (
	"fmt"
)

// Function to compute the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
	// Base case: if 'a' is 0, return 'b' as the GCD
	if a == 0 {
		return b
	}
	// Recursive case: call gcd with 'b' modulo 'a' and 'a'
	return gcd(b%a, a)
}

func main() {
	var R int // Variable to store the input rating
	fmt.Scan(&R) // Read the rating from standard input

	// Determine the category based on the rating value
	if R < 1200 {
		fmt.Println("ABC") // Output "ABC" for ratings less than 1200
	} else if R >= 2800 {
		fmt.Println("AGC") // Output "AGC" for ratings 2800 and above
	} else {
		fmt.Println("ARC") // Output "ARC" for ratings between 1200 and 2800
	}
}

