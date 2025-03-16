package main

import "fmt"

func main() {
	// Declare variables for height and width of the input, and a loop counter
	var height, width, i int

	// Read the height and width from user input
	fmt.Scanf("%d %d", &height, &width)

	// Declare a character array to hold the input strings, with an extra space for the null terminator
	inputStr := make([]byte, width+1)

	// Print the top border of the box, consisting of '#' characters
	for i = 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	// Read each line of input and print it with '#' borders
	for i = 0; i < height; i++ {
		// Read a string from user input
		fmt.Scanf("%s", &inputStr)
		// Print the string with '#' on both sides
		fmt.Printf("#%s#\n", inputStr)
	}

	// Print the bottom border of the box, consisting of '#' characters
	for i = 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	// Return 0 to indicate successful completion of the program
	return 0
}

