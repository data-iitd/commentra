package main

import (
	"fmt"
	"math"
)

// Define a constant for a large number to represent infinity
const inf = 10000000000.0

func main() {
	// Read the number of elements in the array
	var n int
	fmt.Scan(&n)

	// Initialize an array to hold the input values
	arrA := make([]int, n)
	// Read the input values into the array
	for i := 0; i < n; i++ {
		fmt.Scan(&arrA[i])
	}

	// Create a cumulative sum array to store the cumulative sums of arrA
	cumSumA := make([]int, n+1)
	cumSumA[0] = 0 // The first element is 0 (sum of zero elements)
	// Calculate the cumulative sums
	for i, a := range arrA {
		cumSumA[i+1] = cumSumA[i] + a
	}

	// Initialize the answer variable to a large value
	ans := inf
	// Iterate through the cumulative sums to find the minimum difference
	for i := 1; i < n; i++ {
		// Calculate the absolute difference between the total sum and twice the current cumulative sum
		if math.Abs(float64(cumSumA[n]-(cumSumA[i]*2))) < ans {
			// Update the answer if the current difference is smaller
			ans = math.Abs(float64(cumSumA[n] - cumSumA[i]*2))
		}
	}

	// Print the final answer as an integer
	fmt.Println(int(ans))
}
