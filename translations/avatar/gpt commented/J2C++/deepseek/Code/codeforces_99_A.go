package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Read input from the user and convert it to a character array
	var str string
	fmt.Scanln(&str)
	
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
	if str[dotIndex - 1] == '9' {
		// If it is, print a specific message
		fmt.Println("GOTO Vasilisa.")
	} else if str[dotIndex + 1] - '0' > 4 {
		// If it is, create a new string from the integer part and add 1
		_str := str[:dotIndex]
		// Print the incremented value
		result, _ := strconv.Atoi(_str)
		result++
		fmt.Println(result)
	} else {
		// Print the integer part as it is
		fmt.Println(str[:dotIndex])
	}
}
