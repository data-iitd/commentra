package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input and parse it as a double
	input, _ := reader.ReadString('\n')
	inputFloat, _ := strconv.ParseFloat(input, 64)

	// Calculate the count of odd numbers based on the input
	countOdd := math.Round(inputFloat / 2)

	// Create a BigDecimal to hold the result of the division
	result := new(big.Float).Quo(big.NewFloat(countOdd), big.NewFloat(inputFloat))

	// Set the scale of the result to 10 decimal places, rounding half up
	result.SetMode(big.ToNearestAway)
	result.SetPrec(10)

	// Print the result to the console
	fmt.Println(result)
}

