_
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new buffered reader to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input
	line, err := reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
		return
	}

	// Split the input line into an array of strings based on spaces
	input_array := strings.Split(line, " ")

	// Initialize a counter to keep track of the number of non-zero inputs
	result := 0

	// Iterate through each string in the input array
	for _, str := range input_array {
		// Increment the counter for each input
		result += 1

		// If the input is "0", break out of the loop
		if "0" == str {
			break
		}
	}

	// Print the result, which is the count of non-zero inputs before the first "0"
	fmt.Println(result)
}

