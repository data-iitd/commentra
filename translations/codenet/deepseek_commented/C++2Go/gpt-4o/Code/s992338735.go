package main

import (
	"fmt"
)

func main() {
	var N, S int // Declare variables

	for {
		_, err := fmt.Scan(&N) // Read the number of elements (N)
		if err != nil || N <= 0 {
			break // Exit the loop if input is invalid or N is non-positive
		}

		M := -1 // Initialize maximum
		m := 1001 // Initialize minimum
		addup := 0 // Initialize sum

		for i := 0; i < N; i++ { // Loop through each element
			fmt.Scan(&S) // Read the element
			addup += S // Update sum
			if S > M {
				M = S // Update maximum
			}
			if S < m {
				m = S // Update minimum
			}
		}

		// Calculate the average of the remaining numbers
		if N > 2 {
			fmt.Println((addup - M - m) / (N - 2))
		} else {
			fmt.Println(0) // If N <= 2, output 0 to avoid division by zero
		}
	}
} // End of the main function
// <END-OF-CODE>
