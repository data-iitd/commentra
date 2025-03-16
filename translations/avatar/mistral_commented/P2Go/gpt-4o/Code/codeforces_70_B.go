package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	// Taking the number of sentences n as input
	var n int
	fmt.Scan(&n)

	// Initializing the answer counter ans and the sum of lengths of sentences sumL
	ans, sumL := 1, 0

	// Reading the input string
	var inputString string
	fmt.Scanln(&inputString)

	// Splitting the input string into sentences based on punctuation marks
	re := regexp.MustCompile(`[.?!]`)
	sentences := re.Split(inputString, -1)

	for _, s := range sentences {
		// Stripping leading and trailing whitespaces from the sentence s
		s = strings.TrimSpace(s)
		// Adding a dot at the end of the sentence if it doesn't already have one
		s += "."

		// Calculating the length L of the sentence s
		L := len(s)

		// Checking if the length of the sentence is greater than the number of sentences n
		if L > n {
			// Printing an error message and exiting the program if the condition is true
			fmt.Println("Impossible")
			return
		}

		// Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
		if sumL+L+(sumL > 0) > n {
			// Incrementing the answer counter ans if the condition is true
			ans++
			// Updating the sum of lengths sumL with the length of the current sentence
			sumL = L
		} else {
			// Updating the sum of lengths sumL with the length of the current sentence and the previous sentence's length if any
			sumL = sumL + L + boolToInt(sumL > 0)
		}
	}

	// Printing the final answer
	fmt.Println(ans)
}

// Helper function to convert a boolean to an integer (1 for true, 0 for false)
func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}
