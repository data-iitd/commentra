package main

import (
	"fmt"
)

func main() {
	// Declare variables for height and width of the rectangle to be printed
	var height, width int
	// Read the height and width of the rectangle from the user
	fmt.Scan(&height, &width)

	// Print the top border of the rectangle
	for i := 0; i < width+2; i++ {
		// Print '#' character for each iteration
		fmt.Print("#")
	}
	fmt.Println() // Print newline character after the top border

	// Print the body of the rectangle
	for i := 0; i < height; i++ {
		// Declare a slice to store the input string
		var inputStr string
		// Read a string from the user
		fmt.Scan(&inputStr)
		// Print the top and bottom border of each row with '#' character
		fmt.Printf("#%s#\n", inputStr)
	}

	// Print the bottom border of the rectangle
	for i := 0; i < width+2; i++ {
		// Print '#' character for each iteration
		fmt.Print("#")
	}
	fmt.Println() // Print newline character after the bottom border
}

// <END-OF-CODE>
