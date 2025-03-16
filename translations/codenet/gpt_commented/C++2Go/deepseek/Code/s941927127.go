package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	// Declare a string variable to hold the input
	var W string
	
	// Read input string from the user
	fmt.Scanln(&W)
	
	// Convert the string to a slice of runes
	runes := []rune(W)
	
	// Sort the runes in ascending order
	sort.Slice(runes, func(i, j int) bool {
		return runes[i] < runes[j]
	})
	
	// Convert the sorted runes back to a string
	W = string(runes)
	
	// Iterate through the sorted string, checking pairs of characters
	for i := 0; i < len(W); i += 2 {
		// Check if the current character is not equal to the next character
		if W[i] != W[i+1] {
			// If they are not equal, print "No" and exit the program
			fmt.Println("No")
			return
		}
	}
	
	// If all pairs are equal, print "Yes"
	fmt.Println("Yes")
}

