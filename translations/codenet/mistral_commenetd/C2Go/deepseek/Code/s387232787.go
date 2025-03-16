package main

import (
	"fmt"
)

func main() {
	// Initialize an array 'c' of size 26 to store the count of each character.
	var c [26]int

	// Declare a character array 'str' of size 1200 to store the input string.
	var str [1200]byte

	// Use a loop to read strings from the standard input using fmt.Scanln() until the end of file is reached.
	for {
		n, err := fmt.Scanln(&str[0])
		if n == 0 || err != nil {
			break
		}
		// Initialize a pointer 'p' to traverse the string 'str'.
		for p := 0; p < len(str); p++ {
			// Use nested if conditions to check if the current character is a lowercase or uppercase letter.
			if 'a' <= str[p] && str[p] <= 'z' {
				// Increment the count of the corresponding character in the 'c' array.
				c[str[p] - 'a']++
			} else if 'A' <= str[p] && str[p] <= 'Z' {
				// Increment the count of the corresponding character in the 'c' array.
				c[str[p] - 'A']++
			}
		}
	}
	// Use a loop to print the count of each character and its corresponding character.
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a' + i, c[i])
	}
}

