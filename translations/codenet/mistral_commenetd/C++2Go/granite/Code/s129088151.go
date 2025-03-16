

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// main is the entry point for the program
func main() {
	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of input pairs from the standard input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Create a map to store strings as keys and boolean values
	T := make(map[string]bool)

	// Iterate through each input pair
	for i := 0; i < n; i++ {
		// Read the command and the string from the standard input
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		command := parts[0]
		str := parts[1]

		// If the command is 'i', add the string to the map with a value of true
		if command == "i" {
			T[str] = true // Set the value of the string as a key in the map to true
		}
		// If the command is not 'i', check if the string is present in the map and print the result accordingly
		else {
			if _, ok := T[str]; ok { // Check if the string is present in the map
				fmt.Println("yes") // If present, print 'yes'
			} else {
				fmt.Println("no") // If not present, print 'no'
			}
		}
	}
}

