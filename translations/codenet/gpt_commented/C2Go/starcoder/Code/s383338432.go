package main

import "fmt"

func main() {
	// Declare variables for height and width of the input, and a loop counter
	var height, width, i int

	// Read the height and width from user input
	fmt.Scanf("%d %d", &height, &width)

	// Declare a character array to hold the input strings, with an extra space for the null terminator
	var input_str [width + 1]byte

	// Print the top border of the box, consisting of '#' characters
	for i = 0; i < width + 2; i++ {
		fmt.Printf("#")
	}
	fmt.Printf("\n")

	// Read each line of input and print it with '#' borders
	for i = 0; i < height; i++ {
		// Read a string from user input
		fmt.Scanf("%s", &input_str)
		// Print the string with '#' on both sides
		fmt.Printf("#%s#\n", input_str)
	}

	// Print the bottom border of the box, consisting of '#' characters
	for i = 0; i < width + 2; i++ {
		fmt.Printf("#")
	}
	fmt.Printf("\n")
}

