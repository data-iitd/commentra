package main

import (
	"fmt"
)

func main() {
	var K, X int
	// Read two integers, K and X, from the standard input
	fmt.Scan(&K, &X)

	// Loop from X-K+1 to X+K-1
	for i := X - K + 1; i <= X + K - 1; i++ {
		fmt.Print(i)
		// Print a space after each number except the last one
		if i < X+K-1 {
			fmt.Print(" ")
		}
	}
	// Print a newline character to move to the next line
	fmt.Println()
}

// <END-OF-CODE>
