package main

import (
	"bufio" // Importing bufio for buffered I/O
	"fmt"   // Importing fmt for formatted I/O
	"os"    // Importing os for standard I/O
	"strings" // Importing strings for string manipulation
)

func main() {
	// Creating a new buffered reader to read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Reading a line of input from the user
	input, _ := reader.ReadString('\n')

	// Replacing commas in the input string with spaces
	output := strings.ReplaceAll(input, ",", " ")

	// Printing the modified string to the console
	fmt.Print(output)
}

// <END-OF-CODE>
