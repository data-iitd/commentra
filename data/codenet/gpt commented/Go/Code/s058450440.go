package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables to store counts and the result
var (
	a   []int // Slice to hold counts of specific characters
	ans = 0   // Variable to hold the final answer
)

// Depth-first search function to calculate combinations
func dfs(left, i, res int) {
	// If no more characters left to choose, add the result to ans
	if left == 0 {
		ans += res
		return
	}
	// Iterate through the slice starting from index i
	for j := i; j < len(a); j++ {
		// Recursive call to dfs with one less character to choose
		dfs(left-1, j+1, res*a[j])
	}
}

func main() {
	// Initialize input reader
	io := newIo()
	// Read the number of characters
	n := io.nextInt()
	// Map to count occurrences of specific characters
	dic := map[rune]int{}

	// Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
	for range make([]struct{}, n) {
		c := io.nextString()[0] // Read the first character of the string
		switch c {
		case 'M', 'A', 'R', 'C', 'H':
			dic[rune(c)]++ // Increment count for the character if it's one of the specified
		}
	}

	// Populate the slice a with the counts from the dictionary
	for _, v := range dic {
		a = append(a, v)
	}

	// Start the DFS to calculate the product of combinations of 3 characters
	dfs(3, 0, 1)
	// Print the final result
	fmt.Println(ans)
}

// Struct to handle input operations
type io struct {
	reader    *bufio.Reader // Buffered reader for input
	tokens    []string       // Slice to hold split input tokens
	nextToken int            // Index for the next token to read
}

// Function to create a new io instance
func newIo() *io {
	return &io{reader: bufio.NewReader(os.Stdin)} // Initialize the buffered reader
}

// Method to read the next line of input
func (io *io) nextLine() string {
	var buffer []byte
	for {
		line, isPrefix, _ := io.reader.ReadLine() // Read a line from input
		buffer = append(buffer, line...)           // Append the line to the buffer
		if !isPrefix {
			break // Exit if the line is not a prefix
		}
	}
	return string(buffer) // Return the complete line as a string
}

// Method to read the next string token from input
func (io *io) nextString() string {
	// Load more tokens if the current index exceeds the available tokens
	for io.nextToken >= len(io.tokens) {
		line := io.nextLine() // Read the next line
		io.tokens = strings.Fields(line) // Split the line into tokens
		io.nextToken = 0 // Reset the token index
	}
	r := io.tokens[io.nextToken] // Get the next token
	io.nextToken++ // Move to the next token
	return r // Return the token
}

// Method to read the next integer from input
func (io *io) nextInt() int {
	i, _ := strconv.Atoi(io.nextString()) // Convert the next string token to an integer
	return i // Return the integer
}
