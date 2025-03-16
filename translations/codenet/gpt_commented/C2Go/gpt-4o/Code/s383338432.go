package main

import (
	"fmt"
)

func main() {
	// Declare variables for height and width of the input
	var height, width int

	// Read the height and width from user input
	fmt.Scanf("%d %d", &height, &width)

	// Print the top border of the box, consisting of '#' characters
	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	// Read each line of input and print it with '#' borders
	for i := 0; i < height; i++ {
		var inputStr string
		// Read a string from user input
		fmt.Scanf("%s", &inputStr)
		// Print the string with '#' on both sides
		fmt.Printf("#%s#\n", inputStr)
	}

	// Print the bottom border of the box, consisting of '#' characters
	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

// <END-OF-CODE>
