package main

import (
	"fmt"
	"math"
)

// Function to update a variable to the maximum of itself and another value
func chmax(a *int, b int) bool {
	if *a < b {
		*a = b
		return true
	}
	return false
}

// Function to update a variable to the minimum of itself and another value
func chmin(a *int, b int) bool {
	if *a > b {
		*a = b
		return true
	}
	return false
}

// Define a constant for infinity
const inf = 1e18 + 1

// Function to find the smallest integer n >= N such that n/S(n) is minimized
func f(N int) int {
	// Array to store the digits of N
	var a [20]int
	d := 0 // Digit counter

	// Extract digits of N and store them in the array
	for N > 0 {
		a[d] = N % 10
		N /= 10
		d++
	}

	m := math.Inf(1) // Initialize minimum fraction to a large value
	res := N // Result variable to store the best candidate

	// Iterate through possible positions to replace digits with 9s
	for i := 0; i <= d; i++ {
		bunsi := 0 // Numerator
		bunbo := 9 * i // Denominator starts with 9 times the number of replaced digits

		// Construct the numerator and denominator based on the current digit manipulation
		for j := d - 1; j >= 0; j-- {
			bunsi *= 10
			if j < i {
				bunsi += 9
			} else {
				bunsi += a[j]
			}

			if j >= i {
				bunbo += a[j]
			}
		}

		// Calculate the fraction n/S(n)
		frac := float64(bunsi) / float64(bunbo)

		// Update the result if a new minimum fraction is found
		if frac < m {
			m = frac
			res = bunsi
		}
	}
	return res
}

func main() {
	var K int
	fmt.Scan(&K) // Read the number of outputs

	N := f(1) // Initialize N by finding the first candidate starting from 1

	// Generate K outputs
	for i := 0; i < K; i++ {
		fmt.Println(N) // Output the current candidate
		N = f(N + 1)   // Find the next candidate starting from N + 1
	}
}

