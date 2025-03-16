package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Get the input string from the user
	var input string
	fmt.Scanln(&input)

	// Split the input string using '.' as delimiter and store the parts in 'parts'
	parts := strings.Split(input, ".")

	// Extract the first and second parts of the list and store them in 's' and 'p' respectively
	s := []rune(parts[0])
	p := []rune(parts[1])

	// Get the last character of the string 's'
	lastChar := s[len(s)-1]

	// Check if the last character of the string 's' is '9'
	if lastChar == '9' {
		// If yes, print the message "GOTO Vasilisa."
		fmt.Println("GOTO Vasilisa.")
	} else if lastChar != '9' && int(p[0]-'0') < 5 {
		// Concatenate all the characters of 's' to form a string
		sStr := string(s)
		// Print the string 's'
		fmt.Println(sStr)
	} else {
		// Concatenate all the characters of 's' to form a string
		sStr := string(s)
		// Increment the last character of the string 's' by 1
		sInt, _ := strconv.Atoi(sStr)
		sInt++
		// Print the updated string 's'
		fmt.Println(sInt)
	}
}

// <END-OF-CODE>
