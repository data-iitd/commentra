package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input from the user and store it in the variable `n`.
	for i := n; i > 0; i-- { // Iterate from `n` down to 1, decrementing by 1 in each iteration.
		if n%i == 0 { // Check if `n` is divisible by `i`.
			n = i // Update `n` to `i` if `n` is divisible by `i`.
			fmt.Print(i, " ") // Print the value of `i` followed by a space.
		}
	}
}

// <END-OF-CODE>
