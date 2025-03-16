
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare a string variable to hold the input
	var s string
	
	// Read input string from the user
	reader := bufio.NewReader(os.Stdin)
	s, _ = reader.ReadString('\n')
	s = strings.TrimSpace(s)
	
	// Declare variables to store the positions of 'A' and 'Z'
	a, z := -1, -1
	
	// Loop through the string to find the first occurrence of 'A'
	for i, char := range s {
		if char == 'A' {
			a = i // Store the index of 'A'
			break // Exit the loop once 'A' is found
		}
	}
	
	// Loop through the string in reverse to find the last occurrence of 'Z'
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'Z' {
			z = i // Store the index of 'Z'
			break // Exit the loop once 'Z' is found
		}
	}
	
	// Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
	fmt.Println(z - a + 1)
}

