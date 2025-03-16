package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Set up input reading methods for efficiency
	reader := bufio.NewReader(os.Stdin)

	// Read input string
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1] // Remove the newline character

	// Check if all characters in the string are the same
	if allSame(s) {
		fmt.Println(0) // If true, print 0 and exit
		return
	}

	// Count the occurrences of each character in the string
	counts := make(map[rune]int)
	for _, char := range s {
		counts[char]++
	}

	// Calculate the answer as twice the minimum frequency of any character
	minCount := len(s)
	for _, count := range counts {
		if count < minCount {
			minCount = count
		}
	}
	ans := minCount * 2

	// Print the final answer
	fmt.Println(ans)
}

// Function to check if all characters in the string are the same
func allSame(s string) bool {
	firstChar := rune(s[0])
	for _, char := range s {
		if char != firstChar {
			return false
		}
	}
	return true
}

// Entry point of the program
// No explicit entry point needed in Go, main function serves that purpose
