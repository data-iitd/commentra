package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Creating a new reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading input array from the console
	inputArray := bufio.NewScanner(reader)
	inputArray.Scan()
	inputStr := inputArray.Text()

	// Splitting the input string into an array of strings
	inputStrings := split(inputStr, " ")

	// Initializing result variable to 0
	result := 0

	// Iterating through each string in the input array
	for _, str := range inputStrings {
		// Incrementing result variable for each non-zero string encountered
		result++

		// Breaking the loop if a zero string is encountered
		if str == "0" {
			break
		}
	}

	// Writing the result to the console
	fmt.Println(result)
}

// Helper function to split a string by a delimiter
func split(s, delimiter string) []string {
	result := []string{}
	for _, part := range s {
		result = append(result, string(part))
	}
	return result
}

