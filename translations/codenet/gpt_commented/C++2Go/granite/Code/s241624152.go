
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to solve the problem (currently empty)
func solve() {

}

func main() {
	// Initialize a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read input values for a and b
	var a, b int
	scanner.Scan()
	a, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ = strconv.Atoi(scanner.Text())

	// Variable to store the result of the game
	var ans string

	// Determine the outcome based on the values of a and b
	if a == 1 || b == 1 {
		// Special case when either a or b is 1
		if a == 1 && b == 1 {
			// Both players have 1, result is a draw
			ans = "Draw"
		} else if a == 1 {
			// Alice has 1, Bob wins
			ans = "Alice"
		} else {
			// Bob has 1, Alice wins
			ans = "Bob"
		}
	} else {
		// General case when both a and b are greater than 1
		if a == b {
			// Both players have equal values, result is a draw
			ans = "Draw"
		} else if a > b {
			// Alice has a greater value, she wins
			ans = "Alice"
		} else {
			// Bob has a greater value, he wins
			ans = "Bob"
		}
	}

	// Output the result of the game
	fmt.Println(ans)
}

