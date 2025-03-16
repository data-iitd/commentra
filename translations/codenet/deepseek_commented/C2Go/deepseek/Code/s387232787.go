package main

import (
	"fmt"
)

func main() {
	// Array to store the count of each letter (a-z)
	var c [26]int
	
	// Array to store the input string
	var str [1200]rune
	
	// Read input strings until there are no more inputs
	for {
		// Read the input string
		n, _ := fmt.Scan(&str)
		if n == 0 {
			break
		}
		
		// Pointer to traverse the string
		var p *rune = &str[0]
		
		// Traverse each character in the string
		for *p != 0 {
			// Check if the character is a lowercase letter
			if 'a' <= *p && *p <= 'z' {
				// Increment the count for the corresponding letter
				c[*p - 'a']++
			} 
			// Check if the character is an uppercase letter
			else if 'A' <= *p && *p <= 'Z' {
				// Increment the count for the corresponding letter
				c[*p - 'A']++
			}
			p++
		}
	}
	
	// Print the counts for each letter from 'a' to 'z'
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a' + i, c[i]) 
	}
}

