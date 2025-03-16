package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare a string of size 30 to hold user input
	var str string

	// Create a new reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input from the user and store it in the str variable
	str, _ = reader.ReadString('\n')

	// Remove the newline character at the end of the input
	str = str[:len(str)-1]

	// Replace the character at index 5 with a space
	str = str[:5] + " " + str[6:]

	// Replace the character at index 13 with a space
	str = str[:13] + " " + str[14:]

	// Print the modified string to the console
	fmt.Println(str)
}

