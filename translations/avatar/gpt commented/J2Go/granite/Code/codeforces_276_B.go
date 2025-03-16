
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize input reader and writer
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read a line of input from the user
	input, _ := reader.ReadString('\n')

	// Create a map to count occurrences of each character
	charCount := make(map[string]int)
	oddCount := 0 // Initialize counter for characters with odd occurrences

	// Iterate through each character in the input string
	for _, ch := range strings.TrimSpace(input) {
		char := string(ch)
		// Update the count of the character in the map
		if count, ok := charCount[char]; ok {
			charCount[char] = count + 1
		} else {
			charCount[char] = 1
		}
	}

	// Count how many characters have an odd number of occurrences
	for _, count := range charCount {
		if count%2!= 0 {
			oddCount++
		}
	}

	// Determine the output based on the count of odd occurrences
	if oddCount <= 1 || oddCount%2!= 0 {
		fmt.Fprintln(writer, "First") // Output "First" if conditions are met
	} else {
		fmt.Fprintln(writer, "Second") // Output "Second" otherwise
	}

	// Flush the output to ensure all data is written
	writer.Flush()
}
