package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer input which represents the number of strings to be added to the list
	var pya int
	fmt.Scan(&pya)

	// Initialize an empty list to store the input strings
	var arre []string

	// Loop to collect 'pya' number of strings from user input
	for i := 0; i < pya; i++ {
		// Read a string from user input
		input, _ := reader.ReadString('\n')
		// Trim the newline character and convert to lowercase
		arre = append(arre, strings.TrimSpace(input).ToLower())
	}

	// Read the original string from user input
	oString, _ := reader.ReadString('\n')
	// Convert the original string to lowercase for comparison
	lowString := strings.ToLower(strings.TrimSpace(oString))

	// Read a letter from user input and convert it to lowercase
	letter1, _ := reader.ReadString('\n')
	// Convert the letter to lowercase
	letter1 = strings.TrimSpace(letter1)

	// Determine the second letter based on the first letter; if it's 'a', use 'b', otherwise use 'a'
	letter2 := "a"
	if letter1 != "a" {
		letter2 = "b"
	}

	// Initialize a map to track valid indices for replacement
	valid := make([]int, len(lowString))
	for i := range valid {
		valid[i] = 0
	}

	// Create a set to store unique indices where replacements will occur
	setcito := make(map[int]bool)

	// Loop through each string in the list 'arre'
	for _, x := range arre {
		// Check if the current string 'x' is found in the lowercase version of the original string
		wat := 0
		for {
			index := strings.Index(lowString[wat:], x)
			if index < 0 {
				break
			}
			// Add the indices of the found string to the set for replacement
			for i := index; i < index+len(x); i++ {
				setcito[i] = true
			}
			wat = index + 1
		}
	}

	// Convert the original string to a slice for mutable operations
	oStringSlice := []rune(strings.TrimSpace(oString))

	// Loop through the indices stored in 'setcito' for replacement
	for i := range setcito {
		// Determine which letter to use for replacement based on the original character
		letter := letter1
		if string(oStringSlice[i]) == strings.ToLower(letter1) {
			letter = letter2
		}
		// Replace the character in the original string with the chosen letter
		if strings.ContainsAny(oString, string(oStringSlice[i])) {
			if strings.ContainsAny(oString, strings.ToUpper(string(oStringSlice[i]))) {
				oStringSlice[i] = rune(strings.ToUpper(letter)[0])
			} else {
				oStringSlice[i] = rune(strings.ToLower(letter)[0])
			}
		}
	}

	// Print the modified string without spaces between characters
	for _, x := range oStringSlice {
		fmt.Print(string(x))
	}
	fmt.Println()
}
