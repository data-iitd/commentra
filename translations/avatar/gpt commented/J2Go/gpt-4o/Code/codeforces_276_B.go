package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize input stream to read from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read a line of input from the user
	str, _ := reader.ReadString('\n')

	// Create a map to count occurrences of each character
	charCount := make(map[rune]int)
	oddCount := 0 // Initialize counter for characters with odd occurrences

	// Iterate through each character in the input string
	for _, ch := range str {
		// Update the count of the character in the map
		charCount[ch]++
	}

	// Count how many characters have an odd number of occurrences
	for _, count := range charCount {
		if count%2 != 0 {
			oddCount++
		}
	}

	// Determine the output based on the count of odd occurrences
	if oddCount <= 1 || oddCount%2 != 0 {
		fmt.Println("First") // Output "First" if conditions are met
	} else {
		fmt.Println("Second") // Output "Second" otherwise
	}
}

// <END-OF-CODE>
