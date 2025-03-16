package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a scanner to read input from the console
	var N, K int
	fmt.Scan(&N, &K)

	// Initialize a slice to store the input integers
	S := make([]int, N)

	// Read N integers into the slice S
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	// Initialize temporary variable and answer variable with a large number
	temp := 0
	ans := math.MaxInt32

	// Case when K is 1: Find the minimum absolute value in the array
	if K == 1 {
		for i := 0; i < N; i++ {
			temp = S[i]
			ans = int(math.Min(float64(abs(temp)), float64(ans))) // Update ans with the minimum absolute value
		}
		// Output the result
		fmt.Println(ans)
	} else if N-K != 0 { // Case when K is not equal to N
		for i := 0; i <= N-K; i++ {
			min := S[i]          // Minimum value in the current subset
			max := S[i+K-1]     // Maximum value in the current subset

			// Calculate temp based on the values of min and max
			if min < 0 && max > 0 {
				// If the subset contains both negative and positive values
				temp = int(math.Min(float64(2*(-min)+max), float64((-min)+2*max)))
			} else {
				// If the subset contains only negative or only positive values
				temp = int(math.Max(float64(abs(min)), float64(abs(max))))
			}

			// Update the answer with the minimum value found
			ans = int(math.Min(float64(ans), float64(temp)))
		}
		// Output the result
		fmt.Println(ans)
	} else { // Case when K is equal to N
		min := S[0]         // Minimum value in the array
		max := S[N-1]       // Maximum value in the array

		// Check if the array contains both negative and positive values
		if min < 0 && max > 0 {
			// Calculate and print the minimum value based on the formula
			fmt.Println(int(math.Min(float64(2*(-min)+max), float64((-min)+2*max))))
		} else {
			// Print the maximum absolute value
			fmt.Println(int(math.Max(float64(abs(min)), float64(abs(max)))))
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

// <END-OF-CODE>
