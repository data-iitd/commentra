package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize input reader
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input
	str, _ := reader.ReadString('\n')

	// Create a map to store character counts
	charCount := make(map[rune]int)

	// Iterate through each character in the input string
	for _, ch := range str {
		charCount[ch]++
	}

	// Count the number of characters with odd counts
	oddCount := 0
	for _, count := range charCount {
		if count%2 != 0 {
			oddCount++
		}
	}

	// Determine the output based on the odd count
	if oddCount <= 1 || oddCount%2 != 0 {
		fmt.Println("First") // Output "First" if the odd count is 1 or odd
	} else {
		fmt.Println("Second") // Output "Second" if the odd count is even
	}
}

// <END-OF-CODE>
