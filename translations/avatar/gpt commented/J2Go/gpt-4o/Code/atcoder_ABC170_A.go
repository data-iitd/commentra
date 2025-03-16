package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the standard input stream
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input
	input, _ := reader.ReadString('\n')

	// Split the input into an array of strings based on spaces
	inputArray := strings.Fields(input)

	// Initialize a counter to keep track of the number of non-zero inputs
	result := 0

	// Iterate through each string in the input array
	for _, str := range inputArray {
		// Increment the counter for each input
		result++

		// If the input is "0", break out of the loop
		if str == "0" {
			break
		}
	}

	// Print the result, which is the count of non-zero inputs before the first "0"
	fmt.Println(result)
}

// <END-OF-CODE>
