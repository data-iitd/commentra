package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	// Read input from the user
	var input string
	fmt.Scanln(&input)

	// Find the index of the decimal point
	dotIndex := strings.Index(input, ".")
	if dotIndex == -1 {
		return // No decimal point found
	}

	// Check if the digit before the decimal point is '9'
	if input[dotIndex-1] == '9' {
		// If it is, print a specific message
		fmt.Println("GOTO Vasilisa.")
	} else if input[dotIndex+1] > '4' { // Check if the digit after the decimal point is greater than 4
		// Create a new string from the integer part and add 1
		integerPart := input[:dotIndex]
		// Print the incremented value
		num := new(big.Int)
		num.SetString(integerPart, 10)
		num.Add(num, big.NewInt(1))
		fmt.Println(num.String())
	} else {
		// If the digit after the decimal point is 4 or less, print the integer part as it is
		fmt.Println(input[:dotIndex])
	}
}

// <END-OF-CODE>
