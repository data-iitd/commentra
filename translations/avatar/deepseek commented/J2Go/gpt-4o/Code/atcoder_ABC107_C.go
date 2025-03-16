package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K) // Read the values of N and K
	S := make([]int, N) // Create a slice S of size N

	// Read the elements of the slice S
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	temp := 0 // Initialize temp to store intermediate results
	ans := math.MaxInt32 // Initialize ans to store the minimum difference

	// Check if K is equal to 1
	if K == 1 {
		for i := 0; i < N; i++ {
			temp = S[i] // Store the current element in temp
			ans = min(abs(temp), ans) // Update ans with the minimum absolute value
		}
		fmt.Println(ans) // Print the minimum absolute value
	} else if N-K != 0 { // Check if the length of the subarray is not zero
		for i := 0; i <= N-K; i++ {
			min := S[i] // Initialize min with the first element of the subarray
			max := S[i+K-1] // Initialize max with the last element of the subarray

			// Check if the subarray contains both positive and negative numbers
			if min < 0 && max > 0 {
				temp = min(2*(-min)+max, (-min)+2*max) // Calculate the minimum difference
			} else {
				temp = max(abs(min), abs(max)) // Calculate the maximum absolute value
			}

			ans = min(ans, temp) // Update ans with the minimum difference
		}
		fmt.Println(ans) // Print the minimum difference
	} else { // If the length of the subarray is zero
		min := S[0] // Initialize min with the first element
		max := S[N-1] // Initialize max with the last element

		// Check if the array contains both positive and negative numbers
		if min < 0 && max > 0 {
			fmt.Println(min(2*(-min)+max, (-min)+2*max)) // Print the minimum difference
		} else {
			fmt.Println(max(abs(min), abs(max))) // Print the maximum absolute value
		}
	}
}

// Helper function to calculate the absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
