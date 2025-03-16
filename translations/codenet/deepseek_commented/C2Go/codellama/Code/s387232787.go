package main

import "fmt"

func main() {
	// Array to store the count of each letter (a-z)
	c := [26]int{}

	// Array to store the input string
	str := [1200]byte{}

	// Read input strings until there are no more inputs
	for {
		// Pointer to traverse the string
		p := str[:]

		// Traverse each character in the string
		for i := 0; i < len(p); i++ {
			// Check if the character is a lowercase letter
			if 'a' <= p[i] && p[i] <= 'z' {
				// Increment the count for the corresponding letter
				c[p[i]-'a']++
			} else if 'A' <= p[i] && p[i] <= 'Z' {
				// Increment the count for the corresponding letter
				c[p[i]-'A']++
			}
		}

		// Check if the input string is empty
		if len(p) == 0 {
			break
		}
	}

	// Print the counts for each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

