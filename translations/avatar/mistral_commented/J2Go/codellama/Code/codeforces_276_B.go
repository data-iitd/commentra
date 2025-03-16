
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize input and output streams
	inputStreamReader := bufio.NewReader(os.Stdin)
	bufferedReader := bufio.NewReader(inputStreamReader)
	writer := bufio.NewWriter(os.Stdout)

	var str string // String to read from input
	var map map[string]int // Map to store character counts
	var oddCount int // Count of odd-valued character counts

	defer func() {
		// Close the input and output streams
		bufferedReader.Reset(nil)
		inputStreamReader.Reset(nil)
		writer.Flush()
	}()

	// Read the first line of input
	str, _ = bufferedReader.ReadString('\n')

	// Initialize the map to store character counts
	map = make(map[string]int)

	// Iterate through each character in the input string
	for _, ch := range str {
		// If the character is already in the map, increment its count
		if _, ok := map[string(ch)]; ok {
			map[string(ch)]++
		} else {
			// Otherwise, add the character to the map with a count of 1
			map[string(ch)] = 1
		}
	}

	// Iterate through each entry in the map and count odd-valued entries
	for ch, count := range map {
		if count % 2 != 0 {
			oddCount++ // Increment the odd count
		}
	}

	// Determine the output based on the odd count
	if oddCount <= 1 || oddCount % 2 != 0 {
		fmt.Fprintln(writer, "First") // Output "First" if the odd count is 1 or odd
	} else {
		fmt.Fprintln(writer, "Second") // Output "Second" if the odd count is even
	}

	// Flush the output buffer to write the output to the console
	writer.Flush()
}

