package main

import (
	"fmt"
	"strings"
)

func main() {
	var str1, str2 string

	// Read the first string from the user
	fmt.Print("Enter first string: ")
	fmt.Scanln(&str1)
	fmt.Println("First string:", str1) // Print the first string for verification

	// Read the second string from the user
	fmt.Print("Enter second string: ")
	fmt.Scanln(&str2)
	fmt.Println("Second string:", str2) // Print the second string for verification

	// Check if the lengths of the two strings are equal
	if len(str1) != len(str2) {
		fmt.Println("NO") // If the lengths are not equal, print "NO" and exit
		return
	}

	// Reverse the first string
	temp := reverseString(str1)

	// Compare the reversed first string with the second string
	if temp == str2 {
		fmt.Println("YES") // If all characters are equal, print "YES"
	} else {
		fmt.Println("NO") // If any character is different, print "NO"
	}
}

// Function to reverse a string
func reverseString(s string) string {
	runes := []rune(s) // Convert string to rune slice to handle multi-byte characters
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i] // Swap characters
	}
	return string(runes) // Convert rune slice back to string
}
