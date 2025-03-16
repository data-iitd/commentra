package main

import (
	"fmt"
)

// gcd calculates the greatest common divisor (GCD) of a and b
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// ruisekiLR computes the prefix and suffix GCD arrays
func ruisekiLR(array []int) ([]int, []int) {
	n := len(array)
	left := make([]int, n+1)
	right := make([]int, n+1)

	// Compute prefix GCD array
	for i := 0; i < n; i++ {
		left[i+1] = gcd(left[i], array[i])
	}

	// Compute suffix GCD array
	for i := n - 1; i >= 0; i-- {
		right[i] = gcd(right[i+1], array[i])
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

// max returns the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
