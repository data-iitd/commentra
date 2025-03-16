package main

import (
	"fmt"
	"strings"
)

func main() {
	// Reading two lines of input: S and T
	var S, T string
	fmt.Scanln(&S)
	fmt.Scanln(&T)

	// Defining a slice of lowercase letters from 'a' to 'z'
	A := []string{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}

	// Initializing a boolean variable to track the result
	res := true

	// Iterating through each letter in the slice A
	for _, s := range A {
		// Finding the index of the current letter in string S
		sIdx := strings.Index(S, s)

		// If the letter is not found in S, continue to the next letter
		if sIdx < 0 {
			continue
		}

		// Getting the corresponding character from T at the same index
		t := string(T[sIdx])
		idx := 0 // Initializing index for searching

		// Loop to check the correspondence of characters in S and T
		for idx < len(S) {
			// If the current letter s is found in S starting from idx
			if strings.Index(S[idx:], s) >= 0 {
				// Check if the index of s in S matches the index of t in T
				if strings.Index(S[idx:], s) != strings.Index(T[idx:], t) {
					// If they do not match, set res to false and break
					res = false
					break
				} else {
					// If they match, move the index to the next position
					idx += strings.Index(S[idx:], s) + 1
				}
			} else if strings.Index(T[idx:], t) >= 0 {
				// If the character t is found in T but s is not found in S
				res = false
				break
			} else {
				// Break the loop if neither character is found
				break
			}
		}
		// If a mismatch was found, break out of the outer loop
		if !res {
			break
		}
	}

	// Output the result based on the value of res
	if res {
		fmt.Println("Yes") // If res is true, print "Yes"
	} else {
		fmt.Println("No") // If res is false, print "No"
	}
}

// <END-OF-CODE>
