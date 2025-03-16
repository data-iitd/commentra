
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
	inputStreamReader := bufio.NewReader(os.Stdin)
	bufferedReader := bufio.NewReader(inputStreamReader)
	writer := bufio.NewWriter(os.Stdout)

	// Read the input string from the user
	str, _ := bufferedReader.ReadString('\n')

	// Create a map to count the frequency of each character in the input string
	map := make(map[string]int)

	// Initialize a counter for characters with odd frequencies
	oddCount := 0

	// Iterate through the input string to populate the frequency map
	for i := 0; i < len(str); i++ {
		ch := string(str[i])
		if _, ok := map[ch]; ok {
			map[ch]++
		} else {
			map[ch] = 1
		}
	}

	// Iterate through the map to count characters with odd frequencies
	for key, value := range map {
		if value%2 != 0 {
			oddCount++
		}
	}

	// Determine the winner based on the count of characters with odd frequencies
	if oddCount <= 1 || oddCount%2 != 0 {
		fmt.Fprintln(writer, "First")
	} else {
		fmt.Fprintln(writer, "Second")
	}

	// Flush the output to ensure the result is printed immediately
	writer.Flush()
}

// 