package main

import (
	"bufio"
	"fmt"
	"os"
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
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	// Stripping the trailing newline character from the input string
	input = strings.TrimRight(input, "\n")

	// Loop to split the input string into sentences based on punctuation marks
	re := regexp.MustCompile("[.?!]")
	for _, s := range re.Split(input, -1) {
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
			sumL = sumL + L + (sumL > 0)
		}
	}

	// Printing the final answer
	fmt.Println(ans)
}

