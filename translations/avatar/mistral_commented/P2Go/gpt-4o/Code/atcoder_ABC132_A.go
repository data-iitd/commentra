package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take a string as input from the user
	var S string
	fmt.Scanln(&S)

	// Create a map to count the frequency of each character in the string
	c := make(map[rune]int)

	// Count the frequency of each character
	for _, char := range S {
		c[char]++
	}

	// Create a set to hold unique characters
	Sa := make(map[rune]struct{})

	// Populate the set with characters from the string
	for char := range c {
		Sa[char] = struct{}{}
	}

	// Check if the length of the set Sa is equal to 2
	if len(Sa) != 2 {
		// If not, print "No" and exit the program
		fmt.Println("No")
		return
	}

	// Iterate through each character in the set Sa
	for char := range Sa {
		// Check if the frequency of the character is equal to 2
		if c[char] != 2 {
			// If the frequency of any character is not equal to 2, print "No" and exit the program
			fmt.Println("No")
			return
		}
	}

	// If all characters have a frequency of 2, print "Yes"
	fmt.Println("Yes")
}

// <END-OF-CODE>
