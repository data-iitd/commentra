package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read input string from the user
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')

	// Remove the newline character from the input string
	s = s[:len(s)-1]

	// Check if all characters in the string are the same
	if allSame(s) {
		fmt.Println(0)
		return
	}

	// Count the frequency of each character in the string
	frequency := make(map[rune]int)
	for _, char := range s {
		frequency[char]++
	}

	// Calculate the answer as twice the minimum frequency of any character
	minFreq := int(^uint(0) >> 1) // Initialize to max int
	for _, count := range frequency {
		if count < minFreq {
			minFreq = count
		}
	}
	ans := minFreq * 2

	// Print the answer
	fmt.Println(ans)
}

// Function to check if all characters in the string are the same
func allSame(s string) bool {
	for i := 1; i < len(s); i++ {
		if s[i] != s[0] {
			return false
		}
	}
	return true
}

// <END-OF-CODE>
