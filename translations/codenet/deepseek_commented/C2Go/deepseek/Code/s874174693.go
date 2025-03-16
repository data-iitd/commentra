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

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

// Function to compare int64 integers for ascending order in sorting
func upll(a, b *int64) int {
	if *a < *b {
		return -1
	}
	if *a > *b {
		return 1
	}
	return 0
}

// Function to compare int64 integers for descending order in sorting
func downll(a, b *int64) int {
	if *a < *b {
		return 1
	}
	if *a > *b {
		return -1
	}
	return 0
}

// Function to sort an array of int64 integers in ascending order
func sortup(a []int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

// Function to sort an array of int64 integers in descending order
func sortdown(a []int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}

// Function to calculate (a^n) % mod using modular exponentiation
func modpow(a, n, mod int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n & 1 == 1 {
			ans = ans * a % mod
		}
		a = a * a % mod
		n /= 2
	}
	return ans
}

// Function to calculate modular multiplicative inverse
func modinv(a, mod int64) int64 {
	return modpow(a, mod-2, mod)
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to update a variable if it is smaller
func chmax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

// Function to update a variable if it is larger
func chmin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

// Main function
func main() {
	var n int
	fmt.Scan(&n)
	sum := 0
	m := n
	for i := 0; i < 9; i++ {
		sum += n % 10
		n /= 10
	}
	if m % sum == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

