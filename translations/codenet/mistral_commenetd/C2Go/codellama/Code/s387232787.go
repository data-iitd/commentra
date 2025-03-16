
package main

import (
	"fmt"
)

func main() {
	// Initialize an array 'c' of size 26 to store the count of each character.
	c := [26]int{}

	// Use a loop to read strings from the standard input using fmt.Scanf() until the end of file is reached.
	for {
		var str string
		fmt.Scanf("%s", &str)
		if str == "" {
			break
		}

		// Initialize a pointer 'p' to traverse the string 'str'.
		for _, p := range str {
			// Use nested if conditions to check if the current character is a lowercase or uppercase letter.
			if 'a' <= p && p <= 'z' {
				// Increment the count of the corresponding character in the 'c' array.
				c[p-'a']++
			} else if 'A' <= p && p <= 'Z' {
				// Increment the count of the corresponding character in the 'c' array.
				c[p-'A']++
			}

		}
	}
	// Use a loop to print the count of each character and its corresponding character.
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
	// Return 0 to indicate successful execution of the program.
	return 0
}

