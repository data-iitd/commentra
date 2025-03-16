package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Creating a Scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Reading a string input and converting it to a byte slice
	input, _ := reader.ReadString('\n')
	n := []byte(input)
	
	// Initializing a boolean variable to track the state of the previous character
	var s bool
	
	// Iterating through each character in the byte slice
	for i := 0; i < len(n); i++ {
		// Checking if the current character is a dot '.'
		if n[i] == '.' {
			// If the previous character was also a dot, print 1 and reset the state
			if s {
				fmt.Print(1)
				s = false // Resetting the state
			} else {
				// If the previous character was not a dot, print 0
				fmt.Print(0)
			}
		} else {
			// If the current character is not a dot
			if s {
				// If the previous character was also not a dot, print 2 and reset the state
				fmt.Print(2)
				s = false // Resetting the state
			} else {
				// If the previous character was a dot, set the state to true
				s = true
			}
		}
	}
	
	// Closing the Scanner object to prevent resource leaks
	// Note: In Go, there is no need to explicitly close a reader as it is garbage collected
}

