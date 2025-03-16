package main

import (
	"fmt"
	"strconv"
	"strings"
)

// Function to generate a character slice from the concatenation of numbers 1 to 1000
func generateString() []rune {
	var sb strings.Builder // Creating a strings.Builder to efficiently build the string

	// Looping through numbers 1 to 1000 and appending them to the strings.Builder
	for i := 1; i <= 1000; i++ {
		sb.WriteString(strconv.Itoa(i)) // Appending the current number to the strings.Builder
	}

	// Converting the built string to a rune slice and returning it
	return []rune(sb.String())
}

func main() {
	var n int
	fmt.Scan(&n) // Reading an integer input from the user

	// Printing the character at the (n-1)th index of the generated character slice
	fmt.Println(string(generateString()[n-1]))

	// No need to close anything in Go for standard input
}

// <END-OF-CODE>
