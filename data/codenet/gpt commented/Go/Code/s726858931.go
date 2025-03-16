package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Initialize a new scanner to read input from standard input
var sc = bufio.NewScanner(os.Stdin)

func main() {
	// Initialize the scanner with a specific buffer size
	scanInit()

	// Read the input string
	s := nextStr()

	// Start checking for the first missing lowercase letter from 'a'
	c := 'a'

	// Loop through all lowercase letters from 'a' to 'z'
	for j := 0; j < 26; j++ {
		found := false // Flag to check if the current letter is found in the input string
		// Check if the current letter exists in the input string
		for i := 0; i < len(s); i++ {
			if s[i] == byte(c) {
				found = true // Set the flag to true if the letter is found
				break
			}
		}
		// If the letter was not found, print it and exit
		if found == false {
			fmt.Println(string(c))
			return
		}
		c++ // Move to the next letter
	}

	// If all letters from 'a' to 'z' are found, print "None"
	fmt.Println("None")
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
func scanInit() {
	const cap = 1000 * 1024 // Define the buffer capacity
	var buf = make([]byte, cap) // Create a buffer of the specified capacity
	sc.Buffer(buf, cap) // Set the scanner's buffer
	sc.Split(bufio.ScanWords) // Split the input by words
	return
}

// nextInt reads the next integer from the input
func nextInt() int {
	sc.Scan() // Scan the next token
	i, e := strconv.Atoi(sc.Text()) // Convert the scanned text to an integer
	if e != nil {
		panic(e) // Panic if there is an error during conversion
	}
	return i // Return the integer
}

// nextStr reads the next string from the input
func nextStr() string {
	sc.Scan() // Scan the next token
	return sc.Text() // Return the scanned text as a string
}
