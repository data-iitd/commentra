package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var inputNumbers string
	var a, b, c, d int
	var sum int
	symbols := [3]rune{'+', '+', '+'}

	// Read input numbers from user
	fmt.Print("Enter four integers separated by spaces: ")
	_, err := fmt.Scanln(&inputNumbers)
	if err != nil {
		fmt.Println("Error reading input:", err)
		os.Exit(1)
	}

	// Split the input string and convert to integers
	numbers := strings.Fields(inputNumbers)
	if len(numbers) < 4 {
		fmt.Println("Please enter exactly four integers.")
		return
	}

	a, _ = strconv.Atoi(numbers[0])
	b, _ = strconv.Atoi(numbers[1])
	c, _ = strconv.Atoi(numbers[2])
	d, _ = strconv.Atoi(numbers[3])

	// Perform arithmetic operations and check for the sum equal to 7
	for i := 0; i < 2; i++ { // outer loop
		for j := 0; j < 2; j++ { // middle loop
			for k := 0; k < 2; k++ { // inner loop
				// Assign symbols based on the position of current number
				if i == 0 {
					sum = a + b
					symbols[0] = '+'
				} else {
					sum = a - b
					symbols[0] = '-'
				}

				if j == 0 {
					sum += c
					symbols[1] = '+'
				} else {
					sum -= c
					symbols[1] = '-'
				}

				if k == 0 {
					sum += d
					symbols[2] = '+'
				} else {
					sum -= d
					symbols[2] = '-'
				}

				// Check if the sum is equal to 7
				if sum == 7 {
					fmt.Printf("%d%c%d%c%d%c%d = 7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)

					// If sum is equal to 7, exit the loop and return
					return
				}
			}
		}
	}

	// If no combination of four numbers results in a sum of 7, return
}
