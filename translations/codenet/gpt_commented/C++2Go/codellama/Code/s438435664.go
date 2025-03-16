package main

import (
	"fmt"
	"math"
)

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(x, y int) int {
	tmp := 0
	// Ensure x is greater than or equal to y
	if x < y {
		tmp = x
		x = y
		y = tmp
	}
	// Apply the Euclidean algorithm to find GCD
	for y > 0 {
		r := x % y
		x = y
		y = r
	}
	return x // Return the GCD
}

// Function to compute the least common multiple (LCM) of two numbers
func lcm(x, y int) int {
	return x / gcd(x, y) * y // LCM formula using GCD
}

// Function to compute the factorial of a number modulo 1,000,000,007
func kaijo(k int) int {
	sum := 1
	// Calculate factorial iteratively
	for i := 1; i <= k; i++ {
		sum *= i // Multiply current sum by i
		sum %= 1000000000 + 7 // Take modulo to prevent overflow
	}
	return sum // Return the factorial
}

// Function to return the maximum of two numbers
func lmax(s, t int) int {
	if s > t {
		return s // Return s if it is greater
	}
	return t // Otherwise return t
}

// Function to return the minimum of two numbers
func lmin(s, t int) int {
	if s < t {
		return s // Return s if it is smaller
	}
	return t // Otherwise return t
}

// Main function to execute the program
func main() {
	var n, k int
	// Input the values of n and k
	fmt.Scan(&n, &k)
	sum := 0 // Initialize sum to zero

	// Loop through each integer b from 1 to n
	for b := 1; b <= n; b++ {
		// Calculate the count of multiples of b in the range [1, n]
		cnt := (n + 1) / b
		// Calculate the remainder when n + 1 is divided by b
		md := (n + 1) % b
		// Update the sum based on the count and the maximum values
		sum += cnt*max((b-k), 0) + max((md-k), 0)
		// Adjust the sum if k is zero
		if k == 0 {
			sum--
		}
	}

	// Output the final computed sum
	fmt.Println(sum)
}

// Function to return the maximum of two numbers
func max(s, t int) int {
	if s > t {
		return s // Return s if it is greater
	}
	return t // Otherwise return t
}

// Function to return the minimum of two numbers
func min(s, t int) int {
	if s < t {
		return s // Return s if it is smaller
	}
	return t // Otherwise return t
}

// END-OF-CODE
