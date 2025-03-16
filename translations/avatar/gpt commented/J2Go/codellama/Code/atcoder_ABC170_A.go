package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read a line of input, split it into an array of strings based on spaces
	input_array := strings.Split(scanner.Text(), " ")

	// Initialize a counter to keep track of the number of non-zero inputs
	result := 0

	// Iterate through each string in the input array
	for _, str := range input_array {
		// Increment the counter for each input
		result += 1

		// If the input is "0", break out of the loop
		if str == "0" {
			break
		}
	}

	// Print the result, which is the count of non-zero inputs before the first "0"
	fmt.Println(result)
}

