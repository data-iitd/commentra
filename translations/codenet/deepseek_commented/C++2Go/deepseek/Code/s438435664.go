package main

import (
	"fmt"
	"math"
)

// Computes the greatest common divisor of two numbers x and y
func gcd(x, y int) int {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

// Computes the least common multiple of two numbers x and y
func lcm(x, y int) int {
	return x / gcd(x, y) * y
}

// Computes the factorial of a number k modulo 10^9 + 7
func kaijo(k int) int {
	sum := 1
	for i := 1; i <= k; i++ {
		sum *= i
		sum %= 1000000007
	}
	return sum
}

// Utility functions to find the maximum and minimum of two numbers
func lmax(s, t int) int {
	if s > t {
		return s
	} else {
		return t
	}
}

func lmin(s, t int) int {
	if s < t {
		return s
	} else {
		return t
	}
}

func main() {
	// Read two integers n and k
	var n, k int
	fmt.Scan(&n, &k)
	sum := 0

	// Iterate over possible values of b
	for b := 1; b <= n; b++ {
		// Calculate the count and remainder
		cnt := (n + 1) / b
		md := (n + 1) % b

		// Update the sum based on the conditions involving k
		sum += cnt * int(math.Max(float64(b-k), 0)) + int(math.Max(float64(md-k), 0))

		// Adjust the sum if k is 0
		if k == 0 {
			sum--
		}
	}

	// Print the computed sum
	fmt.Println(sum)
}
