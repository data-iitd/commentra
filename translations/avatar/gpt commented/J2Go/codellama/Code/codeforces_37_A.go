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
	input := FastScanner{
		br: bufio.NewReader(os.Stdin),
		st: strings.Split("", ""),
	}

	// Read the number of integers to be processed
	n, _ := strconv.Atoi(input.next())

	// Initialize a HashMap to store the frequency of each integer
	map := make(map[int]int)

	// Loop through the input integers and populate the frequency map
	for i := 0; i < n; i++ {
		val, _ := strconv.Atoi(input.next())
		// Update the count of the integer in the map
		map[val] = map[val] + 1
	}

	// Initialize a variable to track the maximum frequency found
	max := int(^uint(0) >> 1)

	// Iterate through the entries in the frequency map to find the maximum frequency
	for key, value := range map {
		// Update max if the current frequency is greater than the current max
		if value > max {
			max = value
		}
	}

	// Print the maximum frequency and the number of unique integers
	fmt.Println(max, len(map))
}

// FastScanner class for efficient input reading
type FastScanner struct {
	br *bufio.Reader
	st []string
}

// Method to get the next token from input
func (input *FastScanner) next() string {
	// Read new line if there are no more tokens
	for len(input.st) == 0 {
		line, _ := input.br.ReadString('\n')
		input.st = strings.Split(line, " ")
	}
	return input.st[0]
}

// Method to read the next integer from input
func (input *FastScanner) nextInt() int {
	return int(input.nextInt64())
}

// Method to read the next long from input
func (input *FastScanner) nextInt64() int64 {
	return int64(input.nextInt64())
}

// Method to read the next double from input
func (input *FastScanner) nextDouble() float64 {
	return float64(input.nextDouble())
}

// Method to read the next line from input
func (input *FastScanner) nextLine() string {
	return input.next()
}

