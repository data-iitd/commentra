package main

import (
	"fmt"
)

func main() {
	// Initialize variables to store the sum, current number, count of numbers, and min/max values
	var sum int64 = 0 // To hold the sum of all numbers
	var m, n, min, max int // m: current number, n: total count of numbers, min: minimum value, max: maximum value

	// Read the total number of integers to be processed
	fmt.Scan(&n)

	// Loop through each number to read and process
	for i := 0; i < n; i++ {
		// Read the current number
		fmt.Scan(&m)

		// Add the current number to the sum
		sum += int64(m)

		// Initialize min and max with the first number read
		if i == 0 {
			min = m // Set min to the first number
			max = m // Set max to the first number
		}

		// Update min if the current number is less than the current min
		if min > m {
			min = m // Update min
		}

		// Update max if the current number is greater than the current max
		if max < m {
			max = m // Update max
		}
	}

	// Print the minimum, maximum, and sum of the numbers
	fmt.Printf("%d %d %d\n", min, max, sum)
}

// <END-OF-CODE>
