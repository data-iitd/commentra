package main

import (
	"fmt"
	"strings"
)

func main() {
	var pya int
	fmt.Scan(&pya) // Read the number of inputs to be taken
	arre := make([]string, 0) // Initialize an empty slice to store the inputs

	// Read pya number of inputs and convert them to lowercase, then append to arre
	for pya > 0 {
		pya-- // Decrement pya by 1 in each iteration
		var inputStr string
		fmt.Scan(&inputStr)
		arre = append(arre, strings.ToLower(inputStr))
	}

	var oString string
	fmt.Scan(&oString) // Read the original string
	lowString := strings.ToLower(oString) // Convert the original string to lowercase

	var letter1 string
	fmt.Scan(&letter1) // Read the first letter
	letter1 = strings.ToLower(string(letter1[0]))
	letter2 := "a"
	if letter1 != "a" {
		letter2 = "a"
	} else {
		letter2 = "b"
	}

	valid := make([]int, len(oString)) // Initialize a slice of zeros with the length of oString
	setcito := make(map[int]struct{}) // Initialize an empty map to store indices

	// Iterate over each string in arre and check if it exists in lowString
	for _, x := range arre {
		if strings.Contains(lowString, x) { // Check if the substring is found
			wat := 0
			for {
				index := strings.Index(lowString[wat:], x) // Find the index of the substring
				if index < 0 {
					break
				}
				for i := index + wat; i < index+wat+len(x); i++ {
					setcito[i] = struct{}{} // Add the indices to the map
				}
				wat += index + 1
			}
		}
	}

	// Convert oString to a slice of runes for easy manipulation
	runes := []rune(oString)

	// Update the characters in oString based on the setcito indices and letter rules
	for i := range runes {
		if _, exists := setcito[i]; exists {
			if lowString[i] != rune(letter1[0]) {
				runes[i] = rune(letter1[0])
			} else {
				runes[i] = rune(letter2[0])
			}
			if runes[i] >= 'A' && runes[i] <= 'Z' {
				runes[i] = rune(strings.ToUpper(string(runes[i]))[0])
			}
		}
	}

	// Print the modified oString
	for _, x := range runes {
		fmt.Print(string(x))
	}
	fmt.Println()
}

// <END-OF-CODE>
