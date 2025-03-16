package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a scanner to read input from the console
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the characters representing the actions
	ch := make([]rune, n)

	// Initialize sums for two different actions
	s1, s2 := 0, 0

	// Loop variables
	var flag int
	j := 0

	// Process each pair of integers
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y)

		// Calculate temporary sums for the current iteration
		temp1 := s1 + x
		temp2 := s2 + y

		// Check if adding x to s1 keeps the difference within 500
		if math.Abs(float64(temp1-s2)) <= 500 {
			s1 += x // Update s1
			ch[j] = 'A' // Record the action 'A'
			j++
			continue // Move to the next iteration
		}

		// Check if adding y to s2 keeps the difference within 500
		if math.Abs(float64(temp2-s1)) <= 500 {
			s2 += y // Update s2
			ch[j] = 'G' // Record the action 'G'
			j++
			continue // Move to the next iteration
		}

		// If neither condition is met, set flag to indicate failure
		flag = 1
		break // Exit the loop
	}

	// Check if the loop was exited due to a failure condition
	if flag == 1 {
		fmt.Println(-1) // Output -1 to indicate failure
	} else {
		// Convert the character slice to a string and print the result
		ans := string(ch[:j]) // Only take the filled part of the slice
		fmt.Println(ans) // Output the recorded actions
	}
}

// <END-OF-CODE>
