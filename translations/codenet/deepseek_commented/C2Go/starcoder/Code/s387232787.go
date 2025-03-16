<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a map to store the count of each letter (a-z)
	c := make(map[rune]int)

	// Read input strings until there are no more inputs
	for {
		// Read a string
		s, err := os.Readline()
		if err!= nil {
			break
		}

		// Convert the string to lowercase
		s = strings.ToLower(string(s))

		// Traverse each character in the string
		for _, r := range s {
			// Check if the character is a lowercase letter
			if 'a' <= r && r <= 'z' {
				// Increment the count for the corresponding letter
				c[r]++
			}
		}
	}

	// Print the counts for each letter from 'a' to 'z'
	for i := 'a'; i <= 'z'; i++ {
		fmt.Printf("%c : %d\n", i, c[i])
	}
}

