package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read a line of input
	line, _ := reader.ReadString('\n')
	// Convert the string to a slice of runes
	runes := []rune(line)
	// Create a map to count occurrences of each character
	charMap := make(map[rune]int)
	oddCount := 0
	// Iterate through each character in the input string
	for _, ch := range runes {
		// Update the count of the character in the map
		if _, ok := charMap[ch]; ok {
			charMap[ch]++
		} else {
			charMap[ch] = 1
		}
	}
	// Count how many characters have an odd number of occurrences
	for _, count := range charMap {
		if count%2!= 0 {
			oddCount++
		}
	}
	// Determine the output based on the count of odd occurrences
	if oddCount <= 1 || oddCount%2!= 0 {
		fmt.Println("First") // Output "First" if conditions are met
	} else {
		fmt.Println("Second") // Output "Second" otherwise
	}
}

