package main

import (
	"fmt"
	"math"
)

// Define a long long type for convenience
type ll int64

// Function to update a variable to the maximum of itself and another value
func chmax(a *ll, b ll) bool {
	if *a < b {
		*a = b
		return true
	}
	return false
}

// Function to update a variable to the minimum of itself and another value
func chmin(a *ll, b ll) bool {
	if *a > b {
		*a = b
		return true
	}
	return false
}

// Define a constant for infinity
const INF = ll(math.Pow(10, 18) + 1)

/*
The following comments explain the logic behind the function f(N) and the overall approach.
1. The goal is to find the smallest integer n >= N such that n/S(n) is minimized.
2. The function f(N) computes candidates for this minimization by manipulating the digits of N.
*/

// Function to find the smallest integer n >= N such that n/S(n) is minimized
func f(N ll) ll {
	// Array to store the digits of N
	a := make([]ll, 20, 20)
	d := ll(0) // Digit counter

	// Extract digits of N and store them in the array
	for N > 0 {
		a[d] = N % 10 // Get the last digit
		N /= 10 // Remove the last digit
		d++ // Increment digit counter
	}

	m := 1e18 // Initialize minimum fraction to a large value
	res := N // Result variable to store the best candidate

	// Iterate through possible positions to replace digits with 9s
	for i := ll(0); i <= d; i++ {
		bunsi := ll(0) // Numerator
		bunbo := ll(9) * i // Denominator starts with 9 times the number of replaced digits

		// Construct the numerator and denominator based on the current digit manipulation
		for j := d - 1; j >= 0; j-- {
			bunsi *= 10 // Shift left for the next digit
			if j < i {
				bunsi += 9 // Replace with 9 if below the current index
			} else {
				bunsi += a[j] // Keep the original digit
			}

			if j >= i {
				bunbo += a[j] // Add to denominator if the digit is not replaced
			}
		}

		// Calculate the fraction n/S(n)
		frac := float64(bunsi) / float64(bunbo)

		// Update the result if a new minimum fraction is found
		if frac < m {
			m = frac // Update minimum fraction
			res = bunsi // Update result with the new candidate
		}
	}
	return res // Return the best candidate found
}

func main() {
	var K ll // Number of outputs to generate
	fmt.Scan(&K) // Read the number of outputs

	N := f(1) // Initialize N by finding the first candidate starting from 1

	// Generate K outputs
	for i := ll(0); i < K; i++ {
		fmt.Println(N) // Output the current candidate
		N = f(N + 1) // Find the next candidate starting from N + 1
	}
}

