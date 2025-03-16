
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the first line of input
	str, _ := reader.ReadString('\n')

	// Initialize the map to store character counts
	map := make(map[rune]int)

	// Iterate through each character in the input string
	for _, ch := range str {
		// If the character is already in the map, increment its count
		if _, ok := map[ch]; ok {
			map[ch]++
		} else {
			// Otherwise, add the character to the map with a count of 1
			map[ch] = 1
		}
	}

	// Iterate through each entry in the map and count odd-valued entries
	oddCount := 0
	for _, count := range map {
		if count%2!= 0 {
			oddCount++ // Increment the odd count
		}
	}

	// Determine the output based on the odd count
	if oddCount <= 1 || oddCount%2!= 0 {
		fmt.Println("First") // Output "First" if the odd count is 1 or odd
	} else {
		fmt.Println("Second") // Output "Second" if the odd count is even
	}
}

