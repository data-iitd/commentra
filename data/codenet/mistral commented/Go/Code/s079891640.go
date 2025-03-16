
package main

import (
	"fmt"
	"os"
	"strings"
)

// Declare a variable named 's' of type string
var s string

func main() {
	// Read a string input from the standard input using fmt.Scan()
	fmt.Scan(&s)

	// Initialize a for loop to iterate through each character in the string 's'
	for i := 0; i < len(s); i++ {
		// Check if the character at index 'i+1' in the string 's' contains the character at index 'i'
		if strings.Contains(s[i+1:], string(s[i])) {
			// If the condition is true, print "no" and exit the program
			fmt.Println("no")
			os.Exit(0)
		}
	}

	// If the for loop completes without finding any matching characters, print "yes"
	fmt.Println("yes")
}

