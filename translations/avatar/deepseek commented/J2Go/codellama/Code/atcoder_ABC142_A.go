
package main

import (
	"bufio"
	"fmt"
	"math"
	"math/big"
	"os"
	"strconv"
)

// Import statements to handle input/output operations and mathematical calculations

func main() {
	// Main method is the entry point of the program
	
	var input float64
	
	// Declaring a variable to store the input
	
	fmt.Print("Enter a number: ")
	
	// Prompting the user to enter a number
	
	fmt.Scan(&input)
	
	// Reading a double value from the input
	
	countOdd := math.Round(input / 2)
	
	// Calculating the number of odd numbers up to the given input
	
	result := new(big.Float).Quo(big.NewFloat(countOdd), big.NewFloat(input))
	
	// Using big.Float to handle precise decimal calculations
	
	result.SetPrec(10)
	
	// Setting the precision to 10
	
	fmt.Println(result)
	
	// Printing the result
	
}

