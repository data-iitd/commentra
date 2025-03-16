package main

import (
	"fmt"
	"math"
)

func main() {
	startTime := float64(time.Now().UnixNano()) / 1e6 // Start time in milliseconds
	var n int
	fmt.Scan(&n) // Read the number of elements
	div := int64(math.Pow(10, 9) + 7) // Define the modulo constant
	A := make([]int64, n) // Initialize slice A to store n int64 integers
	var ans int64 = 0 // Initialize the answer variable

	// Read n int64 integers from the user and store them in slice A
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Iterate over each bit position from 0 to 59
	for i := 0; i < 60; i++ {
		var a int64 = 0 // Initialize the contribution for the current bit position
		var count1 int64 = 0 // Count of elements with the current bit set to 1

		// Count the number of elements with the current bit set to 1
		for j := 0; j < n; j++ {
			if (A[j]>>i)&1 == 1 {
				count1++
			}
		}

		// Calculate the contribution of the current bit position
		a += count1 * (int64(n) - count1)

		// Shift the contribution left by 1 bit for each lower bit position and take modulo
		for j := 0; j < i; j++ {
			a = (a << 1) % div
		}

		// Add the contribution to the answer and take modulo
		ans = (ans + a) % div
	}

	// Print the result
	fmt.Println(ans)
	endTime := float64(time.Now().UnixNano()) / 1e6 // End time in milliseconds
}

// <END-OF-CODE>
