
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Read the input from the standard input stream
	a, b := readInput()

	// Check if 'a' is positive
	if a > 0 {
		// If it is, print the string 'Positive'
		fmt.Println("Positive")
	} else if a <= 0 && b >= 0 {
		// If it is not, check if 'b' is non-negative
		fmt.Println("Zero")
	} else {
		// If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
		if (a + b)%2 == 0 {
			// If it is, print the string 'Negative'
			fmt.Println("Negative")
		} else {
			// Otherwise, print the string 'Positive'
			fmt.Println("Positive")
		}
	}
}

// readInput reads the input from the standard input stream
func readInput() (int, int) {
	// Read the input from the standard input stream
	input := strings.Split(strings.TrimSpace(fmt.Sprint(S())), " ")

	// Convert the input to integers
	a, _ := strconv.Atoi(input[0])
	b, _ := strconv.Atoi(input[1])

	// Return the integers
	return a, b
}

