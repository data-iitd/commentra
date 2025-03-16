
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of test cases 'n' from the standard input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Read the string's' from the standard input and remove any leading or trailing whitespaces
	s := strings.TrimSpace(bufio.NewReader(os.Stdin).Scan())

	// Check if the string's' does not contain '0' character
	if!strings.Contains(s, "0") {
		// If '0' is not present, print the result as the number of test cases minus one
		fmt.Println(n - 1)
	} else {
		// Find the indices of '0' character in the string's'
		indices := strings.IndexAll(s, "0")

		// Check if there is only one '0' character in the string's'
		if len(indices) == 1 {
			// If there is only one '0', print the result as the number of '1's in the string
			fmt.Println(n)
		} else {
			// Initialize the maximum combination score as 0
			maximum := 0

			// Generate all possible combinations of indices of '0' characters using itertools.combinations()
			combs := generateCombinations(indices)

			// Iterate through each combination and calculate the score for that combination
			for _, x := range combs {
				// Calculate the score for the current combination using the given formula
				score := 2 + 2*(abs(indexOf(indices, x[0])-indexOf(indices, x[1]))-1) - (abs(indexOf(x, x[0])-indexOf(x, x[1]))-1)
				// Update the maximum combination score if the current combination score is greater
				if score > maximum {
					maximum = score
				}
			}

			// Print the final result which is the number of '1's in the string plus the maximum combination score
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}

func generateCombinations(indices string) [][]string {
	// Initialize an empty slice to store the combinations
	var combs [][]string

	// Iterate through each index of '0' character in the string 'indices'
	for i := 0; i < len(indices); i++ {
		// Iterate through each index of '0' character after the current index
		for j := i + 1; j < len(indices); j++ {
			// Create a new slice to store the current combination
			var combination []string

			// Append the current indices to the combination
			combination = append(combination, indices[i:j])

			// Append the combination to the list of combinations
			combs = append(combs, combination)
		}
	}

	// Return the list of combinations
	return combs
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func indexOf(s string, ch string) int {
	// Find the index of the character 'ch' in the string's'
	index := strings.Index(s, ch)

	// Return the index of the character 'ch' in the string's'
	return index
}

// Translate the above Python code to Java and end with comment "