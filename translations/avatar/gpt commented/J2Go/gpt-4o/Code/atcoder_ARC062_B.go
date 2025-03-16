package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new input reader
	in := bufio.NewReader(os.Stdin)

	// Read the input string S
	S, _ := in.ReadString('\n')
	S = S[:len(S)-1] // Remove the newline character

	// Create an instance of TaskD to solve the problem
	solver := TaskD{}
	solver.solve(S)
}

type TaskD struct{}

func (t *TaskD) solve(S string) {
	score := 0 // Initialize score to zero

	// Iterate through each character in the string S
	for i := 0; i < len(S); i++ {
		// Determine the character for 'my' based on the index (even or odd)
		var my byte
		if i%2 == 0 {
			my = 'g'
		} else {
			my = 'p'
		}

		// Get the character from the input string at the current index
		his := S[i]

		// Compare 'my' and 'his' characters to update the score
		if my != his {
			// Increment score if 'my' is 'p', otherwise decrement
			if my == 'p' {
				score++
			} else {
				score--
			}
		}
	}

	// Output the final score
	fmt.Println(score)
}

// <END-OF-CODE>
