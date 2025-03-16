

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read a line of input from the scanner
	scanner.Scan()
	inputString := scanner.Text()

	// Replace all commas with spaces in the input string
	modifiedString := strings.Replace(inputString, ",", " ", -1)

	// Print the modified string to the console
	fmt.Println(modifiedString)
}

