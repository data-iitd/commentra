

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize an array 'c' of size 26 to store the count of each character.
	c := [26]int{}

	// Use a scanner to read strings from the standard input.
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Initialize a string'str' to store the current input string.
		str := scanner.Text()
		// Use a loop to traverse the string'str'.
		for _, ch := range str {
			// Use nested if conditions to check if the current character is a lowercase or uppercase letter.
			if 'a' <= ch && ch <= 'z' {
				// Increment the count of the corresponding character in the 'c' array.
				c[ch-'a']++
			} else if 'A' <= ch && ch <= 'Z' {
				// Increment the count of the corresponding character in the 'c' array.
				c[ch-'A']++
			}
		}
	}
	// Use a loop to print the count of each character and its corresponding character.
	for i, count := range c {
		fmt.Printf("%c : %d\n", 'a'+i, count)
	}
}

