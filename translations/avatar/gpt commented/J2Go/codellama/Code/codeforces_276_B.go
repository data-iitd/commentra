package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize input stream to read from standard input
	inputStreamReader := bufio.NewReader(os.Stdin)
	bufferedReader := bufio.NewReader(inputStreamReader)
	writer := bufio.NewWriter(os.Stdout)

	// Read a line of input from the user
	str, _ := bufferedReader.ReadString('\n')

	// Create a map to count occurrences of each character
	map := make(map[string]int)
	oddCount := 0 // Initialize counter for characters with odd occurrences

	// Iterate through each character in the input string
	for i := 0; i < len(str); i++ {
		ch := string(str[i])
		// Update the count of the character in the map
		if _, ok := map[ch]; ok {
			map[ch] = map[ch] + 1
		} else {
			map[ch] = 1
		}
	}

	// Count how many characters have an odd number of occurrences
	for key, value := range map {
		if value%2 != 0 {
			oddCount++
		}
	}

	// Determine the output based on the count of odd occurrences
	if oddCount <= 1 || oddCount%2 != 0 {
		fmt.Fprintln(writer, "First") // Output "First" if conditions are met
	} else {
		fmt.Fprintln(writer, "Second") // Output "Second" otherwise
	}

	// Flush the output to ensure all data is written
	writer.Flush()
}

