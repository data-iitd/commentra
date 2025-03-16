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
	in := bufio.NewReader(os.Stdin)
	out := os.Stdout

	// Initialize the LightScanner for reading input
	scanner := LightScanner{in}

	// Initialize the output string
	var d strings.Builder

	// Read the input string
	s := scanner.string()

	// Process each character in the input string
	for _, c := range s {
		switch c {
		case '0':
			// Append '0' to the output
			d.WriteByte('0')
		case '1':
			// Append '1' to the output
			d.WriteByte('1')
		case 'B':
			// Handle the 'B' character by removing the last character if possible
			if d.Len() > 0 {
				d.Truncate(d.Len() - 1) // Remove the last character
				d.Reset()              // Adjust the size of the StringBuilder
			}
		}
	}

	// Output the final result
	fmt.Fprintln(out, d.String())
}

// Class to solve the B Unhappy Hacking problem
type BUnhappyHackingABCEdit struct {
}

// Class for reading input efficiently
type LightScanner struct {
	reader *bufio.Reader
}

// Constructor to initialize the BufferedReader
func (scanner *LightScanner) Init(in *bufio.Reader) {
	scanner.reader = in
}

// Method to read the next string token from input
func (scanner *LightScanner) string() string {
	// Read a new line and return it
	return scanner.reader.ReadString('\n')
}

