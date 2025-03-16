package main

import (
	"fmt"
	"strconv"
	"strings"
)

// GenerateString returns a string representing numbers from 1 to 1000
func GenerateString() string {
	var sb strings.Builder // Create a strings.Builder object

	// Use a for loop to append numbers from 1 to 1000 to the strings.Builder object
	for i := 1; i <= 1000; i++ {
		sb.WriteString(strconv.Itoa(i)) // Append the current number to the strings.Builder object
	}

	// Return the built string
	return sb.String()
}

func main() {
	var n int
	fmt.Scan(&n) // Read an integer value from the user input

	// Print the character at the specified index of the generated string
	fmt.Println(string(GenerateString()[n-1]))
}

// <END-OF-CODE>
