package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers from the standard input stream
	a, b := readInt(), readInt()

	// Check if 'a' is positive
	if a > 0 {
		// If it is, print the string 'Positive'
		fmt.Println("Positive")
	}

	// If 'a' is not positive, check if 'b' is non-negative
	if a <= 0 && b >= 0 {
		// If it is, print the string 'Zero'
		fmt.Println("Zero")
	}

	// If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
	if (a+b)%2 == 0 {
		// If it is, print the string 'Negative'
		fmt.Println("Negative")
	} else {
		// Otherwise, print the string 'Positive'
		fmt.Println("Positive")
	}
}

// Read an integer from the standard input stream
func readInt() int {
	// Read a line of input from the standard input stream
	input, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	// Convert the line of input into an integer
	integer, _ := strconv.Atoi(strings.TrimSpace(input))

	// Return the integer that was read
	return integer
}

