package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read an integer input which represents the number of strings to be added to the list
	var pya int
	fmt.Scan(&pya)

	// Initialize a slice to store the input strings
	arre := make([]string, 0, pya)

	// Loop to collect 'pya' number of strings from user input
	for pya > 0 {
		pya-- // Decrement the counter
		var inputStr string
		fmt.Scan(&inputStr)
		// Append the lowercase version of the input string to the slice
		arre = append(arre, strings.ToLower(inputStr))
	}

	// Read the original string from user input
	var oString string
	fmt.Scan(&oString)

	// Convert the original string to lowercase for comparison
	lowString := strings.ToLower(oString)

	// Read a letter from user input and convert it to lowercase
	var letter1 string
	fmt.Scan(&letter1)
	letter1 = strings.ToLower(string(letter1[0]))

	// Determine the second letter based on the first letter; if it's 'a', use 'b', otherwise use 'a'
	var letter2 string
	if letter1 != "a" {
		letter2 = "a"
	} else {
		letter2 = "b"
	}

	// Create a slice to track valid indices for replacement
	valid := make([]int, len(oString))

	// Create a set to store unique indices where replacements will occur
	setcito := make(map[int]struct{})

	// Loop through each string in the slice 'arre'
	for _, x := range arre {
		// Check if the current string 'x' is found in the lowercase version of the original string
		wat := 0 // Initialize a variable to track the search position
		for {
			index := strings.Index(lowString[wat:], x)
			if index < 0 {
				break // Exit the loop if no more occurrences are found
			}
			index += wat // Adjust index to the original string
			// Add the indices of the found string to the set for replacement
			for i := index; i < index+len(x); i++ {
				setcito[i] = struct{}{}
			}
			wat = index + 1 // Move the search position forward
		}
	}

	// Convert the original string to a slice of runes for mutable operations
	oStringRunes := []rune(oString)

	// Loop through the indices stored in 'setcito' for replacement
	for i := range setcito {
		// Determine which letter to use for replacement based on the original character
		var letter string
		if strings.ToLower(string(oStringRunes[i])) != letter1 {
			letter = letter1
		} else {
			letter = letter2
		}
		// Replace the character in the original string with the chosen letter, maintaining case
		if oStringRunes[i] >= 'A' && oStringRunes[i] <= 'Z' {
			oStringRunes[i] = rune(strings.ToUpper(letter)[0])
		} else {
			oStringRunes[i] = rune(letter[0])
		}
	}

	// Print the modified string without spaces between characters
	fmt.Print(string(oStringRunes))

	// Print a newline at the end
	fmt.Println()
}

// <END-OF-CODE>
