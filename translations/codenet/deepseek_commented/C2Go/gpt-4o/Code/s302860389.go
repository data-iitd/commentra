package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Array to store the input numbers as characters
	var inputNumbers [5]byte
	// Integer variables to store the digits
	var a, b, c, d int
	// Variable to store the intermediate results
	var sum int
	// Array to store the operators
	var symbols [3]byte

	// Read a string of four characters from the input
	_, err := fmt.Scanf("%s", &inputNumbers)
	if err != nil {
		fmt.Println("Error reading input:", err)
		os.Exit(1)
	}

	// Extract each digit from inputNumbers and convert it to an integer
	a, _ = strconv.Atoi(string(inputNumbers[0]))
	b, _ = strconv.Atoi(string(inputNumbers[1]))
	c, _ = strconv.Atoi(string(inputNumbers[2]))
	d, _ = strconv.Atoi(string(inputNumbers[3]))

	// Nested loop structure to explore all combinations of addition and subtraction
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				// Choose the operation based on the value of i
				if i == 0 {
					sum = a + b
					symbols[0] = '+'
				} else {
					sum = a - b
					symbols[0] = '-'
				}

				// Choose the operation based on the value of j
				if j == 0 {
					sum += c
					symbols[1] = '+'
				} else {
					sum -= c
					symbols[1] = '-'
				}

				// Choose the operation based on the value of k
				if k == 0 {
					sum += d
					symbols[2] = '+'
				} else {
					sum -= d
					symbols[2] = '-'
				}

				// Check if the sum equals 7
				if sum == 7 {
					// Print the expression if the sum is 7
					fmt.Printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)
					// Exit the program
					return
				}
			}
		}
	}

	// Return 0 if no combination results in a sum of 7
}
