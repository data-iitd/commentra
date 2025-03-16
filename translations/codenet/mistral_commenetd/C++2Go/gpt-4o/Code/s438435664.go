package main

import (
	"fmt"
)

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(x, y int64) int64 {
	if x < y {
		x, y = y, x
	}
	for y > 0 {
		r := x % y
		x = y
		y = r
	}
	return x
}

// Function to find the least common multiple (LCM) of two numbers
func lcm(x, y int64) int64 {
	return x / gcd(x, y) * y
}

// Function to calculate the factorial (kaijo) of a number
func kaijo(k int64) int64 {
	sum := int64(1)
	for i := int64(1); i <= k; i++ {
		sum *= i
		sum %= 1000000000 + 7
	}
	return sum
}

// Function to find the larger of two numbers
func lmax(s, t int64) int64 {
	if s > t {
		return s
	}
	return t
}

// Function to find the smaller of two numbers
func lmin(s, t int64) int64 {
	if s < t {
		return s
	}
	return t
}

// Main function
func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Initialize a variable to store the sum of the results
	var sum int64 = 0

	// Iterate through all possible block sizes from 1 to n
	for b := 1; b <= n; b++ {
		// Calculate the number of blocks of size b that can fit into n+1
		cnt := (n + 1) / b

		// Calculate the remainder of n+1 when divided by b
		md := (n + 1) % b

		// Add the number of blocks of size b that cover k or more numbers to the sum
		sum += int64(cnt)*lmax(int64(b-k), 0) + lmax(int64(md-k), 0)

		// If k is 0, subtract 1 from the sum (since an empty block doesn't contribute to the sum)
		if k == 0 {
			sum--
		}
	}

	// Print the result to the standard output
	fmt.Println(sum)
}

// <END-OF-CODE>
