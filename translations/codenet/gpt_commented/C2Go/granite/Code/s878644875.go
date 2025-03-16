
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the first string from user input
	scanner.Scan()
	s := scanner.Text()
	
	// Read the second string from user input
	scanner.Scan()
	t := scanner.Text()
	
	// Initialize a counter to keep track of matching characters
	hit := 0
	
	// Loop through the first three characters of both strings
	for i := 0; i < 3; i++ {
		// Check if the characters at the same position in both strings match
		if string(s[i]) == string(t[i]) {
			hit++ // Increment the hit counter if there's a match
		}
	}
	
	// Output the total number of matching characters
	fmt.Println(hit)
}

