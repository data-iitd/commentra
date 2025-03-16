package main

import (
	"fmt"
	"strings"
)

func main() {
	// Initialize variables
	var pya int
	fmt.Scan(&pya) // Get the number of strings to be processed
	arre := make([]string, 0) // Initialize an empty slice to store the strings

	// Process strings input
	for pya > 0 {
		pya-- // Decrement pya by 1
		var x string
		fmt.Scan(&x) // Get the next string
		arre = append(arre, strings.ToLower(x)) // Append the string to the slice in lowercase
	}

	// Get the original string and its first letter
	var oString string
	fmt.Scan(&oString) // Get the original string
	var letter1 string
	fmt.Scan(&letter1) // Get the first letter of the original string
	letter1 = strings.ToLower(string(letter1[0])) // Convert to lowercase

	// Determine the second letter based on the first letter
	letter2 := "b" // Default to 'b'
	if letter1 != "a" {
		letter2 = "a" // If the first letter is not 'a', set the second letter to 'a'
	}

	// Initialize a slice of valid indices and a set to store the indices of the strings in the original string
	valid := make([]int, len(oString)) // Initialize a slice of zeros with the length of the original string
	setcito := make(map[int]struct{}) // Initialize an empty set using a map

	// Find the indices of the strings in the original string
	for _, x := range arre {
		index := strings.Index(strings.ToLower(oString), x) // Find the index of the current string
		for index >= 0 { // While the string is found
			for i := index; i < len(oString); i++ { // Iterate through the indices of the string in the original string
				setcito[i] = struct{}{} // Add the index to the set
			}
			index = strings.Index(strings.ToLower(oString[index+1:]), x) + index + 1 // Find the next occurrence
		}
	}

	// Replace the letters in the original string based on the indices of the strings
	oStringRunes := []rune(oString) // Convert the string to a slice of runes
	for i := range oStringRunes {
		if _, exists := setcito[i]; exists { // Check if the index is in the set
			var letter string
			if (unicode.IsLower(oStringRunes[i]) && letter1 != "a") || (unicode.IsUpper(oStringRunes[i]) && letter1 == "a") {
				letter = letter1 // Determine the letter to replace based on the first letter and the case of the letter at the index
			} else {
				letter = letter2
			}
			if unicode.IsUpper(oStringRunes[i]) {
				oStringRunes[i] = []rune(strings.ToUpper(letter))[0] // Replace the letter with the determined letter, preserving the case
			} else {
				oStringRunes[i] = []rune(letter)[0]
			}
		}
	}

	// Print the modified string
	fmt.Print(string(oStringRunes)) // Print the modified string
	fmt.Println() // Print a newline after the modified string
}

// <END-OF-CODE>
