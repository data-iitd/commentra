
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read two integers from input
	a, b := readInt(), readInt()

	// Check if the first integer 'a' is positive
	if a > 0 {
		fmt.Println("Positive") // Output 'Positive' if 'a' is greater than 0
	} else if a <= 0 && b >= 0 {
		fmt.Println("Zero") // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
	} else {
		// If 'a' is negative and 'b' is also negative
		if (a + b) % 2 == 0 {
			fmt.Println("Negative") // Output 'Negative' if the sum of 'a' and 'b' is even
		} else {
			fmt.Println("Positive") // Output 'Positive' if the sum of 'a' and 'b' is odd
		}
	}
}

// Function to read an integer from standard input
func readInt() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a line from standard input and remove trailing whitespace
func readLine() string {
	var s string
	fmt.Scan(&s)
	return strings.TrimSpace(s)
}

