
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Function to check if a given string is a palindrome
func isPalindrome(s string) bool {
	// Iterate through the first half of the string
	for i := 0; i < len(s)/2; i++ {
		// Check if the character at current index is same as its mirror index
		if s[i] == s[len(s)-1-i] {
			// If yes, continue to next character
			continue
		} else {
			// If no, return false as the string is not a palindrome
			return false
		}
	}
	// If we reach here, it means all characters in the first half are same as their mirror index
	// So, the string is a palindrome
	return true
}

func main() {
	// Declare a string variable to store user input
	var s string
	// Take user input and store it in the string variable
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string: ")
	s, _ = reader.ReadString('\n')
	// Remove the newline character from the input string
	s = strings.TrimSpace(s)
	// Check if the given string is a palindrome and its first half is also a palindrome
	if isPalindrome(s) && isPalindrome(s[:len(s)/2]) {
		// If yes, print "Yes"
		fmt.Println("Yes")
	} else {
		// If no, print "No"
		fmt.Println("No")
	}
}

