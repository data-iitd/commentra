package main

import (
	"fmt"
	"strings"
)

func main() {
	var l string
	fmt.Scanln(&l)

	// Split the input string into two parts using '.' as the delimiter
	lParts := strings.Split(l, ".")

	// Convert the first part of the input into a list of characters
	s := []rune(lParts[0])

	// Convert the second part of the input into a list of characters
	p := []rune(lParts[1])

	// Extract the first character from the second part and convert it to an integer
	i := int(p[0] - '0')

	// Check if the last character of the first part is '9'
	if s[len(s)-1] == '9' {
		// If it is '9', print the message "GOTO Vasilisa."
		fmt.Println("GOTO Vasilisa.")
		// Check if the last character is not '9' and the integer i is less than 5
	} else if s[len(s)-1] != '9' && i < 5 {
		// If both conditions are true, join the list of characters into a string and print it
		fmt.Println(string(s))
	} else {
		// If the last character is not '9' and i is 5 or more
		// Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
		sStr := string(s)
		sInt := int(sStr) + 1
		fmt.Println(strconv.Itoa(sInt))
	}
}

