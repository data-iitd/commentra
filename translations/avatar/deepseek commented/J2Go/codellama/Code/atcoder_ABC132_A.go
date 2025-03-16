
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	// Read the input string

	targ := []rune(s)
	// Convert the string to a character array

	map := make(map[rune]int)
	// Initialize a map to store character counts

	for i := 0; i < len(targ); i++ {
		// Loop through each character in the character array
		if _, ok := map[targ[i]]; !ok {
			// If the character is not already in the map, add it with a count of 1
			map[targ[i]] = 1
		} else {
			// If the character is already in the map, increment its count
			map[targ[i]]++
		}
	}

	ok := true
	// Initialize a boolean flag to check the conditions

	for c := range map {
		// Loop through each entry in the map
		if map[c] != 2 {
			// If any character count is not 2, set ok to false and break the loop
			ok = false
			break
		}
	}

	if ok && len(map) == 2 {
		// Check if all characters appear exactly twice and there are exactly 2 unique characters
		fmt.Println("Yes")
		// Print "Yes" if the conditions are met
	} else {
		fmt.Println("No")
		// Print "No" otherwise
	}
}

