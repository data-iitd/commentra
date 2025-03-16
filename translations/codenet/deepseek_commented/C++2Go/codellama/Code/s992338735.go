package main

import (
	"fmt"
)

var N, S int // Declare global variables

func main() { // Start the main function
	for { // Start the loop
		fmt.Scan(&N) // Read the number of elements (N)
		if N <= 0 {
			break
		}
		M, m, addup, i := -1, 1001, 0, 0 // Initialize variables for maximum, minimum, sum, and index
		for i = 0; i < N; i++ { // Loop through each element and update the maximum, minimum, and sum
			fmt.Scan(&S)
			addup += S
			if S > M {
				M = S
			}
			if S < m {
				m = S
			}
		}
		fmt.Println((addup - M - m) / (N - 2)) // Calculate the average of the remaining numbers
	}
} // End the loop and main function

