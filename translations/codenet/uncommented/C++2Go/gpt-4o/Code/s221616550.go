package main

import (
	"fmt"
)

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-1-i] {
			return false
		}
	}
	return true
}

func main() {
	var s string
	fmt.Scan(&s)
	if isPalindrome(s) && isPalindrome(s[:len(s)/2]) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
