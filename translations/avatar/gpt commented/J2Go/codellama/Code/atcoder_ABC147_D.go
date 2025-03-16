
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Record the start time for performance measurement
	startTime := float64(os.Getpid()) / 1000000000

	// Create a Scanner object for input
	sc := make([]int, 0)

	// Read the number of elements
	n, _ := strconv.Atoi(os.Args[1])

	// Define a modulus value to prevent overflow
	div := int(math.Pow(10, 9) + 7)

	// Initialize an array to hold the input values
	A := make([]int, n)

	// Variable to store the final answer
	ans := 0

	// Read n long integers into the array A
	for i := 0; i < n; i++ {
		A[i], _ = strconv.Atoi(os.Args[i+2])
	}

	// Iterate through each bit position from 0 to 59
	for i := 0; i < 60; i++ {
		a := 0 // Variable to accumulate contributions for the current bit
		count1 := 0 // Count of numbers with the i-th bit set

		// Count how many numbers have the i-th bit set
		for j := 0; j < n; j++ {
			if (A[j] >> i & 1) == 1 {
				count1++
			}
		}

		// Calculate the contribution of the current bit to the answer
		a = a + count1*(n-count1)

		// Shift the contribution left by i positions (equivalent to multiplying by 2^i)
		for j := 0; j < i; j++ {
			a = a << 1
		}

		// Add the contribution to the final answer and apply modulus
		ans += a
		ans %= div
	}

	// Output the final answer
	fmt.Println(ans)

	// Record the end time for performance measurement
	endTime := float64(os.Getpid()) / 1000000000
	fmt.Println("Time elapsed:", endTime-startTime, "seconds")
}

