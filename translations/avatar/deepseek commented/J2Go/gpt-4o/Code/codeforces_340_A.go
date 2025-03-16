package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int64 // Declare variables to hold the input values
	fmt.Scan(&x, &y, &a, &b) // Read the input values

	var j int64 = 2
	var c int64 = 0
	ans := true // Initialize a boolean variable to track the result

	// Calculate the maximum of x and y and store it in c
	c = max(x, y)

	// If c is greater than b, print "0" and set ans to false
	if c > b {
		fmt.Println("0")
		ans = false
	}

	// Continue looping until c is divisible by the minimum of x and y or ans is false
	for c%min(x, y) != 0 && ans {
		if x > y {
			c = x * j // Update c to be x multiplied by j
		} else {
			c = y * j // Update c to be y multiplied by j
		}
		j++ // Increment j

		// If the updated c is greater than b, print "0" and break out of the loop
		if c > b {
			fmt.Println("0")
			ans = false
			break
		}
	}

	// If ans is still true, calculate the number of multiples of c between a and b
	if ans {
		count := int64(0)
		i := a
		for i <= b {
			if i%c == 0 {
				break // Break if a multiple of c is found
			}
			i++
		}
		if i != b+1 {
			fmt.Println((b - i) / c + 1) // Print the number of multiples
		} else {
			fmt.Println("0")
		}
	}
}

// Helper function to get the maximum of two int64 values
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// Helper function to get the minimum of two int64 values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
