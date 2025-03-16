package main

import (
	"fmt"
)

func main() {
	// Define a constant for infinity (a large number)
	const INF = 100000

	// Create a Scanner object for input
	// Note: Go does not have a built-in Scanner like Java, so we will use fmt.Scan
	var D int
	var G int64
	fmt.Scan(&D, &G)

	// Arrays to store the number of problems and their corresponding scores
	p := make([]int, D) // p[i] = number of problems for the i-th problem set
	c := make([]int, D) // c[i] = additional score for the i-th problem set

	// Read the number of problems and additional scores for each problem set
	for i := 0; i < D; i++ {
		fmt.Scan(&p[i], &c[i])
	}

	// Initialize the minimum number of problems solved to infinity
	min := INF

	// Iterate through all possible combinations of problem sets using bit masking
	for bit := 0; bit < (1 << D); bit++ {
		score := int64(0) // Total score achieved with the current combination
		solveNum := 0 // Total number of problems solved with the current combination

		// Calculate the score and number of problems solved for the current combination
		for i := 0; i < D; i++ {
			if (bit & (1 << i)) != 0 { // Check if the i-th problem set is included
				score += int64(100 * (i + 1) * p[i] + c[i]) // Update score
				solveNum += p[i] // Update number of problems solved
			}
		}

		// If the current score is less than the goal score G
		if score < G {
		loop:
			for i := D - 1; i >= 0; i-- { // Iterate through problem sets in reverse
				if (bit & (1 << i)) == 0 { // Check if the i-th problem set is not included
					// Attempt to solve additional problems from this set
					for j := 0; j < p[i]-1; j++ {
						score += int64(100 * (i + 1)) // Increase score by the value of the problem
						solveNum++ // Increment the number of problems solved
						if score >= G { // If the score meets or exceeds the goal
							break loop // Exit the loop
						}
					}
				}
			}
		}

		// If the score meets or exceeds the goal, update the minimum number of problems solved
		if score >= G {
			if solveNum < min {
				min = solveNum // Update min if a better solution is found
			}
		}
	}

	// Output the minimum number of problems solved to achieve the goal score
	fmt.Println(min)
}
