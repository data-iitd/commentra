package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read input from the user
	var input string
	fmt.Scanln(&input)

	// Split the input string into two parts using '.' as the delimiter
	parts := strings.Split(input, ".")

	// Convert the first part of the input into a slice of runes
	s := []rune(parts[0])

	// Convert the second part of the input into a slice of runes
	p := []rune(parts[1])

	// Extract the first character from the second part and convert it to an integer
	i, _ := strconv.Atoi(string(p[0]))

	// Check if the last character of the first part is '9'
	if s[len(s)-1] == '9' {
		// If it is '9', print the message "GOTO Vasilisa."
		fmt.Println("GOTO Vasilisa.")
	} else if s[len(s)-1] != '9' && i < 5 {
		// If both conditions are true, convert the slice of runes into a string and print it
		fmt.Println(string(s))
	} else {
		// If the last character is not '9' and i is 5 or more
		// Convert the slice of runes into a string, convert it to an integer, increment it by 1, and convert it back to a string
		num, _ := strconv.Atoi(string(s))
		num++
		// Print the incremented value
		fmt.Println(num)
	}
}

// <END-OF-CODE>
