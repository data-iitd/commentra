
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a FastScanner object to read input efficiently
	input := NewFastScanner(os.Stdin)

	// Read the number of integers to be processed
	n, _ := strconv.Atoi(input.Scan())

	// Initialize a map to store the frequency of each integer
	map := make(map[int]int)

	// Loop through the input integers and populate the frequency map
	for i := 0; i < n; i++ {
		val, _ := strconv.Atoi(input.Scan())
		// Update the count of the integer in the map
		map[val] += 1
	}

	// Initialize a variable to track the maximum frequency found
	max := -1

	// Iterate through the entries in the frequency map to find the maximum frequency
	for _, value := range map {
		// Update max if the current frequency is greater than the current max
		if value > max {
			max = value
		}
	}

	// Print the maximum frequency and the number of unique integers
	fmt.Println(max, len(map))
}

// FastScanner struct for efficient input reading
type FastScanner struct {
	reader *bufio.Reader
}

// NewFastScanner function to create a new FastScanner object
func NewFastScanner(reader *bufio.Reader) *FastScanner {
	return &FastScanner{reader: reader}
}

// Scan method to get the next token from input
func (f *FastScanner) Scan() string {
	text, _ := f.reader.ReadString('\n')
	return strings.TrimSpace(text)
}

// 