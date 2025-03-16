package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Declare two string variables, s and t
	var s string

	// Read a string from the standard input and store it in s
	fmt.Scan(&s)

	// Assign the first character of s to t
	t := string(s[0])

	// Append the size of s minus 2 to t
	t += strconv.Itoa(len(s) - 2)

	// Append the last character of s to t
	t += string(s[len(s)-1])

	// Print the modified string t
	fmt.Println(t)
}

// <END-OF-CODE>
