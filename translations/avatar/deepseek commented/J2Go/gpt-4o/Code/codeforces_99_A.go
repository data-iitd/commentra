package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	// Read input string from the user
	var input string
	fmt.Scanln(&input)

	// Find the index of the dot ('.') in the string
	dotIndex := strings.Index(input, ".")
	if dotIndex == -1 {
		return // No dot found, exit
	}

	// Check if the character before the dot is '9'
	if input[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else {
		// If the character before the dot is not '9', check the digit after the dot
		if input[dotIndex+1] > '4' {
			// Increment the number before the dot by 1 and print the result
			beforeDot := input[:dotIndex]
			num := new(big.Int)
			num.SetString(beforeDot, 10)
			num.Add(num, big.NewInt(1))
			fmt.Println(num.String())
		} else {
			// If the digit after the dot is 4 or less, print the number before the dot without any changes
			fmt.Println(input[:dotIndex])
		}
	}
}

// <END-OF-CODE>
