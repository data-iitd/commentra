package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables to hold input numbers and intermediate values
	var inputNumbers string // String to store input numbers
	var a, b, c, d int     // Variables to hold the individual numbers
	var sum int            // Variable to hold the calculated sum
	var symbols [3]rune    // Array to store the symbols used in the expression

	// Read a string of numbers from user input
	fmt.Scan(&inputNumbers)

	// Convert each character to an integer and store in respective variables
	a, _ = strconv.Atoi(string(inputNumbers[0]))
	b, _ = strconv.Atoi(string(inputNumbers[1]))
	c, _ = strconv.Atoi(string(inputNumbers[2]))
	d, _ = strconv.Atoi(string(inputNumbers[3]))

	// Iterate through all combinations of addition and subtraction for the four numbers
	for i := 0; i < 2; i++ { // Loop for the first operation (a + b or a - b)
		for j := 0; j < 2; j++ { // Loop for the second operation (result + c or result - c)
			for k := 0; k < 2; k++ { // Loop for the third operation (result + d or result - d)
				// Determine the first operation (addition or subtraction with a and b)
				if i == 0 {
					sum = a + b // Perform addition
					symbols[0] = '+' // Store the symbol used
				} else {
					sum = a - b // Perform subtraction
					symbols[0] = '-' // Store the symbol used
				}

				// Determine the second operation (addition or subtraction with c)
				if j == 0 {
					sum = sum + c // Perform addition
					symbols[1] = '+' // Store the symbol used
				} else {
					sum = sum - c // Perform subtraction
					symbols[1] = '-' // Store the symbol used
				}

				// Determine the third operation (addition or subtraction with d)
				if k == 0 {
					sum = sum + d // Perform addition
					symbols[2] = '+' // Store the symbol used
				} else {
					sum = sum - d // Perform subtraction
					symbols[2] = '-' // Store the symbol used
				}

				// Check if the calculated sum equals 7
				if sum == 7 {
					// Print the expression that results in 7
					fmt.Printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)
					return // Exit the program after finding the first valid expression
				}
			}
		}
	}

	os.Exit(0) // Exit the program
}

// <END-OF-CODE>
