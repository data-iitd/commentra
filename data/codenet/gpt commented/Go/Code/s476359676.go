package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Declare a scanner variable for reading input
var sc *bufio.Scanner

// Function to read the next string from input
func nextStr() string {
	sc.Scan() // Scan the next token
	return sc.Text() // Return the scanned text
}

// Function to read the next integer from input
func nextInt() int {
	sc.Scan() // Scan the next token
	i, e := strconv.Atoi(sc.Text()) // Convert the scanned text to an integer
	if e != nil {
		panic(e) // Panic if there is an error during conversion
	}
	return i // Return the integer value
}

func main() {
	// Initialize the scanner to read from standard input
	sc = bufio.NewScanner(os.Stdin)
	// Set the buffer size for the scanner
	sc.Buffer(make([]byte, 0), 1000000001*3)
	// Split the input by whitespace
	sc.Split(bufio.ScanWords)

	// Read the number of integers to process
	n := nextInt()

	// Initialize variables for the answer and the previous integer
	ans := 0
	aPrev := 0

	// Loop through each integer input
	for i := 0; i < n; i++ {
		a := nextInt() // Read the next integer

		// Check conditions based on the current and previous integers
		switch {
		case a > i || a > aPrev+1: // If the current integer is greater than the index or previous integer + 1
			fmt.Println(-1) // Print -1 and exit if the condition is met
			return
		case a == aPrev+1: // If the current integer is exactly one more than the previous integer
			ans++ // Increment the answer
		default: // For all other cases
			ans += a // Add the current integer to the answer
		}
		aPrev = a // Update the previous integer to the current one
	}

	// Print the final answer
	fmt.Println(ans)
}
