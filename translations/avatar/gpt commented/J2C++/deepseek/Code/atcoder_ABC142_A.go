package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
)

func main() {
	// Create a new bufio reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input and parse it as a float64
	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	// Remove the newline character from the input
	input = input[:len(input)-1]

	// Parse the input string to a float64
	floatInput, err := strconv.ParseFloat(input, 64)
	if err != nil {
		fmt.Println("Error parsing input to float:", err)
		return
	}

	// Calculate the count of odd numbers based on the input
	countOdd := math.Round(floatInput / 2)

	// Create a new big.Float to hold the result of the division
	result := big.NewFloat(0).SetPrec(64)
	result.SetMode(big.ToNearestEven)

	// Set the result to the countOdd divided by the input
	result.Quo(big.NewFloat(countOdd), big.NewFloat(floatInput))

	// Set the precision of the result to 10 decimal places
	result.SetPrec(10)

	// Print the result to the console
	fmt.Println(result)
}

