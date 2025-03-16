<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
<<<<<<< HEAD
	var height, width int
	var input_str [width + 1]byte
	var i int

	fmt.Scanf("%d %d", &height, &width)

	for i = 0; i < width + 2; i++ {
		fmt.Printf("#")
	}
	fmt.Printf("\n")

	for i = 0; i < height; i++ {
		fmt.Scanf("%s", &input_str)
		fmt.Printf("#%s#\n", input_str)
	}

	for i = 0; i < width + 2; i++ {
		fmt.Printf("#")
	}
	fmt.Printf("\n")
=======
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
		fmt.Printf("#")
	}
	fmt.Printf("\n") // Print newline character after the top border

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
		fmt.Printf("#")
	}
	fmt.Printf("\n") // Print newline character after the bottom border
>>>>>>> 98c87cb78a (data updated)
}

