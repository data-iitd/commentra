package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare variables for input and a map to store string entries
	var n int // Number of commands to process
	var com, str string // Variables to hold command and string inputs

	// Create a new reader for standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of commands from input
	fmt.Scan(&n)
	
	// Map to track the presence of strings (true if present)
	T := make(map[string]bool)

	// Loop through each command
	for i := 0; i < n; i++ {
		// Read the command and the associated string
		com, _ = reader.ReadString('\n')
		str, _ = reader.ReadString('\n')
		
		// Trim the newline characters from the input
		com = strings.TrimSpace(com)
		str = strings.TrimSpace(str)
		
		// Check if the command is 'insert' (indicated by the first character being 'i')
		if com[0] == 'i' {
			// Insert the string into the map with a value of true
			T[str] = true
		} else {
			// If the command is not 'insert', check if the string exists in the map
			if T[str] {
				// If the string exists, print "yes"
				fmt.Println("yes")
			} else {
				// If the string does not exist, print "no"
				fmt.Println("no")
			}
		}
	}
}

