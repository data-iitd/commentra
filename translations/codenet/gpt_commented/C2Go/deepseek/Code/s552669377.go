package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var i, n int
	var tmp int
	var min, max, sum int64 = 1000000, -1000000, 0

	// Read the number of integers to be processed
	fmt.Scan(&n)
	
	// Loop to read n integers
	for i = 0; i < n; i++ {
		// Read the next integer
		fmt.Scan(&tmp)
		
		// Update min if the current number is smaller
		if min > int64(tmp) {
			min = int64(tmp)
		}
		
		// Update max if the current number is larger
		if max < int64(tmp) {
			max = int64(tmp)
		}
		
		// Add the current number to the sum
		sum += int64(tmp)
	}

	// Print the minimum, maximum, and sum of the numbers
	fmt.Printf("%d %d %d\n", min, max, sum)
}

