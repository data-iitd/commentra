package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new reader from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read a line from input using the reader
	inputString, _ := reader.ReadString('\n')

	// Replace all commas with spaces in the input string
	modifiedString := strings.ReplaceAll(inputString, ",", " ")

	// Print the modified string to the console
	fmt.Println(modifiedString)
}

