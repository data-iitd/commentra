
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	myMove  string
	hisMove string
	score   int
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the string: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")

	// Iterate through each character in the string
	for i := 0; i < len(input); i++ {
		// Determine my move based on the index
		if i%2 == 0 {
			myMove = "g"
		} else {
			myMove = "p"
		}

		// Read his move from the input string
		hisMove = string(input[i])

		// Update the score based on the moves
		if myMove!= hisMove {
			if myMove == "p" {
				score += 1
			} else {
				score -= 1
			}
		}
	}

	// Print the score
	fmt.Println(score)
}

