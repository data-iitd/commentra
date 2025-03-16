package main

import (
	"fmt"
)

func gcd(x, y int64) int64 {
	// Ensure x is greater than or equal to y
	if x < y {
		x, y = y, x
	}
	// Apply the Euclidean algorithm to find GCD
	for y > 0 {
		r := x % y
		x = y
		y = r
	}
	return x // Return the GCD
}

func lcm(x, y int64) int64 {
	return x / gcd(x, y) * y // LCM formula using GCD
}

func kaijo(k int64) int64 {
	sum := int64(1)
	// Calculate factorial iteratively
	for i := int64(1); i <= k; i++ {
		sum *= i // Multiply current sum by i
		sum %= 1000000007 // Take modulo to prevent overflow
	}
	return sum // Return the factorial
}

func lmax(s, t int64) int64 {
	if s > t {
		return s // Return s if it is greater
	}
	return t // Otherwise return t
}

func lmin(s, t int64) int64 {
	if s < t {
		return s // Return s if it is smaller
	}
	return t // Otherwise return t
}

func main() {
	var n, k int
	// Input the values of n and k
	fmt.Scan(&n, &k)
	sum := int64(0) // Initialize sum to zero

	// Loop through each integer b from 1 to n
	for b := 1; b <= n; b++ {
		// Calculate the count of multiples of b in the range [1, n]
		cnt := (n + 1) / b
		// Calculate the remainder when n + 1 is divided by b
		md := (n + 1) % b
		// Update the sum based on the count and the maximum values
		sum += int64(cnt) * lmax(int64(b-k), 0) + lmax(int64(md-k), 0)
		// Adjust the sum if k is zero
		if k == 0 {
			sum--
		}
	}

	// Output the final computed sum
	fmt.Println(sum)
}

// <END-OF-CODE>
