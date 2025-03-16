
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Declare variables
var n int
var str, com string
var T map[string]bool // A map to store strings as keys and boolean values

func main() {
	// Read the number of input pairs from the standard input
	fmt.Scan(&n)

	// Iterate through each input pair
	for i := 0; i < n; i++ {
		// Read the command and the string from the standard input
		fmt.Scan(&com, &str)

		// If the command is 'i', add the string to the map with a value of true
		if com[0] == 'i' {
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
	// Return 0 to indicate successful execution of the program
	os.Exit(0)
}

