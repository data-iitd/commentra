package main

import "fmt"

func main() {
	// Declare variables for height and width of the rectangle to be printed
	var height, width int
	// Declare a character array to store the input string
	var input_str [width + 1]byte
	// Initialize a counter variable 'i'
	var i int

	// Read the height and width of the rectangle from the user
	fmt.Scanf("%d %d", &height, &width)

	// Print the top border of the rectangle
	for i = 0; i < width+2; i++ {
		// Print '#' character for each iteration
		fmt.Print("#")
	}
	fmt.Println() // Print newline character after the top border

	// Print the body of the rectangle
	for i = 0; i < height; i++ {
		// Read a string from the user
		fmt.Scanf("%s", &input_str)
		// Print the top and bottom border of each row with '#' character
		fmt.Printf("#%s#\n", input_str)
	}

	// Print the bottom border of the rectangle
	for i = 0; i < width+2; i++ {
		// Print '#' character for each iteration
		fmt.Print("#")
	}
	fmt.Println() // Print newline character after the bottom border

	// Return 0 to indicate successful execution of the program
	return 0
}

