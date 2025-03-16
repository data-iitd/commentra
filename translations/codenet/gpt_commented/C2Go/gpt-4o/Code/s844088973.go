package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables K and X
	var K, X int

	// Read two integers from standard input: K and X
	fmt.Scanf("%d %d", &K, &X)

	// Loop from (X - K + 1) to (X + K - 1)
	for i := X - K + 1; i <= X + K - 1; i++ {
		// Print the current value of i
		fmt.Print(i)

		// If i is not the last number, print a space after it
		if i < X + K - 1 {
			fmt.Print(" ")
		}
	}

	// Print a newline character after the loop completes
	fmt.Println()
}

// <END-OF-CODE>
