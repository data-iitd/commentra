package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Read input string from the user
	var str string
	fmt.Scanln(&str)

	// Find the index of the dot ('.') in the string
	dotIndex := 0
	for i := 0; i < len(str); i++ {
		if str[i] == '.' {
			dotIndex = i
			break
		}
	}

	// Check if the character before the dot is '9'
	if str[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else if int(str[dotIndex+1]-'0') > 4 {
		// Increment the number before the dot by 1 and print the result
		result := strconv.Atoi(str[:dotIndex]) + 1
		fmt.Println(result)
	} else {
		// If the digit after the dot is 4 or less, print the number before the dot without any changes
		fmt.Println(str[:dotIndex])
	}
}

