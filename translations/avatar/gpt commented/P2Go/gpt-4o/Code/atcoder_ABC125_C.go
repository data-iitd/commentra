package main

import (
	"fmt"
)

// Function to compute the GCD of two integers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to compute cumulative GCD from left and right
func ruisekiLR(array []int) ([]int, []int) {
	n := len(array)
	left := make([]int, n+1)
	right := make([]int, n+1)

	// Initialize the identity element for GCD
	e := 0

	// Calculate cumulative GCD from the left
	for i := 0; i < n; i++ {
		left[i+1] = gcd(left[i], array[i])
	}

	// Calculate cumulative GCD from the right
	for i := n - 1; i >= 0; i-- {
		right[i] = gcd(right[i+1], array[i])
	}

	return left, right
}

func main() {
	// Read the number of elements in the array
	var n int
	fmt.Scan(&n)

	// Read the array elements from input
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Compute the cumulative GCD from the left and right
	left, right := ruisekiLR(a)

	// Initialize the answer variable to store the maximum GCD found
	ans := 0

	// Iterate through the array to find the maximum GCD of left and right parts
	for i := 0; i < n; i++ {
		ans = max(gcd(left[i], right[i+1]), ans)
	}

	// Print the maximum GCD found
	fmt.Println(ans)
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
