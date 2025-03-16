package main

import (
	"fmt"
	"math/big"
)

func main() {
	var input string // Declare a variable to hold the input string
	fmt.Scanln(&input) // Read a line of input from the console

	dotIndex := -1 // Initialize dotIndex variable to -1

	// Finding the index of the last occurrence of '.' character in the string
	for i, char := range input {
		if char == '.' {
			dotIndex = i
		}
	}

	// Check if the character before the '.' character is '9'
	if dotIndex > 0 && input[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.") // Print the message if the condition is true
	} else if dotIndex < len(input)-1 && input[dotIndex+1] > '4' {
		// Check if the character after the '.' character is a digit greater than 4
		integerPart := input[:dotIndex] // Get the substring before the dot

		// Perform big integer addition and print the result
		num := new(big.Int) // Create a new big integer
		num.SetString(integerPart, 10) // Set the value of the big integer from the string
		num = num.Add(num, big.NewInt(1)) // Add 1 to the big integer
		fmt.Println(num.String()) // Print the result
	} else {
		// Print the substring of the input from the beginning to the index of '.' character
		fmt.Println(input[:dotIndex]) // Print the integer part
	}
}

// <END-OF-CODE>
