
package main

import (
	"bufio"
	"fmt"
	"io"
	"math/big"
	"os"
	"strconv"
)

func main() {
	// Read input from standard input
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil && err != io.EOF {
		panic(err)
	}

	// Parse input as a float64
	inputFloat, err := strconv.ParseFloat(input, 64)
	if err != nil {
		panic(err)
	}

	// Calculate the number of odd numbers in the input
	countOdd := math.Round(inputFloat / 2)

	// Create a BigDecimal object for the result
	result := big.NewRat(int64(countOdd), int64(inputFloat))

	// Set the scale and rounding mode for the result
	result.SetScale(10, big.RoundHalfUp)

	// Print the result
	fmt.Println(result)
}

