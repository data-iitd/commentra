package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare variables
	var n int
	var com, str string

	// Create a new reader for standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of input pairs from the standard input
	fmt.Scan(&n)

	// Create a map to store strings as keys and boolean values
	T := make(map[string]bool)

	// Iterate through each input pair
	for i := 0; i < n; i++ {
		// Read the command and the string from the standard input
		com, _ = reader.ReadString(' ')
		str, _ = reader.ReadString('\n')
		com = strings.TrimSpace(com)
		str = strings.TrimSpace(str)

		// If the command is 'i', add the string to the map with a value of true
		if com == "i" {
			T[str] = true // Set the value of the string as a key in the map to true
		} else {
			// If the command is not 'i', check if the string is present in the map and print the result accordingly
			if _, exists := T[str]; exists { // Check if the string is present in the map
				fmt.Println("yes") // If present, print 'yes'
			} else {
				fmt.Println("no") // If not present, print 'no'
			}
		}
	}
	// Return 0 to indicate successful execution of the program
}

