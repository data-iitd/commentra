
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] == s[len(s)-1-i] {
			continue
		} else {
			return false
		}
	}
	return true
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	if isPalindrome(s) && isPalindrome(s[:len(s)/2]) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

