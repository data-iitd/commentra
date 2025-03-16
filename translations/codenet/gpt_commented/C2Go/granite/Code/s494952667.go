
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare a string variable to hold the input string
	var str string

	// Create a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read a string from standard input
	if scanner.Scan() {
		str = scanner.Text()
	}

	// Calculate the length of the input string
	len := len(str)

	// Loop through the string in reverse order
	for i := len - 1; i >= 0; i-- {
		// Output each character of the string in reverse
		fmt.Print(string(str[i]))
	}

	// Print a newline character after the reversed string
	fmt.Println()
}

