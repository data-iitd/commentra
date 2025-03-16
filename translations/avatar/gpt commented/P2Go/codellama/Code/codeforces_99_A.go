package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read input from the user
	var l string
	fmt.Scan(&l)

	// Split the input string into two parts using '.' as the delimiter
	l = strings.Split(l, ".")

	// Convert the first part of the input into a list of characters
	s := []string(l[0])

	// Convert the second part of the input into a list of characters
	p := []string(l[1])

	// Extract the first character from the second part and convert it to an integer
	i, _ := strconv.Atoi(p[0])

	// Check if the last character of the first part is '9'
	if s[len(s) - 1] == "9" {
		// If it is '9', print the message "GOTO Vasilisa."
		fmt.Println("GOTO Vasilisa.")
	} else if s[len(s) - 1] != "9" && i < 5 {
		// If both conditions are true, join the list of characters into a string and print it
		s = strings.Join(s, "")
		fmt.Println(s)
	} else {
		// If the last character is not '9' and i is 5 or more
		// Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
		s = strings.Join(s, "")
		i, _ = strconv.Atoi(s)
		s = strconv.Itoa(i + 1)
		// Print the incremented value
		fmt.Println(s)
	}
}

