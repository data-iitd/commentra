package main

import (
	"fmt"
)

func main() {
	var N, S int

	// Continuously read input until a non-positive integer is entered
	for {
		fmt.Scan(&N)
		if N <= 0 {
			break
		}

		M := -1   // Maximum value initialized to -1 (less than any possible input)
		m := 1001 // Minimum value initialized to 1001 (greater than any possible input)
		addup := 0 // Variable to accumulate the sum of inputs

		// Loop to read N integers
		for i := 0; i < N; i++ {
			fmt.Scan(&S) // Read the next integer

			addup += S // Add the current integer to the total sum

			// Update the maximum value if the current integer is greater
			if S > M {
				M = S
			}

			// Update the minimum value if the current integer is smaller
			if S < m {
				m = S
			}
		}

		// Calculate the average excluding the maximum and minimum values
		// and print the result
		if N > 2 {
			fmt.Println((addup - M - m) / (N - 2))
		} else {
			fmt.Println(0) // If N <= 2, we cannot calculate the average
		}
	}
}

// <END-OF-CODE>
