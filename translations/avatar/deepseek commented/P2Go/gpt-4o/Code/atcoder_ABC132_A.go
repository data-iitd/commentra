package main

import (
	"fmt"
	"strings"
)

func main() {
	var S string
	fmt.Scanln(&S) // Take a string input from the user

	// Create a map to count the frequency of each character
	c := make(map[rune]int)
	for _, char := range S {
		c[char]++
	}

	// Create a set of unique characters
	Sa := make(map[rune]struct{})
	for _, char := range S {
		Sa[char] = struct{}{}
	}

	// Check if the number of unique characters is not equal to 2
	if len(Sa) != 2 {
		fmt.Println("No") // Print "No" and exit if the condition is true
		return
	}

	// Iterate over the set of unique characters and check if the frequency of each character is not equal to 2
	for char := range Sa {
		if c[char] != 2 {
			fmt.Println("No") // Print "No" and exit if the condition is true
			return
		}
	}

	fmt.Println("Yes") // Print "Yes" if all characters have a frequency of 2
}

// <END-OF-CODE>
