// Package main is the entry point of the program
package main

import (
	"bufio" // Import bufio package for reading standard input
	"fmt"   // Import fmt package for formatted I/O
	"os"    // Import os package for interacting with the operating system
	"strconv" // Import strconv package for converting strings to other types
)

// Initialize scanner for reading input
var sc = bufio.NewScanner(os.Stdin)

// Function to initialize the scanner
func scanInit() {
	const cap = 1000 * 1024 // Set buffer capacity
	var buf = make([]byte, cap) // Allocate buffer
	sc.Buffer(buf, cap)        // Set buffer and capacity for scanner
	sc.Split(bufio.ScanWords)  // Split input on words
}

// Function to read an integer from standard input
func nextInt() int {
	sc.Scan() // Read next token
	i, e := strconv.Atoi(sc.Text()) // Convert token to integer
	if e != nil { // If error occurred
		panic(e) // Panic with error
	}
	return i // Return integer
}

// Function to read a string from standard input
func nextStr() string {
	sc.Scan() // Read next token
	return sc.Text() // Return token as string
}

// Main function
func main() {
	// Initialize scanner
	scanInit()

	// Read the first string from standard input
	s := nextStr()

	// Initialize variable c with 'a'
	c := 'a'

	// Check all characters from 'a' to 'z' in the string s
	for j := 0; j < 26; j++ {
		// Initialize variable found as false
		found := false

		// Iterate through each character in the string s
		for i := 0; i < len(s); i++ {
			// If current character matches c, set found to true and break the loop
			if s[i] == byte(c) {
				found = true
				break
			}
		}

		// If character c is not found in the string s, print it and return
		if found == false {
			fmt.Println(string(c))
			return
		}

		// Increment variable c
		c++
	}

	// If no character from 'a' to 'z' is found in the string s, print "None"
	fmt.Println("None")
}