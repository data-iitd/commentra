package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a new reader to read input from console
	var sb strings.Builder             // Create a new StringBuilder to store the output string

	a, _ := reader.ReadString('\n') // Read the input string from the console and store it in the 'a' variable

	// Replace all occurrences of ',' in the 'a' string with a single space and store the result in the StringBuilder object
	a = strings.ReplaceAll(a, ",", " ")

	// Print the modified string stored in the StringBuilder object to the console
	fmt.Print(sb.String())
}

