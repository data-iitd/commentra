
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables for iteration, sum, and a flag
	var i int
	var sum int
	var flag bool // Note: 'flag' is declared but not used in this code
	reader := bufio.NewReader(os.Stdin)
	x := make([]byte, 1002) // Array to store input strings

	// Read the first input string
	fmt.Fscanf(reader, "%s", x)

	// Loop to process input until the termination condition is met
	for {
		// Iterate through the characters of the input string
		for i = 0; i < 1002; i++ {
			// Check for the end of the string (null character)
			if x[i] == 0 {
				// Print the sum of the digits in the string
				fmt.Println(sum)
				break // Exit the loop if end of string is reached
			} else {
				// Convert character to integer and add to sum
				sum += int(x[i]) - 0x30 // '0' is represented by 0x30 in ASCII
			}
		}
		
		// Reset sum for the next input
		sum = 0

		// Read the next input string
		fmt.Fscanf(reader, "%s", x)

		// Check for the termination condition
		if x[0] == 0x30 {
			break
		}
	}
}

