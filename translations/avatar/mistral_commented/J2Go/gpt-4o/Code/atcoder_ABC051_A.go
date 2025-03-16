package main

import (
	"bufio" // Import bufio package for buffered I/O
	"fmt"   // Import fmt package for formatted I/O
	"os"    // Import os package for operating system functionality
	"strings" // Import strings package for string manipulation
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a new buffered reader to read input from console
	fmt.Print("Enter input: ") // Prompt the user for input

	input, _ := reader.ReadString('\n') // Read the input string from the console

	// Replace all occurrences of ',' in the input string with a single space
	output := strings.ReplaceAll(input, ",", " ")

	// Print the modified string to the console
	fmt.Println(output)
}

// <END-OF-CODE>
