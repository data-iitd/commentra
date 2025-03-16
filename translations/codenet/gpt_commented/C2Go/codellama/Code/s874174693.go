
package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
)

// Function to swap two integers
func swap(x, y int) {
	var temp int

	// Swap the values of x and y
	temp = x
	x = y
	y = temp

	return
}

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	var c int

	// Use the Euclidean algorithm to find GCD
	for b > 0 {
		c = a % b
		a = b
		b = c
	}

	return a // Return the GCD
}

// Comparison function for sorting in ascending order
func upll(a, b int) int {
	return a - b
}

// Comparison function for sorting in descending order
func downll(a, b int) int {
	return b - a
}

// Function to sort an array in ascending order
func sortup(a []int, n int) {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] }) // Use sort.Slice with the ascending comparison function
}

// Function to sort an array in descending order
func sortdown(a []int, n int) {
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] }) // Use sort.Slice with the descending comparison function
}

// Function to compute modular exponentiation
func modpow(a, n, mod int) int {
	var ans int = 1

	// Exponentiation by squaring method
	for n > 0 {
		if n&1 == 1 { // If n is odd
			ans = (ans * a) % mod // Multiply the base with the result
		}
		a = (a * a) % mod // Square the base
		n /= 2            // Divide n by 2
	}
	return ans // Return the result
}

// Function to compute modular inverse using Fermat's little theorem
func modinv(a, mod int) int {
	return modpow(a, mod-2, mod) // a^(mod-2) mod mod
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a < b {
		return b // Return b if a is less than b
	}
	return a // Otherwise return a
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a > b {
		return b // Return b if a is greater than b
	}
	return a // Otherwise return a
}

// Function to update the value of a if b is greater
func chmax(a *int, b int) {
	if *a < b {
		*a = b // Update a to b if b is greater
	}

	return
}

// Function to update the value of a if b is smaller
func chmin(a *int, b int) {
	if *a > b {
		*a = b // Update a to b if b is smaller
	}

	return
}

// Main function
func main() {
	var n int
	// Read an integer n from input
	fmt.Scan(&n)
	var sum int = 0 // Initialize sum to 0
	var m int = n   // Store the original value of n

	// Calculate the sum of the digits of n (up to 9 digits)
	for i := 0; i < 9; i++ {
		sum += n % 10 // Add the last digit to sum
		n /= 10       // Remove the last digit
	}

	// Check if m is divisible by the sum of its digits
	if m%sum == 0 {
		fmt.Println("Yes") // Print "Yes" if divisible
	} else {
		fmt.Println("No") // Print "No" if not divisible
	}

	return
}

