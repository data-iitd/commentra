
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Record the start time for performance measurement
	startTime := time.Now()

	// Create a Scanner object for input
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	// Define a modulus value to prevent overflow
	div := int64(1e9 + 7)

	// Initialize an array to hold the input values
	A := make([]int64, n)

	// Variable to store the final answer
	ans := int64(0)

	// Read n integers into the array A
	for i := 0; i < n; i++ {
		sc.Scan()
		A[i], _ = strconv.ParseInt(sc.Text(), 10, 64)
	}

	// Iterate through each bit position from 0 to 59
	for i := 0; i < 60; i++ {
		a := int64(0) // Variable to accumulate contributions for the current bit
		count1 := int64(0) // Count of numbers with the i-th bit set

		// Count how many numbers have the i-th bit set
		for j := 0; j < n; j++ {
			if A[j]>>i&1 == 1 {
				count1++
			}
		}

		// Calculate the contribution of the current bit to the answer
		a = a + count1 * (int64(n) - count1)

		// Shift the contribution left by i positions (equivalent to multiplying by 2^i)
		for j := 0; j < i; j++ {
			a = (a << 1) % div
		}

		// Add the contribution to the final answer and apply modulus
		ans += a
		ans %= div
	}

	// Output the final answer
	fmt.Println(ans)

	// Record the end time for performance measurement
	endTime := time.Now()
}

