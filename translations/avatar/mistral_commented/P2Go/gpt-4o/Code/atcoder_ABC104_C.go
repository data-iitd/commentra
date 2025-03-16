package main

import (
	"fmt"
	"math"
)

func main() {
	// Define input variables
	var D, G int
	fmt.Scan(&D, &G)

	// Initialize slice of problems with their respective capacities
	PC := make([][2]int, D)
	for i := 0; i < D; i++ {
		fmt.Scan(&PC[i][0], &PC[i][1])
	}

	// Initialize variable for the current iteration
	ans := math.MaxInt32

	// Loop through all possible combinations of problems
	for i := 0; i < (1 << D); i++ {
		// Initialize variables for the current combination
		score := 0
		problem := 0

		// Calculate score for the current combination
		for j := 0; j < D; j++ {
			// If problem j is included in the current combination
			if (i>>j)&1 == 1 {
				// Add score for problem j to the total score
				score += 100*(j+1)*PC[j][0] + PC[j][1]
				// Add capacity of problem j to the total problem
				problem += PC[j][0]
			}
		}

		// If score for the current combination is greater than goal G, skip to the next combination
		if score > G {
			continue
		}

		// Calculate remaining capacity to be covered
		left := G - score

		// Loop through all problems and check if they can be included in the solution
		for j := 0; j < D; j++ {
			// If problem j is already included in the current combination, skip it
			if (i>>j)&1 == 1 {
				continue
			}

			// Check if including problem j can cover the remaining capacity
			if left > 100*(j+1)*PC[j][0]+PC[j][1] {
				continue
			} else {
				// Calculate the number of instances of problem j that can be included
				tmp := (left + (100*(j+1) - 1)) / (100 * (j + 1))
				// Update the answer if including more instances of problem j results in a better solution
				ans = min(ans, problem+min(tmp, PC[j][0]))
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
