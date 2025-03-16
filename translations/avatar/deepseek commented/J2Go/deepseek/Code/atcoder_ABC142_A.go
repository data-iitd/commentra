package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	// Remove the newline character from the input
	input = input[:len(input)-1]

	// Convert the input string to a float64
	floatInput, err := strconv.ParseFloat(input, 64)
	if err != nil {
		fmt.Println("Error converting input to float:", err)
		return
	}

	// Calculate the number of odd numbers up to the given input
	countOdd := math.Round(floatInput / 2)

	// Calculate the ratio of odd numbers to the input
	ratio := countOdd / floatInput

	// Print the result with a precision of 10 decimal places
	fmt.Printf("%.10f\n", ratio)
}

