package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	ch := make([]rune, n) // Declare a slice to store the result
	s1, s2 := 0, 0 // Initialize sums for two paths
	j, flag := 0, 0 // Declare loop variables and a flag for invalid configuration

	// Loop to read inputs and decide paths
	for i := 0; i < n; i++ {
		var x, y int
		fmt.Scan(&x, &y) // Read the next integers for path 'x' and 'y'
		temp1 := s1 + x // Calculate temporary sum for path 'x'
		temp2 := s2 + y // Calculate temporary sum for path 'y'

		// Check if adding to path 'x' or 'y' is valid
		if math.Abs(float64(temp1-s2)) <= 500 {
			s1 += x // Update sum for path 'x'
			ch[j] = 'A' // Append 'A' to the result slice
			j++ // Increment index for result slice
			continue // Continue to the next iteration
		}
		if math.Abs(float64(temp2-s1)) <= 500 {
			s2 += y // Update sum for path 'y'
			ch[j] = 'G' // Append 'G' to the result slice
			j++ // Increment index for result slice
			continue // Continue to the next iteration
		}
		flag = 1 // Set flag to indicate invalid configuration
		break // Break out of the loop
	}

	// Handle the result based on the flag
	if flag == 1 {
		fmt.Println(-1) // Print -1 if configuration is invalid
	} else {
		ans := string(ch[:j]) // Convert slice to string
		fmt.Println(ans) // Print the result string
	}
}

// <END-OF-CODE>
