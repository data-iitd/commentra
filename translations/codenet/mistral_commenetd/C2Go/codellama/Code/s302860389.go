
package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Declare variables
	var inputNumbers string = "0000"
	var temp string = "0"
	var a, b, c, d int
	var sum int
	var symbols string = "+++"

	// Read input numbers from user
	fmt.Print("Enter four integers separated by spaces: ")
	fmt.Scan(&inputNumbers)

	// Extract each number from input string and convert to integer
	temp = string(inputNumbers[0])
	a, _ = strconv.Atoi(temp)
	temp = string(inputNumbers[1])
	b, _ = strconv.Atoi(temp)
	temp = string(inputNumbers[2])
	c, _ = strconv.Atoi(temp)
	temp = string(inputNumbers[3])
	d, _ = strconv.Atoi(temp)

	// Perform arithmetic operations and check for the sum equal to 7
	for i := 0; i < 2; i++ { // outer loop
		for j := 0; j < 2; j++ { // middle loop
			for k := 0; k < 2; k++ { // inner loop
				// Assign symbols based on the position of current number
				if i == 0 {
					sum = a + b
					symbols = "+"
				} else {
					sum = a - b
					symbols = "-"
				}

				if j == 0 {
					sum = sum + c
					symbols = symbols + "+"
				} else {
					sum = sum - c
					symbols = symbols + "-"
				}

				if k == 0 {
					sum = sum + d
					symbols = symbols + "+"
				} else {
					sum = sum - d
					symbols = symbols + "-"
				}

				// Check if the sum is equal to 7
				if sum == 7 {
					fmt.Printf("%d%s%d%s%d%s%d = 7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)

					// If sum is equal to 7, exit the loop and return 0
					return
				}
			}
		}
	}

	// If no combination of four numbers results in a sum of 7, return 0
	return
}

