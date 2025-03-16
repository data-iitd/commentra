// Package declaration, not a logical block, no comments needed.
package main

// Import statement, not a logical block, no comments needed.
import (
	"fmt"
)

// Function comp checks if x is less than a. If so, it returns 0, otherwise it returns 10.
func comp(x, a int) int {
	// If x is less than a, return 0, otherwise return 10.
	if (x < a) {
		return 0
	}

	// If x is not less than a, return 10.
	return 10
}

// Main function initializes two integer variables x and a, reads their values from the standard input,
// and then prints the result of calling the comp function with these values.
func main() {
	var x, a int
	fmt.Scan(&x, &a)
	fmt.Println(comp(x, a))
}

