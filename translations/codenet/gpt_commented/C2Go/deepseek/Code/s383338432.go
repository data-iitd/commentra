package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare variables for height and width of the input, and a loop counter
	var height, width int

	// Read the height and width from user input
	fmt.Scan(&height, &width)

	// Declare a character array to hold the input strings, with an extra space for the null terminator
	inputStr := make([]byte, width+1)

	// Print the top border of the box, consisting of '#' characters
	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	// Read each line of input and print it with '#' borders
	for i := 0; i < height; i++ {
		// Read a string from user input
		reader := bufio.NewReader(os.Stdin)
		inputStr, _ = reader.ReadBytes('\n')
		// Print the string with '#' on both sides
		fmt.Printf("#%s#\n", inputStr[:len(inputStr)-1])
	}

	// Print the bottom border of the box, consisting of '#' characters
	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

