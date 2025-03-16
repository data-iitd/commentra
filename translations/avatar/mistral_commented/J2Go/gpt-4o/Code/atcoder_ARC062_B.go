package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new reader from standard input
	reader := bufio.NewReader(os.Stdin)
	// Read the input string
	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S) // Trim any whitespace or newline characters

	// Create a variable to store the score
	score := 0

	// Iterate through each character in the string
	for i := 0; i < len(S); i++ {
		var my, his rune // Variables to store my move and his move

		// Determine my move based on the index
		if i%2 == 0 {
			my = 'g' // My move is 'g' for even indices
		} else {
			my = 'p' // My move is 'p' for odd indices
		}

		// Read his move from the input string
		his = rune(S[i])

		// Update the score based on the moves
		if my != his {
			if my == 'p' {
				score++ // Increment score if my move is 'p' and his move is different
			} else {
				score-- // Decrement score if my move is 'g' and his move is different
			}
		}
	}

	// Print the score
	fmt.Println(score)
}

// <END-OF-CODE>
