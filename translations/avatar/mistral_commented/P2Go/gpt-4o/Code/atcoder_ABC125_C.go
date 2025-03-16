package main

import (
	"fmt"
)

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a int, b int) int {
	// Base case: if b is 0, return a as the GCD
	if b == 0 {
		return a
	}
	// Recursive case: find the GCD of b and the remainder of a divided by b
	return gcd(b, a%b)
}

// Function to perform Ruiseki algorithm on a given array
func ruisekiLR(array []int) ([]int, []int) {
	n := len(array)
	left := make([]int, n+1)
	right := make([]int, n+1)

	// Initialize left array
	for i := 0; i < n; i++ {
		left[i+1] = gcd(left[i], array[i])
	}

	// Initialize right array
	for i := n - 1; i >= 0; i-- {
		right[i] = gcd(right[i+1], array[i])
	}

	return left, right
}

func main() {
	// Read input from the user: number of elements in the array and the array itself
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Perform Ruiseki algorithm on the given array and get the left and right arrays
	left, right := ruisekiLR(a)

	// Initialize answer variable with 0
	ans := 0

	// Iterate through the array and find the maximum GCD between adjacent elements in the left and right arrays
	for i := 0; i < n; i++ {
		ans = max(gcd(left[i], right[i+1]), ans)
	}

	// Print the final answer
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
