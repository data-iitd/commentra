package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	var W string

	// Read the input word from the standard input stream using fmt.Scan
	fmt.Scan(&W)

	// Convert the string to a slice of runes to sort the characters
	runes := []rune(W)
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})

	// Convert the sorted slice of runes back to a string
	W = string(runes)

	// Initialize a string iterator named itr to point to the first character in the sorted string W
	itr := 0

	// Loop through the sorted string W using a for loop, with the loop condition that itr does not point to the end of the string
	for itr < len(W)-1 {
		// Check if the current character and the next character in the string are the same
		if W[itr] != W[itr+1] {
			// If they are not the same, print "No" to the standard output stream and return from the main function
			fmt.Println("No")
			return
		}
		// Move the iterator to the next character
		itr++
	}

	// If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream
	fmt.Println("Yes")
}

