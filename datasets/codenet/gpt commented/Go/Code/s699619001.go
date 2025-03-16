package main

import "fmt"

// Define a struct to represent a problem with its number of questions and bonus points
type problem struct {
	number, bonus int
}

// Function to return the minimum of two integers
func min(a, b int) int {
	if a >= b {
		return b
	}
	return a
}

func main() {
	// Read the number of problems (D) and the target score (G)
	var D, G int
	fmt.Scan(&D, &G)

	// Create a slice to hold the problems
	problems := make([]problem, D)
	
	// Read the number of questions and bonus points for each problem
	for i := range problems {
		fmt.Scan(&problems[i].number)
		fmt.Scan(&problems[i].bonus)
	}
	// Uncomment the following line to debug input values
	// fmt.Println("D", D, "G", G, "problems", problems)

	// Initialize the answer to a large number (infinity equivalent)
	ans := 10000
	
	// Iterate over all possible combinations of problems using bit manipulation
	for bit := 0; bit < (1 << uint(D)); bit++ {
		score := 0        // Initialize the score for the current combination
		solved := 0       // Initialize the count of solved problems
		ok := false       // Flag to check if the current combination meets the target score

		// Calculate the score and number of solved problems for the current combination
		for j := 0; j < D; j++ {
			if bit&(1<<uint(j)) != 0 { // Check if the j-th problem is included
				score += (j+1)*100*problems[j].number + problems[j].bonus
				solved += problems[j].number
			}
		}

		// If the current score is less than the target score (G)
		if score < G {
			var j int
			// Find the rightmost problem that is not yet included
			for j = D - 1; j >= 0; j-- {
				if bit&(1<<uint(j)) == 0 {
					break
				}
			}
			// Attempt to solve additional questions from the rightmost problem
			for k := 0; k < problems[j].number; k++ {
				score += (j + 1) * 100 // Add score for solving one more question
				solved++               // Increment the count of solved problems
				if score >= G {        // Check if the target score is reached
					ok = true
					break
				}
			}
			// If the target score is still not reached, add the bonus points
			if !ok {
				score += problems[j].bonus
				if score >= G {
					ok = true // Check again if the target score is reached
				}
			}
		} else {
			ok = true // If the score is already greater than or equal to G
		}
		
		// If the current combination meets the target score, update the answer
		if ok {
			ans = min(ans, solved) // Update the minimum number of solved problems
		}
	}
	
	// Output the minimum number of problems that need to be solved to reach the target score
	fmt.Println(ans)
}
