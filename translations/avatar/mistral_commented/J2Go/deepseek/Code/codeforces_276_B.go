package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var str string
	mapChar := make(map[rune]int)
	var oddCount int

	// Read the first line of input
	str, _ = reader.ReadString('\n')

	// Iterate through each character in the input string
	for _, ch := range str {
		// If the character is already in the map, increment its count
		if _, ok := mapChar[ch]; ok {
			mapChar[ch]++
		} else {
			// Otherwise, add the character to the map with a count of 1
			mapChar[ch] = 1
		}
	}

	// Iterate through each entry in the map and count odd-valued entries
	for _, count := range mapChar {
		if count%2 != 0 {
			oddCount++ // Increment the odd count
		}
	}

	// Determine the output based on the odd count
	if oddCount <= 1 || oddCount%2 != 0 {
		fmt.Fprintln(writer, "First") // Output "First" if the odd count is 1 or odd
	} else {
		fmt.Fprintln(writer, "Second") // Output "Second" if the odd count is even
	}
}

