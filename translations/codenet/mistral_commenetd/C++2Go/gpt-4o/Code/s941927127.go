package main

import (
	"fmt"
	"sort"
)

func main() {
	var W string // Declare a string variable named W to store the input word

	// Read the input word from the standard input stream
	fmt.Scan(&W)

	// Convert the string W to a slice of runes to sort the characters
	runes := []rune(W)

	// Sort the characters in the slice of runes in ascending order
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	// Loop through the sorted slice of runes
	for i := 0; i < len(runes)-1; i++ {
		// Check if the current character and the next character in the slice are the same
		if runes[i] != runes[i+1] {
			// If they are not the same, print "No" and return from the main function
			fmt.Println("No")
			return
		}
	}

	// If the loop completes without finding any pair of non-identical characters, print "Yes"
	fmt.Println("Yes")
}

// <END-OF-CODE>
