package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var N, K int
	fmt.Scan(&N, &K)
	
	// Initialize an array to store the input integers
	S := make([]int, N)
	
	// Read N integers into the array S
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}
	
	// Initialize temporary variable and answer variable with a large number
	temp := 0
	ans := 1000000000

	// Case when K is 1: Find the minimum absolute value in the array
	if K == 1 {
		for i := 0; i < N; i++ {
			temp = S[i]
			if abs(temp) < ans {
				ans = abs(temp)
			}
		}
		// Output the result
		fmt.Println(ans)
	} 
	// Case when K is not equal to N: Calculate the minimum value based on subsets of size K
	else if N - K != 0 {
		for i := 0; i <= N - K; i++ {
			min := S[i] // Minimum value in the current subset
			max := S[i + K - 1] // Maximum value in the current subset
			
			// Calculate temp based on the values of min and max
			if min < 0 && max > 0 {
				// If the subset contains both negative and positive values
				temp = minInt(2 * (-min) + max, (-min) + 2 * max)
			} else {
				// If the subset contains only negative or only positive values
				temp = maxInt(abs(min), abs(max))
			}
			
			// Update the answer with the minimum value found
			if temp < ans {
				ans = temp
			}
		}
		// Output the result
		fmt.Println(ans)
	} 
	// Case when K is equal to N: Handle the entire array as a single subset
	else {
		min := S[0] // Minimum value in the array
		max := S[N - 1] // Maximum value in the array
		
		// Check if the array contains both negative and positive values
		if min < 0 && max > 0 {
			// Calculate and print the minimum value based on the formula
			fmt.Println(minInt(2 * (-min) + max, (-min) + 2 * max))
		} else {
			// Print the maximum absolute value
			fmt.Println(maxInt(abs(min), abs(max)))
		}
	}
}

// Helper function to calculate absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to find the minimum of two integers
func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to find the maximum of two integers
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

