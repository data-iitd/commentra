package main

import (
	"fmt"
)

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	// Recursively calculates the greatest common divisor (GCD) of a and b
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to compute prefix and suffix GCD arrays
func ruisekiLR(array []int) ([]int, []int) {
	// Defines a lambda function to compute GCD
	op := func(a, b int) int {
		return gcd(a, b)
	}
	// Initial GCD value
	e := 0
	// Length of the input array
	n := len(array)
	// Initialize prefix and suffix GCD arrays
	left := make([]int, n+1)
	right := make([]int, n+1)
	// Fill the prefix GCD array with initial value
	for i := range left {
		left[i] = e
	}
	// Fill the suffix GCD array with initial value
	for i := range right {
		right[i] = e
	}
	// Compute prefix GCD array
	for i := 0; i < n; i++ {
		left[i+1] = op(left[i], array[i])
	}
	// Compute suffix GCD array
	for i := n - 1; i >= 0; i-- {
		right[i] = op(right[i+1], array[i])
	}
	return left, right
}

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)
	// Read the list of elements
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	// Compute prefix and suffix GCD arrays
	left, right := ruisekiLR(a)
	// Initialize the answer variable
	ans := 0
	// Iterate through the array to find the maximum GCD
	for i := 0; i < n; i++ {
		ans = max(gcd(left[i], right[i+1]), ans)
	}
	// Print the result
	fmt.Println(ans)
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

