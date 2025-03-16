package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a new Scanner to read input from the standard input stream
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read a line of input, split it into an array of strings based on spaces
	scanner.Scan()
	input_array := scanner.Text()
	
	// Initialize a counter to keep track of the number of non-zero inputs
	result := 0
	
	// Iterate through each character in the input string
	for _, char := range input_array {
		// Increment the counter for each input
		result += 1
		
		// If the input is "0", break out of the loop
		if char == '0' {
			break
		}
	}
	
	// Print the result, which is the count of non-zero inputs before the first "0"
	fmt.Println(result)
}

