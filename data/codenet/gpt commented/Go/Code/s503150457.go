package main

import (
	"fmt"
	"strings"
)

func main() {
	// Declare three string variables to hold user input
	var s1, s2, s3 string
	
	// Read three strings from standard input
	fmt.Scan(&s1, &s2, &s3)

	// Split each string into a slice of individual characters
	s1s := strings.Split(s1, "")
	s2s := strings.Split(s2, "")
	s3s := strings.Split(s3, "")

	// Convert the first character of each string to uppercase and concatenate them
	result := strings.ToUpper(s1s[0]) + strings.ToUpper(s2s[0]) + strings.ToUpper(s3s[0])
	
	// Print the concatenated result
	fmt.Println(result)
}
