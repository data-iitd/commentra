package main

import (
	"fmt"
	"strings"
)

func main() {
	var S, T string
	fmt.Scanln(&S) // Read input string S
	fmt.Scanln(&T) // Read input string T

	A := []string{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"} // Array of all lowercase letters

	res := true // Initialize result as true

	// Loop through each letter in the alphabet
	for _, s := range A {
		sIdx := strings.Index(S, s) // Find the index of the current letter in S
		if sIdx < 0 {
			continue // If the letter is not in S, continue to the next letter
		}

		t := string(T[sIdx]) // Find the corresponding letter in T

		idx := 0 // Initialize index for comparison
		for idx < len(S) {
			if strings.Index(S[idx:], s) >= 0 { // If the letter appears in S from the current index
				if strings.Index(T[idx:], t) < 0 || strings.Index(S[idx:], s) != strings.Index(T[idx:], t) { // Check if the positions match
					res = false // If positions do not match, set res to false
					break // Break out of the loop
				} else {
					idx = strings.Index(S[idx:], s) + 1 // Update index to check the next position
				}
			} else if strings.Index(T[idx:], t) >= 0 { // If the letter appears in T from the current index
				res = false // If positions do not match, set res to false
				break // Break out of the loop
			} else {
				break // If neither letter appears, break out of the loop
			}
		}
		if !res {
			break // If res is false, break out of the outer loop
		}
	}

	if res {
		fmt.Println("Yes") // If res is true, print "Yes"
	} else {
		fmt.Println("No") // If res is false, print "No"
	}
}

// <END-OF-CODE>
