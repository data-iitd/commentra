package main

import (
	"fmt"
	"strings"
)

// Declare character arrays to hold two strings and a temporary string for manipulation
var str1, str2, temp string

func main() {
	// Read two strings from user input
	fmt.Scanln(&str1)
	fmt.Scanln(&str2)

	// Get the length of the first string and calculate the last index
	i := len(str1)
	t := i - 1

	// Check if the lengths of the two strings are different
	if len(str1) != len(str2) {
		// If lengths are different, they cannot be anagrams
		fmt.Println("NO")
	} else {
		// Reverse the first string and store it in the temporary array
		temp = ""
		for j := 0; j < i; j++ {
			temp = string(str1[t]) + temp // Prepend characters from the end of str1 to temp
			t--
		}

		// Compare the reversed string with the second string
		if strings.EqualFold(temp, str2) {
			// If all characters match, the strings are anagrams
			fmt.Println("YES")
		} else {
			// If not all characters match, they are not anagrams
			fmt.Println("NO")
		}
	}
}
