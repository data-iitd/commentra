package main

import "fmt"

// Abs function returns the absolute value of an integer x.
func Abs(x int) int {
	if x < 0 {
		return -x // If x is negative, return its negation.
	}
	return x // If x is non-negative, return x itself.
}

// min function returns the smaller of two integers a and b.
func min(a, b int) int {
	if a > b {
		return b // If a is greater than b, return b.
	}
	return a // Otherwise, return a.
}

func main() {
	var N, K int
	// Read two integers N and K from standard input.
	fmt.Scan(&N, &K)

	// The following block is commented out; it appears to be an alternative approach
	// to find a minimum value based on some conditions involving N and K.
	/*
	hm := make(map[int]bool) // Create a map to track seen values of N.
	for {
		if !hm[N] { // If N has not been seen before,
			hm[N] = true // mark it as seen.
			N = Abs(N - K) // Update N to the absolute difference of N and K.
		} else {
			break // If N has been seen, exit the loop.
		}
	}
	var mini int
	mini = 999999999 // Initialize mini to a large value.
	for k := range hm { // Iterate over the keys in the map.
		mini = min(mini, k) // Update mini to the minimum value found.
	}
	fmt.Println(mini) // Print the minimum value found.
	*/

	var x int
	// Calculate the remainder of N divided by K.
	x = N % K
	// Determine the minimum between the absolute difference of (x - K) and x.
	x = min(Abs(x-K), x)
	// Print the final result.
	fmt.Println(x)
}
