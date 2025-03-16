
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables for height and width of the input, and a loop counter
	var height, width int
	var i int

	// Read the height and width from user input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &height, &width)

	// Declare a character array to hold the input strings, with an extra space for the null terminator
	inputStr := make([]byte, width+1)

	// Print the top border of the box, consisting of '#' characters
	for i = 0; i < width+2; i++ {
		fmt.Printf("#")
	}
	fmt.Println()

	// Read each line of input and print it with '#' borders
	for i = 0; i < height; i++ {
		// Read a string from user input
		fmt.Fscanf(reader, "%s\n", inputStr)
		// Print the string with '#' on both sides
		fmt.Printf("#%s#\n", string(inputStr))
	}

	// Print the bottom border of the box, consisting of '#' characters
	for i = 0; i < width+2; i++ {
		fmt.Printf("#")
	}
	fmt.Println()
}

