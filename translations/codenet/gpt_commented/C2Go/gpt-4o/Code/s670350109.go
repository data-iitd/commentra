package main

import (
	"fmt"
	"strings"
)

func main() {
	var str1, str2 string

	// Read two strings from user input
	fmt.Scanln(&str1)
	fmt.Scanln(&str2)

	// Check if the lengths of the two strings are different
	if len(str1) != len(str2) {
		// If lengths are different, they cannot be anagrams
		fmt.Println("NO")
		return
	}

	// Reverse the first string
	temp := reverseString(str1)

	// Compare the reversed string with the second string
	if temp == str2 {
		// If all characters match, the strings are anagrams
		fmt.Println("YES")
	} else {
		// If not all characters match, they are not anagrams
		fmt.Println("NO")
	}
}

// Function to reverse a string
func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// <END-OF-CODE>
