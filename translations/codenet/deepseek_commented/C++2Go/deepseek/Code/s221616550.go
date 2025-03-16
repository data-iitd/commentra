package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to check if a string is a palindrome
func isPalindrome(s string) bool {
	// Loop through the first half of the string
	for i := 0; i < len(s)/2; i++ {
		// Compare characters from the start and end of the string
		if s[i] == s[len(s)-1-i] {
			continue
		} else {
			// If any characters do not match, return false
			return false
		}
	}
	// If all characters match, return true
	return true
}

func main() {
	// Declare a scanner to read input
	scanner := bufio.NewScanner(os.Stdin)
	// Read the input string from the user
	scanner.Scan()
	s := scanner.Text()
	// Check if the entire string and its first half are palindromes
	if isPalindrome(s) && isPalindrome(s[:len(s)/2]) {
		// Print "Yes" if both conditions are true
		fmt.Println("Yes")
	} else {
		// Print "No" if either condition is false
		fmt.Println("No")
	}
}

