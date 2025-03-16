package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Creating a new reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading input array from the console
	input, _ := reader.ReadString('\n')
	inputArray := strings.Fields(input)

	// Initializing result variable to 0
	result := 0

	// Iterating through each string in the input array
	for _, str := range inputArray {
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

// <END-OF-CODE>
