package main

import (
	"fmt"
)

// gcd function calculates the greatest common divisor of two integers a and b using the Euclidean algorithm.
func gcd(a int, b int) int {
	// Base case: if b is 0, return a as the GCD
	if b == 0 {
		return a
	}
	// Recursive case: call gcd with b and the remainder of a divided by b
	return gcd(b, a%b)
}

func main() {
	// Declare variables for the upper limit (k) and loop counters (a, b, c)
	var k, a, b, c int
	// Initialize the answer variable to accumulate the results
	ans := 0
	
	// Read the upper limit k from user input
	fmt.Scan(&k)
	
	// Iterate through all combinations of a, b, and c from 1 to k
	for a = 1; a <= k; a++ {
		for b = 1; b <= k; b++ {
			for c = 1; c <= k; c++ {
				// Calculate the GCD of a, b, and c and add it to the answer
				ans += gcd(a, gcd(b, c))
			}
		}
	}
	
	// Print the final accumulated answer
	fmt.Println(ans)
}
