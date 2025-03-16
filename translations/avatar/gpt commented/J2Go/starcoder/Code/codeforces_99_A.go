package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from the user and convert it to a character array
	str := []rune(strings.TrimSpace(os.ReadLine()))

	// Initialize variable to store the index of the decimal point
	dotIndex := 0

	// Find the index of the decimal point in the input
	for i := 0; i < len(str); i++ {
		if str[i] == '.' {
			dotIndex = i
			break
		}
	}

	// Check if the digit before the decimal point is '9'
	if str[dotIndex-1] == '9' {
		// If it is, print a specific message
		fmt.Println("GOTO Vasilisa.")
	} else if str[dotIndex+1] > '4' {
		// If it is, create a new string from the integer part and add 1
		_str := ""
		for i := 0; i < dotIndex; i++ {
			_str += string(str[i])
		}
		// Print the incremented value
		fmt.Println(new(big.Int).Add(new(big.Int).SetString(_str, 10), big.NewInt(1)).String())
	} else {
		// Print the integer part as it is
		for i := 0; i < dotIndex; i++ {
			fmt.Print(string(str[i]))
		}
		fmt.Println()
	}
}

