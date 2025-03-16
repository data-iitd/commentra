package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare a string variable to hold the input
	var s string
	
	// Create a new reader to read input from the user
	reader := bufio.NewReader(os.Stdin)
	
	// Read input string from the user
	fmt.Fscan(reader, &s)
	
	// Declare variables to store the positions of 'A' and 'Z'
	var a, z int
	
	// Loop through the string to find the first occurrence of 'A'
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
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

