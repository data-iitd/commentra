package main

import (
	"fmt"
)

// Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm
func gcd(a, b int) int {
	// Base case: if b is 0, return a as the GCD
	if b == 0 {
		return a
	}
	// Recursive case: call gcd with b and the remainder of a divided by b
	return gcd(b, a % b)
}

// Function to compute cumulative GCD from the left and right
func ruisekiLR(array []int) ([]int, []int) {
	// Define the operation to find the GCD of two numbers
	op := func(a, b int) int {
		return gcd(a, b)
	}
	
	// Initialize the identity element for GCD
	e := 0
	n := len(array)
	
	// Create slices to store cumulative GCD from the left and right
	left := make([]int, n + 1)
	right := make([]int, n + 1)
	
	// Calculate cumulative GCD from the left
	for i := 0; i < n; i++ {
		left[i + 1] = op(left[i], array[i])
	}
	
	// Calculate cumulative GCD from the right
	for i := n - 1; i >= 0; i-- {
		right[i] = op(right[i + 1], array[i])
	}
	
	// Return both cumulative GCD slices
	return left, right
}

func main() {
	// Read the number of elements in the array
	var n int
	fmt.Scan(&n)
	
	// Read the array elements from input and convert them to integers
	var a []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		a = append(a, x)
	}
	
	// Compute the cumulative GCD from the left and right
	left, right := ruisekiLR(a)
	
	// Initialize the answer variable to store the maximum GCD found
	ans := 0
	
	// Iterate through the array to find the maximum GCD of left and right parts
	for i := 0; i < n; i++ {
		ans = max(gcd(left[i], right[i + 1]), ans)
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

