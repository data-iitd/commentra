package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	input = input[:len(input)-1] // Remove the newline character
	num, err := strconv.ParseFloat(input, 64)
	if err != nil {
		fmt.Println("Error parsing input:", err)
		return
	}

	// Calculate the number of odd numbers in the input
	countOdd := math.Round(num / 2)

	// Create a big.Float object for the result
	result := big.NewFloat(0).SetPrec(64).SetFloat64(float64(countOdd) / num)

	// Set the precision and rounding mode for the result
	result.SetPrec(10)
	result.SetMode(big.ToNearestEven)

	// Print the result
	fmt.Println(result)
}

