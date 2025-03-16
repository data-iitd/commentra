package main

import (
	"fmt"
	"strings"
)

func main() {
	var a string
	fmt.Scanln(&a) // Take an input from the user
	vo := []rune{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'} // Define a slice of vowels

	// Iterate over the input string in reverse order
	for i := len(a) - 1; i >= 0; i-- {
		if a[i] == ' ' || a[i] == '?' { // Check if the current character is a space or a question mark
			continue // Continue to the next iteration
		} else {
			isVowel := false
			for _, v := range vo { // Check if the current character is a vowel
				if a[i] == byte(v) {
					isVowel = true
					break
				}
			}
			if isVowel {
				fmt.Println("YES") // Print "YES" if the character is a vowel
			} else {
				fmt.Println("NO") // Print "NO" if the character is not a vowel
			}
			break // Break the loop after printing the result
		}
	}
}

// <END-OF-CODE>
