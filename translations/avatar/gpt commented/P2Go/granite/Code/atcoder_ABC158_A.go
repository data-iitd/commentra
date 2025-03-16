
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Read input from the standard input (user input)
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	// Store the input string in a variable's'
	s := strings.TrimSpace(input)

	// Check if both 'A' and 'B' are present in the input string
	// If both are found, set result to "Yes", otherwise set it to "No"
	result := "Yes"
	if!strings.Contains(s, "A") ||!strings.Contains(s, "B") {
		result = "No"
	}

	// Print the result indicating whether both 'A' and 'B' were found
	fmt.Println(result)
}
