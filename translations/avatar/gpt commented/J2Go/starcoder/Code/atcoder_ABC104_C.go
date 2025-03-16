package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for infinity (a large number)
const INF = 100000

func main() {
	// Create a new Scanner to read input from stdin
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of problems D and the goal score G
	D := readInt(sc)
	G := readInt(sc)

	// Arrays to store the number of problems and their corresponding scores
	p := make([]int, D) // p[i] = number of problems for the i-th problem set
	c := make([]int, D) // c[i] = additional score for the i-th problem set

	// Read the number of problems and additional scores for each problem set
	for i := 0; i < D; i++ {
		p[i] = readInt(sc)
		c[i] = readInt(sc)
	}

	// Initialize the minimum number of problems solved to infinity
	min := INF

	// Iterate through all possible combinations of problem sets using bit masking
	for bit := 0; bit < (1 << D); bit++ {
		score := 0 // Total score achieved with the current combination
		solve_num := 0 // Total number of problems solved with the current combination

		// Calculate the score and number of problems solved for the current combination
		for i := 0; i < D; i++ {
			if bit&(1<<i)!= 0 { // Check if the i-th problem set is included
				score += 100*(i+1)*p[i] + c[i] // Update score
				solve_num += p[i] // Update number of problems solved
			}
		}

		// If the current score is less than the goal score G
		if score < G {
			loop: // Label for breaking out of the nested loop
			for i := D - 1; i >= 0; i-- { // Iterate through problem sets in reverse
				if bit&(1<<i) == 0 { // Check if the i-th problem set is not included
					// Attempt to solve additional problems from this set
					for j := 0; j < p[i]-1; j++ {
						score += 100*(i+1) // Increase score by the value of the problem
						solve_num++ // Increment the number of problems solved
						if score >= G { // If the score meets or exceeds the goal
							break loop // Exit the loop
						}
					}
				}
			}
		}

		// If the score meets or exceeds the goal, update the minimum number of problems solved
		if score >= G {
			min = min(min, solve_num) // Update min if a better solution is found
		}
	}

	// Output the minimum number of problems solved to achieve the goal score
	fmt.Println(min)
}

// readInt reads a single integer from stdin
func readInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

