package main

import (
	"fmt"
)

const INF = 100000 // Defining a constant for infinity

func main() {
	var D int
	var G int64
	fmt.Scan(&D) // Reading the number of problems
	fmt.Scan(&G) // Reading the target score

	p := make([]int, D) // Array to store the number of problems completed
	c := make([]int, D) // Array to store the bonus points for each problem

	// Reading the number of problems completed and the bonus points for each problem
	for i := 0; i < D; i++ {
		fmt.Scan(&p[i], &c[i])
	}

	min := INF // Initializing the minimum number of problems solved to a large value

	// Using bitmask to iterate through all possible combinations of problem completions
	for bit := 0; bit < (1 << D); bit++ {
		score := int64(0) // Initializing the current score
		solveNum := 0     // Initializing the number of problems solved

		// Calculating the total score and the number of problems solved for the current combination
		for i := 0; i < D; i++ {
			if (bit & (1 << i)) != 0 {
				score += 100 * int64(i+1) * int64(p[i]) + int64(c[i])
				solveNum += p[i]
			}
		}

		// If the score is less than the target, try to maximize the score by completing remaining problems
		if score < G {
			for i := D - 1; i >= 0; i-- {
				if (bit & (1 << i)) == 0 {
					for j := 0; j < p[i]-1; j++ {
						score += 100 * int64(i+1)
						solveNum++
						if score >= G {
							break
						}
					}
				}
			}
		}

		// Updating the minimum number of problems solved if the current combination meets or exceeds the target score
		if score >= G {
			if solveNum < min {
				min = solveNum
			}
		}
	}

	// Output the minimum number of problems solved to achieve the target score
	fmt.Println(min)
}
