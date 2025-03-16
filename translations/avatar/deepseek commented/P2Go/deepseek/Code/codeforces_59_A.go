package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	var txt string
	fmt.Scanln(&txt) // Taking input from the user and storing it in the variable `txt`.

	cu := 0 // Initializing the counter for uppercase letters to zero.
	cl := 0 // Initializing the counter for lowercase letters to zero.

	// Looping through each character in the input text `txt` to count the number of uppercase and lowercase letters.
	for _, z := range txt {
		if unicode.IsLower(z) { // Checking if the current character `z` is lowercase.
			cl++ // Incrementing the counter for lowercase letters if `z` is lowercase.
		} else { // If `z` is not lowercase, it must be uppercase.
			cu++ // Incrementing the counter for uppercase letters.
		}
	}

	// Comparing the counts of uppercase and lowercase letters to decide the case of the output.
	if cu > cl { // If there are more uppercase letters than lowercase letters.
		fmt.Println(strings.ToUpper(txt)) // Convert the entire text to uppercase.
	} else { // If there are more lowercase letters than uppercase letters or equal counts.
		fmt.Println(strings.ToLower(txt)) // Convert the entire text to lowercase.
	}
}
