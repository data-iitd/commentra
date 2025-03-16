package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a new reader for standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the input string
	s, _ := reader.ReadString('\n')

	// Remove the newline character from the input string
	s = strings.TrimSpace(s)

	// Check if all characters in the string are the same
	if len(strings.Unique(s)) == 1 {
		// If so, print 0 and exit
		fmt.Println(0)
		return
	}

	// Count the occurrences of each character in the string
	a := make(map[rune]int)
	for _, char := range s {
		a[char]++
	}

	// Calculate the answer
	ans := min(a) * 2

	// Print the answer
	fmt.Println(ans)
}

// Helper function to find the minimum value in a map
func min(a map[rune]int) int {
	minVal := int(^uint(0) >> 1) // Max int value
	for _, value := range a {
		if value < minVal {
			minVal = value
		}
	}
	return minVal
}
