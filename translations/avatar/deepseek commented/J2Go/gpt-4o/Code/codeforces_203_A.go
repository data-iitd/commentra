package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Reading the number of test cases (t) and other required values
	x := nextInt(reader) // Target value x
	t := nextInt(reader) // Number of test cases (unused in this code)
	a := nextInt(reader) // Value a
	b := nextInt(reader) // Value b
	da := nextInt(reader) // Difference a (da)
	db := nextInt(reader) // Difference b (db)

	// Flag to determine if a solution is found
	ok := false

	// Nested loop to calculate possible values of first and second
	for i := 0; i < t; i++ {
		first := a - (da * i) // Calculate first value
		for j := 0; j < t; j++ {
			second := b - (db * j) // Calculate second value
			if second+first == x || second == x || first == x || x == 0 {
				// Check if the sum of first and second equals x, or if either value equals x, or if x is zero
				ok = true
				break
			}
		}
		if ok {
			break // Exit the outer loop if a solution is found
		}
	}

	// Print the result based on the flag
	if ok {
		writer.WriteString("YES\n")
	} else {
		writer.WriteString("NO\n")
	}
}

// Function to read the next integer from the input
func nextInt(reader *bufio.Reader) int {
	line, _ := reader.ReadString('\n')
	value, _ := strconv.Atoi(line[:len(line)-1]) // Convert string to int
	return value
}

// Function to read the next token from the input (not used in this case)
func next(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1] // Return the line without the newline character
}

// Note: The next function is not used in this code, but kept for completeness.
