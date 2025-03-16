

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the input string from the user
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)

	// Create a map to count the frequency of each character in the input string
	charCount := make(map[rune]int)

	// Initialize a counter for characters with odd frequencies
	oddCount := 0

	// Iterate through the input string to populate the frequency map
	for _, ch := range str {
		charCount[ch]++
	}

	// Iterate through the map to count characters with odd frequencies
	for _, count := range charCount {
		if count%2!= 0 {
			oddCount++
		}
	}

	// Determine the winner based on the count of characters with odd frequencies
	if oddCount <= 1 || oddCount%2!= 0 {
		fmt.Fprintln(writer, "First")
	} else {
		fmt.Fprintln(writer, "Second")
	}

	// Flush the output to ensure the result is printed immediately
	writer.Flush()
}

