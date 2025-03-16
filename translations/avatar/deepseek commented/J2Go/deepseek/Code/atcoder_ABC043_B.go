package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Step 1: Define the input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	
	// Step 2: Read the input string
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	
	// StringBuilder to build the result
	var result strings.Builder
	
	// Iterate over each character in the input string
	for _, char := range input {
		switch char {
		case '0':
			// Append '0' to the result
			result.WriteRune('0')
		case '1':
			// Append '1' to the result
			result.WriteRune('1')
		case 'B':
			// Remove the last character if the result is not empty
			if result.Len() > 0 {
				result.Truncate(result.Len() - 1)
			}
		}
	}
	
	// Print the result
	fmt.Fprintln(writer, result.String())
}

