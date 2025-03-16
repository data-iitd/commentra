package main

import (
	"fmt"
	"math"
)

func main() {
	var D, G int
	fmt.Scan(&D, &G) // Reading the number of problems and target score
	PC := make([][2]int, D) // Creating a slice to hold the number of problems and bonus points for each problem

	for i := 0; i < D; i++ {
		fmt.Scan(&PC[i][0], &PC[i][1]) // Reading the number of problems and bonus points for each problem
	}

	ans := math.MaxInt // Initializing the answer to a large number

	// Iterating over all possible combinations of problems using a bitmask approach
	for i := 0; i < (1 << D); i++ {
		score := 0 // Initializing the current score
		problem := 0 // Initializing the number of problems solved

		// Calculating the total score and the number of problems solved for the current combination
		for j := 0; j < D; j++ {
			if (i>>j)&1 == 1 {
				score += 100 * (j + 1) * PC[j][0] + PC[j][1]
				problem += PC[j][0]
			}
		}

		// If the total score is greater than or equal to the target score, skip to the next combination
		if score >= G {
			continue
		}

		// Calculating the remaining score needed to reach or exceed the target score
		left := G - score

		// Checking if the remaining score can be achieved by solving additional problems
		for j := 0; j < D; j++ {
			if (i>>j)&1 == 1 {
				continue
			}
			if left > 100*(j+1)*PC[j][0]+PC[j][1] {
				continue // If the remaining score is not enough, continue to the next problem
			} else {
				tmp := (left + (100 * (j + 1)) - 1) / (100 * (j + 1)) // Calculating the number of problems needed
				ans = min(ans, problem+min(tmp, PC[j][0])) // Updating the minimum number of problems solved
			}
		}
	}

	// Printing the minimum number of problems solved to achieve the target score
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
