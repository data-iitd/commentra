
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var i int
	var sum int
	var flag int
	var x [1002]byte

	// Read a string from standard input and store it in 'x' array
	fmt.Println("Enter a string of digits separated by spaces or newline: ")
	fmt.Scanf("%s", &x)

	for {
		// Initialize sum to zero before processing each string
		sum = 0

		// Process each character in the string 'x'
		for i = 0; i < 1002; i++ {
			// Check if current character is end-of-string marker
			if x[i] == 0 {
				// If so, print the sum of digits in the previous string and exit the loop
				fmt.Printf("Sum of digits in previous string: %d\n", sum)
				break
			} else {
				// Otherwise, add the ASCII value of the character to the sum (subtracting 0x30 to convert ASCII to integer)
				sum += int(x[i]) - 0x30
			}
		}

		// Initialize sum to zero for next iteration of the loop
		sum = 0

		// Read next string from standard input
		fmt.Println("Enter a string of digits separated by spaces or newline: ")
		fmt.Scanf("%s", &x)

<<<<<<< HEAD
=======
		// Check if the first character of the input string is '0'
>>>>>>> 98c87cb78a (data updated)
		if x[0] == 0x30 {
			break
		}
	}
}

