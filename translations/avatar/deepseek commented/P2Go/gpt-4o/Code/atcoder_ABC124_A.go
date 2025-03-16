package main

import (
	"fmt"
)

func main() {
	var a, b int
	// Taking two integer inputs, `a` and `b`, separated by spaces
	fmt.Scan(&a, &b)

	c := 0
	// Initializing a variable `c` to 0

	for i := 0; i < 2; i++ {
		// The loop runs twice
		if a >= b {
			// Checking if `a` is greater than or equal to `b`
			c += a
			// Adding `a` to `c`
			a--
			// Decrementing `a` by 1 if the condition is true
		} else {
			c += b
			// Adding `b` to `c`
			b--
			// Decrementing `b` by 1 if the condition is false
		}
	}

	fmt.Println(c)
	// Printing the value of `c` after the loop completes
}

// <END-OF-CODE>
