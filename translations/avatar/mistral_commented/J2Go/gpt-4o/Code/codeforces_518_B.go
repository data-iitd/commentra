package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s) // Read the first input string
	fmt.Scan(&t) // Read the second input string

	ura := 0 // Counter for unique characters in the first string
	opa := 0 // Counter for opposite characters in the second string

	// Create a map to store the frequency of each character in the second string
	tmap := make(map[rune]int)

	// Read the characters of the second string and store their frequencies in the map
	for _, ch := range t {
		tmap[ch]++
	}

	// Process the first string
	length := len(s)
	for i, ch := range s {
		num, exists := tmap[ch]
		if !exists { // If the character is not in the second string
			continue
		}
		if num == 1 { // If the character appears only once in the second string
			delete(tmap, ch) // Remove it from the map
		} else {
			tmap[ch]-- // Decrement its frequency
		}
		s = s[:i] + "Я" + s[i+1:] // Replace the character in the string with 'Я'
		ura++ // Increment the counter for unique characters
	}

	// Process the reversed version of the first string
	for i, ch := range s {
		rch := reverse(ch) // Get the reverse character of the current character
		num, exists := tmap[rch]
		if !exists { // If the reverse character is not in the second string
			continue
		}
		if num == 1 { // If the reverse character appears only once in the second string
			delete(tmap, rch) // Remove it from the map
		} else {
			tmap[rch]-- // Decrement its frequency
		}
		opa++ // Increment the counter for opposite characters
	}

	// Print the results
	fmt.Println(ura, opa)
}

// Reverse the given character
func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' { // If the character is lowercase
		return ch - 'a' + 'A' // Return its uppercase version
	}
	return ch - 'A' + 'a' // If the character is uppercase, return its lowercase version
}
