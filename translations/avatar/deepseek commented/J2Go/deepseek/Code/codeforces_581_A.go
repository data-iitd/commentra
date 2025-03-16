package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Read first integer input

	count := 0 // Initialize count to keep track of loop iterations

	// Loop continues until the condition is met to break
	for {
		if a > 0 && b > 0 { // Check if both a and b are positive
			count++ // Increment count
			a--     // Decrement a
			b--     // Decrement b
		} else {
			break // Break the loop if a or b is not positive
		}
	}

	ans := a/2 + b/2 // Calculate the value of ans
	fmt.Println(count, ans) // Print the results
}

