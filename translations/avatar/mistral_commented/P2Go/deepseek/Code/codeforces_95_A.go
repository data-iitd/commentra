package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Initialize variables
	var pya int
	fmt.Scan(&pya) // Get the number of strings to be processed
	arre := []string{} // Initialize an empty list to store the strings
	
	// Process strings input
	for pya > 0 {
		pya-- // Decrement pya by 1
		x, _ := reader.ReadString('\n') // Get the next string as a lowercase string
		x = strings.TrimSpace(x) // Remove any leading or trailing whitespace
		x = strings.ToLower(x) // Convert the string to lowercase
		arre = append(arre, x) // Append the string to the list
	}
	
	// Get the original string and its first letter
	oString, _ := reader.ReadString('\n') // Get the original string
	oString = strings.TrimSpace(oString) // Remove any leading or trailing whitespace
	oString = strings.ToLower(oString) // Convert the original string to lowercase
	letter1, _ := reader.ReadString('\n') // Get the first letter of the original string
	letter1 = strings.TrimSpace(letter1) // Remove any leading or trailing whitespace
	letter1 = strings.ToLower(letter1) // Convert the first letter to lowercase
	
	// Determine the second letter based on the first letter
	letter2 := "a"
	if letter1 != "a" {
		letter2 = "b"
	}
	
	// Initialize a list of valid indices and a set to store the indices of the strings in the original string
	valid := make([]int, len(oString)) // Initialize a list of zeros with the length of the original string
	setcito := make(map[int]bool) // Initialize an empty map
	
	// Find the indices of the strings in the original string
	for _, x := range arre {
		index := strings.Index(oString, x) // Find the index of the string in the original string
		if index >= 0 { // If the original string contains the current string
			for i := index; i < len(oString); i++ { // Iterate through the indices of the string in the original string
				setcito[i] = true // Add the index to the map
			}
		}
	}
	
	// Replace the letters in the original string based on the indices of the strings
	oStringSlice := []rune(oString) // Convert the string to a slice of runes
	for i := range oStringSlice {
		if _, exists := setcito[i]; exists {
			if oStringSlice[i] == rune(letter1[0]) {
				if strings.ToLower(string(oStringSlice[i])) != letter1 {
					oStringSlice[i] = rune(letter2[0])
				} else if strings.ToUpper(string(oStringSlice[i])) == letter1 {
					oStringSlice[i] = rune(strings.ToUpper(letter2)[0])
				}
			} else {
				oStringSlice[i] = rune(letter1[0])
			}
		}
	}
	
	// Print the modified string
	fmt.Println(string(oStringSlice)) // Print each character of the modified string
	fmt.Println("<END-OF-CODE>")