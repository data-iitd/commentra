package main

import (
	"fmt"
	"strings"
)

// isPalindrome checks if a given string is a palindrome
func isPalindrome(s string) bool {
	// Loop through the first half of the string
	for i := 0; i < len(s)/2; i++ {
		// Compare characters from the start and end of the string
		if s[i] == s[len(s)-1-i] {
			continue
		} else {
			return false
		}
	}
	return true
}

func main() {
	var s string
	fmt.Scanln(&s)

	// Check if the entire string is a palindrome and if the first half is also a palindrome
	if isPalindrome(s) && isPalindrome(s[:len(s)/2]) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

