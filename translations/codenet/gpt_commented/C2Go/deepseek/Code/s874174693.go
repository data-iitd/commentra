package main

import (
	"fmt"
)

// Function to swap two integers
func swap(x *int, y *int) {
	temp := *x
	*x = *y
	*y = temp
}

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// Comparison function for sorting in ascending order
func upll(a, b interface{}) int {
	va := a.(int64)
	vb := b.(int64)
	if va < vb {
		return -1
	}
	if va > vb {
		return 1
	}
	return 0
}

// Comparison function for sorting in descending order
func downll(a, b interface{}) int {
	va := a.(int64)
	vb := b.(int64)
	if va < vb {
		return 1
	}
	if va > vb {
		return -1
	}
	return 0
}

// Function to sort an array in ascending order
func sortup(a []int64) {
	// Use qsort with the ascending comparison function
	// qsort(a, n, sizeof(int64), upll)
}

// Function to sort an array in descending order
func sortdown(a []int64) {
	// Use qsort with the descending comparison function
	// qsort(a, n, sizeof(int64), downll)
}

// Function to compute modular exponentiation
func modpow(a, n, mod int) int {
	ans := 1
	for n > 0 {
		if n & 1 == 1 {
			ans = ans * a % mod
		}
		a = a * a % mod
		n /= 2
	}
	return ans
}

// Function to compute modular inverse using Fermat's little theorem
func modinv(a, mod int) int {
	return modpow(a, mod-2, mod)
}

// Function to return the maximum of two integers
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to update the value of a if b is greater
func chmax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

// Function to update the value of a if b is smaller
func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

// Main function
func main() {
	var n int
	// Read an integer n from input
	fmt.Scan(&n)
	sum := 0
	m := n

	// Calculate the sum of the digits of n (up to 9 digits)
	for i := 0; i < 9; i++ {
		sum += n % 10
		n /= 10
	}

	// Check if m is divisible by the sum of its digits
	if m % sum == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

