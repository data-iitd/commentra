package main

import (
	"fmt"
)

func main() {
	// Infinite loop to continuously process input until a termination condition is met
	for {
		var n, m int
		// Read the values of n and m
		fmt.Scan(&n, &m)
		// Break the loop if n is 0 (termination condition)
		if n == 0 {
			break
		}

		// Arrays to store the presence of numbers and dynamic programming results
		here := make([]int, 100001)
		dp1 := make([]int, 100001)
		dp2 := make([]int, 100001)

		// Flag to check if a zero was encountered in the input
		dpflg := false

		// Read m numbers and mark their presence
		for i := 0; i < m; i++ {
			var a int
			fmt.Scan(&a)
			// If a zero is encountered, set the flag
			if a == 0 {
				dpflg = true
			}
			// Mark the presence of number a
			here[a] = 1
		}

		// Variables to track the maximum lengths of sequences
		maxi1 := 0
		maxi2 := 0

		// Calculate the longest sequence of present numbers without a zero
		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp1[i] = dp1[i-1] + 1 // Increment if present
			}
			if dp1[i] > maxi1 {
				maxi1 = dp1[i] // Update maximum length
			}
		}

		// Calculate the longest sequence of present numbers considering the presence of a zero
		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp2[i] = dp2[i-1] + 1 // Increment if present
			} else {
				dp2[i] = dp1[i-1] + 1 // Reset if zero is encountered
			}
			if dp2[i] > maxi2 {
				maxi2 = dp2[i] // Update maximum length
			}
		}

		// Output the result based on whether a zero was encountered
		if !dpflg {
			fmt.Println(maxi1) // Print the maximum length without zero
		} else {
			fmt.Println(maxi2) // Print the maximum length considering zero
		}
	}
}

// <END-OF-CODE>
