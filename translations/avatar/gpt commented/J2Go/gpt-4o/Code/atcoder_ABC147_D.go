package main

import (
	"fmt"
	"math"
)

func main() {
	// Record the start time for performance measurement
	startTime := getCurrentTimeMillis()

	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Define a modulus value to prevent overflow
	div := int64(math.Pow(10, 9)) + 7

	// Initialize a slice to hold the input values
	A := make([]int64, n)

	// Variable to store the final answer
	var ans int64 = 0

	// Read n long integers into the slice A
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Iterate through each bit position from 0 to 59
	for i := 0; i < 60; i++ {
		var a int64 = 0 // Variable to accumulate contributions for the current bit
		var count1 int64 = 0 // Count of numbers with the i-th bit set

		// Count how many numbers have the i-th bit set
		for j := 0; j < n; j++ {
			if (A[j]>>i)&1 == 1 {
				count1++
			}
		}

		// Calculate the contribution of the current bit to the answer
		a += count1 * (int64(n) - count1)

		// Shift the contribution left by i positions (equivalent to multiplying by 2^i)
		for j := 0; j < i; j++ {
			a = (a << 1) % div
		}

		// Add the contribution to the final answer and apply modulus
		ans = (ans + a) % div
	}

	// Output the final answer
	fmt.Println(ans)

	// Record the end time for performance measurement
	endTime := getCurrentTimeMillis()
	// You can print the time taken if needed
	// fmt.Println("Time taken:", endTime-startTime)
}

// Function to get the current time in milliseconds
func getCurrentTimeMillis() int64 {
	return int64(float64(time.Now().UnixNano()) / 1e6)
}
