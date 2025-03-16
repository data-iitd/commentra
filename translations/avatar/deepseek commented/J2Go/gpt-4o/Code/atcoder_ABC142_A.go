package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	// Main function is the entry point of the program

	reader := bufio.NewReader(os.Stdin)

	// Setting up bufio.Reader to read input from standard input
	inputStr, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println(err)
		return
	}

	// Reading a string value from the input and converting it to float64
	input, err := strconv.ParseFloat(inputStr[:len(inputStr)-1], 64)
	if err != nil {
		fmt.Println(err)
		return
	}

	// Calculating the number of odd numbers up to the given input
	countOdd := int(input / 2)

	// Using big.Float to handle precise decimal calculations
	result := new(big.Float).SetFloat64(float64(countOdd) / input)
	result = result.SetPrec(256) // Set precision for the result
	result = result.SetMode(big.ToNearestEven) // Set rounding mode

	// Printing the result with 10 decimal places
	fmt.Printf("%.10f\n", result)
}

// <END-OF-CODE>
