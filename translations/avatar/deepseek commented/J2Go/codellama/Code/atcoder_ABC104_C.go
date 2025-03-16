package main

import (
	"fmt"
	"math"
)

func main() {
	var D int // Number of problems
	var G int // Target score
	fmt.Scan(&D)
	fmt.Scan(&G)
	p := make([]int, D) // Array to store the number of problems completed
	c := make([]int, D) // Array to store the bonus points for each problem

	// Reading the number of problems completed and the bonus points for each problem
	for i := 0; i < D; i++ {
		fmt.Scan(&p[i])
		fmt.Scan(&c[i])
	}

	min := math.MaxInt32 // Initializing the minimum number of problems solved to a large value

	// Using bitmask to iterate through all possible combinations of problem completions
	for bit := 0; bit < (1 << D); bit++ {
		score := 0 // Initializing the current score
		solve_num := 0 // Initializing the number of problems solved

		// Calculating the total score and the number of problems solved for the current combination
		for i := 0; i < D; i++ {
			if (bit & (1 << i)) != 0 {
				score += 100 * (i + 1) * p[i] + c[i]
				solve_num += p[i]
			}
		}

		// If the score is less than the target, try to maximize the score by completing remaining problems
		if score < G {
			for i := D - 1; i >= 0; i-- {
				if (bit & (1 << i)) == 0 {
					for j := 0; j < p[i]-1; j++ {
						score += 100 * (i + 1)
						solve_num++
						if score >= G {
							break
						}
					}
				}
			}
		}

		// Updating the minimum number of problems solved if the current combination meets or exceeds the target score
		if score >= G {
			min = int(math.Min(float64(min), float64(solve_num)))
		}
	}

	// Output the minimum number of problems solved to achieve the target score
	fmt.Println(min)
}

