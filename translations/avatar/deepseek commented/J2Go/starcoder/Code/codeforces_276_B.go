
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the input string from the user
	input, _ := reader.ReadString('\n')

	// Create a map to count the frequency of each character in the input string
	charMap := make(map[rune]int)

	// Initialize a counter for characters with odd frequencies
	oddCount := 0

	// Iterate through the input string to populate the frequency map
	for _, ch := range input {
		if _, ok := charMap[ch]; ok {
			charMap[ch]++
		} else {
			charMap[ch] = 1
		}
	}

	// Iterate through the map to count characters with odd frequencies
	for _, count := range charMap {
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

