package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Read two integers from standard input
	var ans string

	// Check if either a or b is 1 and determine the winner based on their values
	if a == 1 || b == 1 {
		if a == 1 && b == 1 {
			ans = "Draw" // If both a and b are 1, it's a draw
		} else if a == 1 {
			ans = "Alice" // If a is 1, Alice wins
		} else {
			ans = "Bob" // If b is 1, Bob wins
		}
	} else {
		// If neither a nor b is 1, determine the winner based on their values
		if a == b {
			ans = "Draw" // If a and b are equal, it's a draw
		} else if a > b {
			ans = "Alice" // If a is greater than b, Alice wins
		} else {
			ans = "Bob" // If b is greater than a, Bob wins
		}
	}

	fmt.Println(ans) // Output the result to standard output
}

