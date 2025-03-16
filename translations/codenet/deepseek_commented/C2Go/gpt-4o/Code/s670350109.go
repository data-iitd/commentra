package main

import (
	"fmt"
	"strings"
)

func main() {
	var str1, str2 string

	// Read the first string from the user input
	fmt.Scanln(&str1)
	// Read the second string from the user input
	fmt.Scanln(&str2)

	// Check if the lengths of the two strings are not equal
	if len(str1) != len(str2) {
		// Print "NO" if the lengths are not equal
		fmt.Println("NO")
		return
	}

	// Reverse the first string
	temp := reverseString(str1)

	// Check if the reversed string matches the second string
	if temp == str2 {
		// Print "YES" if all characters match
		fmt.Println("YES")
	} else {
		// Print "NO" if not all characters match
		fmt.Println("NO")
	}
}

// Function to reverse a string
func reverseString(s string) string {
	r := []rune(s) // Convert string to rune slice to handle multi-byte characters
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
